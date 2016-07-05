#include "REM_RecordID.h"

REM_RecordID::REM_RecordID()	{
	this->page_id = -1;
	this->slot   = -1;	
	this->is_valid = false;
}

REM_RecordID::REM_RecordID(int page_id, int slot)	{
	this->page_id  = page_id;                                                       //Initialize 
	this->slot    = slot;
	this->is_valid = true;
	
	if (page_id <= 0 || slot <= 0) {
		this->is_valid = false;                                                 //Mark as not valid
	}
}

REM_RecordID::~REM_RecordID()	{
	
}

t_rc REM_RecordID::GetPageID(int &page_id) const	{
	if (!this->is_valid) { return REM_INVALIDRID; }
	
	page_id = this->page_id;                                                        //Get page id from argument
	return (OK);
}

t_rc REM_RecordID::GetSlot(int &slot) const	{
	if (!this->is_valid) { return REM_INVALIDRID; }                                 //If not valid
	
	slot = this->slot;
	return (OK);
}

t_rc REM_RecordID::SetPageID (int page_id)	{
	if (page_id <= 0) {                                                             //Check not valid page id
		return REM_INVALIDRID;
	}
	
	this->page_id = page_id;
	this->is_valid = true;
	return (OK);
}

t_rc REM_RecordID::SetSlot (int slot)	{
	if (slot <= 0) {                                                                //Check not valid slot
		return REM_INVALIDRID;
	}
	
	this->slot = slot;
	this->is_valid = true;
	return (OK);
}
