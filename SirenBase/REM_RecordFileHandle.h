#ifndef _REM_RecordFileHandle_h
#define _REM_RecordFileHandle_h

#include "retcodes.h"
#include "STORM.h"
#include "REM_Structs.h"
#include "REM_RecordID.h"
#include "REM_RecordHandle.h"

class REM_RecordFileHandle { 
  private:
	
	STORM_FileHandle sfh;
        REM_FileHeader rem_file_header;
        int page_num_file_header;
	bool is_open; 
	char *pData_fileHeader;
	
  public:
	
	REM_RecordFileHandle(); 
	~REM_RecordFileHandle();
	
	t_rc ReadRecord (const REM_RecordID &rid, REM_RecordHandle &rh); 
	t_rc InsertRecord (const char *pData, REM_RecordID &rid); 
	t_rc DeleteRecord (const REM_RecordID &rid); 
	t_rc UpdateRecord (const REM_RecordHandle &rh);
	t_rc FlushPages () const;
	
	friend class REM_RecordFileManager;
	friend class REM_RecordFileScan;
};
#endif
