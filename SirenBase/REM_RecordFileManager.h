#ifndef _REM_RecordFileManager
#define _REM_RecordFileManager

#include "retcodes.h"
#include "STORM_StorageManager.h"
#include "REM_Structs.h"
#include "REM_RecordFileHandle.h"
#include <cstdio>

class REM_RecordFileManager {
	
private:
	
	STORM_StorageManager *sm;
	
public:
	
	REM_RecordFileManager  (STORM_StorageManager *sm);							
	~REM_RecordFileManager ();													
	
    t_rc CreateRecordFile  (const char *fname, int rs);							
    t_rc DestroyRecordFile (const char *fname);									
    t_rc OpenRecordFile    (const char *fname, REM_RecordFileHandle &rfh);		
    t_rc CloseRecordFile   (REM_RecordFileHandle &rfh);							
	
};
#endif
