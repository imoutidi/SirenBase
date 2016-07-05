#include "REM_RecordHandle.h"

REM_RecordHandle::REM_RecordHandle()	{
	this->pData	  = NULL;
	this->is_valid = false;	
}

REM_RecordHandle::~REM_RecordHandle()	{
	if (this->pData != NULL) {
		delete this->pData;
	}
}

t_rc REM_RecordHandle::GetData(char *&pData) const	{
	if (!this->is_valid) { return REM_INVALIDREC; }
	
	pData = this->pData;
	
	return (OK);
}

t_rc REM_RecordHandle::GetRecordID(REM_RecordID &rid) const	{
	if (!this->is_valid) { return REM_INVALIDREC; }
	
	rid = this->rid;
	
	return (OK);
}
