#ifndef _REM_RecordID
#define _REM_RecordID

#include "retcodes.h"

class REM_RecordID { 
  private:
	
	int page_id;
	int slot;
	
	bool is_valid;
	
  public:
	
	REM_RecordID(); 
	REM_RecordID(int page_id, int slot); 
	~REM_RecordID();
	
	t_rc GetPageID(int &page_id) const; 
	t_rc GetSlot(int &slot) const; 
	t_rc SetPageID (int page_id); 
	t_rc SetSlot (int slot);
	
};
#endif