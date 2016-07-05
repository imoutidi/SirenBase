#include "REM_RecordFileScan.h"

REM_RecordFileScan::REM_RecordFileScan()	{
	this->value  = NULL;
	this->is_open = false;
}

REM_RecordFileScan::~REM_RecordFileScan()	{
	
}

t_rc REM_RecordFileScan::OpenRecordScan ( REM_RecordFileHandle &rfh, 
					 t_attrType attr_type,
					 int	attr_length, 
					 int	attr_offset, 
					 t_compOp	compOp, 
					 void *value)
{
                                                                                        // if file scan is open. 
	if (this->is_open) { return REM_FSOPEN; }
	
                                                                                        // Initialize local copies 
	this->rfh		 = &rfh;
	this->sfh		 = &rfh.sfh;
	this->attr_type   = attr_type;
	this->attr_length = attr_length;
	this->attr_offset = attr_offset;
	this->compOp	 = compOp;
	if (compOp != NO_OP) {
		this->value = malloc(attr_length);
		memcpy(this->value, value, attr_length);
	}
	
                                                                                         
	this->rem_file_header = this->rfh->rem_file_header;
	
	t_rc rc = this->sfh->GetFirstPage(this->iter_page_handle);
	if (rc != OK) { return rc; }
	rc = this->sfh->GetNextPage(this->iter_page_handle);                            // Get pages with iterator
	if (rc != OK) { return rc; }
	
	this->iter_slot = 0;
	
	
	this->is_open = true;
	return (OK);
}

t_rc REM_RecordFileScan::GetNextRecord(REM_RecordHandle &rh)	{
                                                                                         //if file scan is not open
	if (!this->is_open) { return REM_FSCLOSED; }
	t_rc rc;
	
	
	do {
		char *pData;
		int page_id;
		REM_PageHeader iter_page_header;
		
		rc = this->iter_page_handle.GetDataPtr(&pData);                         //Get data
		if (rc != OK) { return rc; }
		
		memcpy(&iter_page_header, pData, REM_PAGEHEADER_SIZE);
		
		rc = iter_page_handle.GetPageID(page_id);                               //Get page Id
		if (rc != OK) { return rc; }
		
		for (; this->iter_slot < iter_page_header.n_records; this->iter_slot++) { //Search to find the record
			
			if (Check(&pData[REM_PAGEHEADER_SIZE+(this->iter_slot*this->rem_file_header.record_size)])) {
				
				REM_RecordID rid(page_id, iter_slot+1);
								
				rc = this->rfh->ReadRecord(rid, rh);                    //Read record
				if (rc != OK) { return rc; }
				
				rc = this->sfh->UnpinPage(page_id);                     
				if (rc != OK) { return rc; }
				
				this->iter_slot++;
				
				return OK;
			}
		}
		
                                                                                        // Unpin the page
		rc = this->sfh->UnpinPage(page_id);
		if (rc != OK) { return rc; }
		
	} while (this->sfh->GetNextPage(this->iter_page_handle) != STORM_EOF);
	
	
	return REM_FSEOF;
}

t_rc REM_RecordFileScan::CloseRecordScan()	{
                                                                                        // Check if file is not open. 
	if (!this->is_open) { return REM_FSCLOSED; }
	
                                                                                        //  delete values
	this->rfh		 = NULL;
	this->sfh		 = NULL;
	this->attr_length = NULL;
	this->attr_offset = NULL;
	
                                                                                        // Free memory.
	free(this->value);
	
                                                                                        // Reset slot 
	this->iter_slot = 0;
	
                                                                                        
	this->is_open = false;
	return OK;
}

bool REM_RecordFileScan::Check(const char *pData) const {
                                                                                        // If we don't have operation
	if (this->compOp == NO_OP) {
		return true;
	}
	
	int   int1 = 0, int2 = 0;                                                           // Initialize
	const char *char1 = 0, *char2 = 0;
                                                                                        // Get value of attribute at offset attrOffset 

        bool opInt=false;
        
        if(this->attr_type == TYPE_INT)
        {
            memcpy(&int1, &pData[this->attr_offset],sizeof(int));
            int2 = * (int *) this->value;
            opInt = true;
        }
        else if(this->attr_type == TYPE_STRING)
        {
            char1 = &pData[this->attr_offset];
            char2 = (char*) this->value;
        }
	
	bool check = false;
        
        if(this->compOp == EQ_OP)                                               // Check data satisifies condition
        {
            if(opInt) 
                (int1==int2) ? check=true: check=false;
            else
                check = strncmp(char1,char2,this->attr_length)==0;
                
        }
        else if(this->compOp == LT_OP)
        {
            if(opInt) 
                (int1 < int2) ? check=true: check=false;
            else
                check = strncmp(char1,char2,this->attr_length)<0;
                
        }
        else if(this->compOp == GT_OP)
        {
            if(opInt) 
                (int1>int2) ? check=true : check=false;
            else
                check = strncmp(char1,char2,this->attr_length)>0;
        }
        else if(this->compOp == LE_OP)
        {
            if(opInt) 
                (int1<=int2) ? check=true: check=false;
            else
                check = strncmp(char1,char2,this->attr_length)<=0;
        }
        else if(this->compOp == GE_OP)
        {
            if(opInt) 
                (int1>=int2) ? check=true: check=false;
            else
                check = strncmp(char1,char2,this->attr_length)>=0;
        }
        else if(this->compOp == NE_OP)
        {
            if(opInt) 
                (int1!=int2) ? check=true: check=false;
            else
                check = strncmp(char1,char2,this->attr_length)!=0;
        }
	
	return check;
}
