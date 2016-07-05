#include "REM_RecordFileManager.h"

REM_RecordFileManager::REM_RecordFileManager(STORM_StorageManager *sm)	{
	this->sm = sm;
}

REM_RecordFileManager::~REM_RecordFileManager()	{
	
}

t_rc REM_RecordFileManager::CreateRecordFile(const char *fname, int rs)	{
	
                                                                                
	int recordsPerPage = (PAGE_SIZE - REM_PAGEHEADER_SIZE)/rs;                      // calculate the records per page.
	
	if (recordsPerPage < 1) {
		return (REM_INVALIDRECSIZE);
	}
	
	
                                                                                        // Create file 
	t_rc rc = this->sm->CreateFile(fname);
	if (rc != OK) { return rc; }
	
	
                                                                                        // Open the created file 
	STORM_FileHandle storm_file_handle;

	rc = this->sm->OpenFile(fname, storm_file_handle);
	if (rc != OK) { return rc; }
	
                                                                                        // Allocate a new page for REM header page. 
	STORM_PageHandle storm_page_handle;

	rc = storm_file_handle.ReservePage(storm_page_handle);
	if (rc != OK) { return rc; }

	
                                                                                        // Get pointer to the data of the REM header page 
	char *pData;
	int page_id;

	rc = storm_page_handle.GetDataPtr(&pData);
	if (rc != OK) { return rc; }

                                                                                        // Get page number of the REM header page 
	rc = storm_page_handle.GetPageID(page_id);
	if (rc != OK) { return rc; }
	
                                                                                        //initialize file header
	REM_FileHeader 
	fileHeader = { 0,	// # of records currently stored in file.
		rs, // record size
		recordsPerPage, //records /page
		true
	};
	
                                                                                        // Copy	REM File Header to the first page 
	memcpy(pData, &fileHeader, REM_FILEHEADER_SIZE);
		
	
                                                                                        //We mark the page as dirty because we modified it
	rc = storm_file_handle.MarkPageDirty(page_id);
	if (rc != OK) { return rc; }
	rc = storm_file_handle.FlushPage(page_id);
	if (rc != OK) { return rc; }

                                                                                        // Unpin page
	rc = storm_file_handle.UnpinPage(page_id);
	if (rc != OK) { return rc; }	
	
                                                                                        // We close the file 
	rc = this->sm->CloseFile(storm_file_handle);
	if (rc != OK) { return rc; }	
	
	return(OK);
}

t_rc REM_RecordFileManager::DestroyRecordFile(const char *f_name)	{
	
        return this->sm->DestroyFile(f_name);                                           //Destroy record file with file name
}

t_rc REM_RecordFileManager::OpenRecordFile(const char *f_name, REM_RecordFileHandle &rfh)	{

                                                                                        // Close record file handler if it's already open 
	if (rfh.is_open) {
		CloseRecordFile(rfh);
	}
	
                                                                                        // Open file
	t_rc rc = this->sm->OpenFile(f_name, rfh.sfh);
	if (rc != OK) { return rc; }
	
	
                                                                                       
	STORM_PageHandle page_handle;
                                                                                         // Get the first page. */
	rc = rfh.sfh.GetFirstPage(page_handle);
	if (rc != OK) { return rc; }
	
                                                                                        // Get the REM File Header 
	rc = page_handle.GetDataPtr(&rfh.pData_fileHeader);
	if (rc != OK) { return rc; }
	
	rc = page_handle.GetPageID(rfh.page_num_file_header);
	if (rc != OK) { return rc; }
	
	
	memcpy(&rfh.rem_file_header, &rfh.pData_fileHeader[0], REM_FILEHEADER_SIZE);
	
	printf ("We now have number of records = %d with size = %d and we store per page = %d in file %s \n", rfh.rem_file_header.n_records, rfh.rem_file_header.record_size,rfh.rem_file_header.records_per_page, f_name);
	
	
	rfh.is_open = true;
	
	return (OK);
}

t_rc REM_RecordFileManager::CloseRecordFile(REM_RecordFileHandle &rfh)	{
	
                                                                                // If record file handler is already closed
	if (!rfh.is_open) { return REM_FHCLOSED; }
                                                                                //Flash pages to close the file safe
	t_rc rc = rfh.sfh.FlushAllPages();
	if (rc != OK) { return rc; }
                                                                                // Unpin page we have already flush 
	rc = rfh.sfh.UnpinPage(rfh.page_num_file_header);
	if (rc != OK) { return rc; }
	
	rc = this->sm->CloseFile(rfh.sfh);
	if (rc != OK) { return rc; }
                
	rfh.is_open = false;
	
	return (OK);
}
