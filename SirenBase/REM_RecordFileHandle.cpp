#include "REM_RecordFileHandle.h"

REM_RecordFileHandle::REM_RecordFileHandle()	{
	this->pData_fileHeader = NULL;
	this->is_open = false;
}

REM_RecordFileHandle::~REM_RecordFileHandle()	{
	FlushPages();
}

t_rc REM_RecordFileHandle::ReadRecord(const REM_RecordID &rid, REM_RecordHandle &rh)	{
                                                                                        // If file is open.  
	if (!this->is_open) { return REM_FHCLOSED; }
	t_rc rc;

                                                                                        // Get pageID and slot number. 
	int page_id, slot;
	
	rc = rid.GetPageID( page_id);
	if (rc != OK) { return rc; }
	
	rc = rid.GetSlot(slot);
	if (rc != OK) { return rc; }
	
                                                                                        // We create a stromPageHandle to handle the record with specify pageID and slot number. 
	STORM_PageHandle page_handle;
	
	rc = this->sfh.GetPage( page_id, page_handle);
	if (rc != OK) { return rc; }
	
                                                                                        // If it doesn't have data allocate the needed space. 
	if (rh.pData == NULL) {
		rh.pData = (char*) malloc(this->rem_file_header.record_size);
	}
	else {
		delete rh.pData;
		rh.pData = (char*) malloc(this->rem_file_header.record_size);
	}
	
	char *pData;
	REM_PageHeader pageHeader;                                                      // We create a page header to store info about the records
	
	page_handle.GetDataPtr(&pData);
	
                                                                                        // Check slot number
	memcpy(&pageHeader, pData, REM_PAGEHEADER_SIZE);	
	if (slot > pageHeader.n_records) { return REM_INVALIDRID; }
                                                                                        //correct slot 
                                                                                        // Find the record and copy the data to the record handler.
	memcpy(rh.pData, &pData[REM_PAGEHEADER_SIZE+((slot-1)*this->rem_file_header.record_size)], this->rem_file_header.record_size);
	
                                                                                        // Add the recordID to the record handler. 
	rh.rid = rid;
	
                                                                                        // Make Record Handler valid. 
	rh.is_valid = true;
	
	return (OK);
}

t_rc REM_RecordFileHandle::InsertRecord(const char *pData, REM_RecordID &rid)	{
                                                                                         // If file is open.  
	if (!this->is_open) { return REM_FHCLOSED; }
	t_rc rc;
	
                                                                                        // Find an empty page to write the new record. 
	STORM_PageHandle target_page;
	REM_PageHeader page_header = {0};                                               // We store 0 ,we haven't any record yet.
	char *page_data;
	
                                                                                        //If there is no free space on this page we reserve a new page. 
	if (this->rem_file_header.is_last_page_full) {
		
		rc = sfh.ReservePage(target_page);                                      // Reserve the new page.
		if (rc != OK) { return rc; }
		
                                                                                        // We mark the last page as not full. 
		this->rem_file_header.is_last_page_full = false;
		
                                                                                        // Update file header and mark it as dirty. 
		memcpy(this->pData_fileHeader, &this->rem_file_header, REM_FILEHEADER_SIZE);

		rc = this->sfh.MarkPageDirty(this->page_num_file_header);
		if (rc != OK) { return rc; }
		
                                                                                         // Get a pointer to the data of the new page to write data. 	
		rc = target_page.GetDataPtr(&page_data);
		if (rc != OK) { return rc; }
				
	}
                                                                                	// If we have free space in a page, we just get the page. 
	else {
		rc = this->sfh.GetLastPage(target_page);
		if (rc != OK) { return rc; }
		
                                                                                        // Get a pointer to the data of the the page to read the REM Page Header. 
		rc = target_page.GetDataPtr(&page_data);
		if (rc != OK) { return rc; }
		
		memcpy(&page_header, page_data, REM_PAGEHEADER_SIZE);
                
		
	}
	
                                                                                        //We calculate the corect offset(page header size + the offset) of each record there and we place the data 

	memcpy(&page_data[REM_PAGEHEADER_SIZE+(page_header.n_records*this->rem_file_header.record_size)], pData, this->rem_file_header.record_size);
	page_header.n_records+=1;
        this->rem_file_header.n_records+=1;
        memcpy(this->pData_fileHeader, &this->rem_file_header, REM_FILEHEADER_SIZE);
        rc = this->sfh.MarkPageDirty(this->page_num_file_header);
		if (rc != OK) { return rc; }
                                                                                        // Increase the number of records in the page header. This number is also the slot number of the record. 
	int slot_num = page_header.n_records; 
                                                                                	// Declare page number we are currently working on. 
	int page_num;
	rc = target_page.GetPageID(page_num);
	if (rc != OK) { return rc; }
	
                                                                                        //If page is full. 
	if (page_header.n_records == this->rem_file_header.records_per_page) {
		this->rem_file_header.is_last_page_full = true;
		
                                                                                        // Update the file header and mark as dirty. 
		memcpy(this->pData_fileHeader, &this->rem_file_header, REM_FILEHEADER_SIZE);
		
		rc = this->sfh.MarkPageDirty(this->page_num_file_header);
		if (rc != OK) { return rc; }
		
                                                                                        // Get a pointer to the data of the new page to write the new data. 	
		rc = target_page.GetDataPtr(&page_data);
		if (rc != OK) { return rc; }		
	}
	
                                                                                        // Write the new REM Page Header. 
	memcpy(page_data, &page_header, REM_PAGEHEADER_SIZE);
	
	
                                                                                        // Mark the page as dirty because we modified it 
	rc = this->sfh.MarkPageDirty(page_num);
	if (rc != OK) { return rc; }
	
	this->sfh.FlushPage(page_num);                                                  // We are flushing pages
	
                                                                                        // Unpin the page 
	rc = this->sfh.UnpinPage (page_num);
	if (rc != OK) { return rc; }
	
                                                                                        // Set the passed RID's page and slot number 
	rc = rid.SetPageID(page_num);
	if (rc != OK) { return rc; }
	rc = rid.SetSlot(slot_num);
	if (rc != OK) { return rc; }

		
	return (OK);
}

t_rc REM_RecordFileHandle::DeleteRecord(const REM_RecordID &rid)	{
                                                                                        // If file is open.  
	if (!this->is_open) { return REM_FHCLOSED; }
	t_rc rc;
	
                                                                                        // Read page and slot we want to delete. 
	int page_id, slot;
	
	rc = rid.GetPageID(page_id);
	if (rc != OK) { return rc; }
	
	rc = rid.GetSlot(slot);
	if (rc != OK) { return rc; }
	
                                                                                	// Get the page. 
	STORM_PageHandle wanted_page_handle;
	rc = this->sfh.GetPage(page_id, wanted_page_handle);
	if (rc != OK) { return rc; }
	
                                                                                	// Get wanted page header. 
	char *wantedData;
	REM_PageHeader wanted_page_header;
	
	rc = wanted_page_handle.GetDataPtr(&wantedData);
	if (rc != OK) { return rc; }
	
	memcpy(&wanted_page_header, wantedData, REM_PAGEHEADER_SIZE);
	if (slot > wanted_page_header.n_records) { return REM_INVALIDRID; }
	
	STORM_PageHandle last_page_handle;
	int last_page_id;
	
	rc = this->sfh.GetLastPage(last_page_handle);
	if (rc != OK) { return rc; }
	
	rc = last_page_handle.GetPageID(last_page_id);
	if (rc != OK) { return rc; }
	
                                                                                	// Determine if we need to retrieve an other page to replace the record. 
	if (last_page_id == page_id){
		
                                                                                        // Determine if our record is the last one
		if (wanted_page_header.n_records == slot) {
			
                                                                                        // Check if we need to release the page. 
			if (wanted_page_header.n_records == 1) {
				rc = this->sfh.ReleasePage(page_id);
				if (rc != OK) { return rc; }
				
                                                                                	// We change the lastPageID in REM File Header
				this->rem_file_header.is_last_page_full = true;
                                                                                	// Copy new file header /
				memcpy(this->pData_fileHeader, &this->rem_file_header, REM_FILEHEADER_SIZE);
				/* Mark REM File Header frame as dirty */
				rc = this->sfh.MarkPageDirty(this->page_num_file_header);
				if (rc != OK) { return rc; }				
			}
			else {
                                                                                        // If our record is the last one in the row but more data exist, we just decrease the number of records of the page
				wanted_page_header.n_records--;
				
                                                                                        // Copy header back to save changes
				memcpy(wantedData, &wanted_page_header, REM_PAGEHEADER_SIZE);				
			}			
		}
		else {
                                                                                        // Copy the last record of this page (last page) in the position of the record we want to delete. */
			memcpy(&wantedData[REM_PAGEHEADER_SIZE+((slot-1)*this->rem_file_header.record_size)], 
				   &wantedData[REM_PAGEHEADER_SIZE+((wanted_page_header.n_records-1)*this->rem_file_header.record_size)], 
				   this->rem_file_header.record_size);			
			
                                                                                        // Decrease the number of records the pages has. 
			wanted_page_header.n_records--;

                                                                                        // Copy header back to save changes
			memcpy(wantedData, &wanted_page_header, REM_PAGEHEADER_SIZE);
		}
	}
	else {
                                                                                        // Get last record from last page to replace the record. 
		char *lastData;
		
		rc = last_page_handle.GetDataPtr(&lastData);
		if (rc != OK) { return rc; }
		
                                                                                        // Get last page header. 
		REM_PageHeader lastPageHeader;
		
		memcpy(&lastPageHeader, lastData, REM_PAGEHEADER_SIZE);		
		
                                                                                        // Copy data between the two pages 
		memcpy(&wantedData[REM_PAGEHEADER_SIZE+((slot-1)*this->rem_file_header.record_size)], 
			   &lastData[REM_PAGEHEADER_SIZE+((lastPageHeader.n_records-1)*this->rem_file_header.record_size)], 
			   this->rem_file_header.record_size);
		
                                                                                        // If last page has no more records
		if (lastPageHeader.n_records == 1) {
                                                                                        // If we copied the last record we can  release the page
			rc = this->sfh.ReleasePage(last_page_id);
			if (rc != OK) { return rc; }
                                
                                                                                        // We change the lastPageID in REM File Header to save the changes
			this->rem_file_header.is_last_page_full = true;
                                                                                        // Copy new file header 
			memcpy(this->pData_fileHeader, &this->rem_file_header, REM_FILEHEADER_SIZE);
                                                                                        // Mark REM File Header as dirty to flush it
			rc = this->sfh.MarkPageDirty(this->page_num_file_header);
			if (rc != OK) { return rc; }
		}
		else {
                                                                                         //Decrease last page record number in its page header		
			lastPageHeader.n_records--;
			
			memcpy(lastData, &lastPageHeader, REM_PAGEHEADER_SIZE);
			
                                                                                        // Mark last page as dirty 			
			rc = sfh.MarkPageDirty(last_page_id);
			if (rc != OK) { return rc; }
			
                                                                                        // Unpin last page.
			rc = sfh.UnpinPage (last_page_id);
			if (rc != OK) { return rc; }
		}
	}

	
                                                                                        // Mark the page as dirty because we modified it 
	rc = sfh.MarkPageDirty(page_id);
	if (rc != OK) { return rc; }
                                                                                        // Unpin page 
	rc = sfh.UnpinPage (page_id);
	if (rc != OK) { return rc; }
	
	sfh.FlushPage(page_id);
	
	
	return (OK);
}

t_rc REM_RecordFileHandle::UpdateRecord(const REM_RecordHandle &rh)	{
                                                                                        //If file is open. 
	if (!this->is_open) { return REM_FHCLOSED; }
	t_rc rc;
	
                                                                                        // get pageID and slot numbers.
	REM_RecordID rid;
	int page_id, slot;
	
	rc = rh.GetRecordID(rid);
	if (rc != OK) { return rc; }
	
	rc = rid.GetPageID( page_id);
	if (rc != OK) { return rc; }
	rc = rid.GetSlot(slot);
	if (rc != OK) { return rc; }
	
                                                                                        // Get the record and a pointer to the data
	STORM_PageHandle page_handle;
	char *pData;
	
	rc = this->sfh.GetPage( page_id, page_handle);
	if (rc != OK) { return rc; }
	
	rc = page_handle.GetDataPtr(&pData);
	if (rc != OK) { return rc; }
	
                                                                                        // Copy new data. 
	memcpy(&pData[REM_PAGEHEADER_SIZE+((slot-1)*this->rem_file_header.record_size)], rh.pData, this->rem_file_header.record_size);
	
                                                                                        // Mark last page as dirty 
	rc = this->sfh.MarkPageDirty( page_id);
	if (rc != OK) { return rc; }
                                                                                        // Unpin page 
	rc = this->sfh.UnpinPage( page_id);
	if (rc != OK) { return rc; }
	
	return (OK);
}

t_rc REM_RecordFileHandle::FlushPages() const	{
	if (this->is_open) {
		t_rc rc = this->sfh.FlushAllPages();
		if (rc != OK) { return rc; }
	}
	
	return (OK);
}
