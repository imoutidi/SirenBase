#ifndef _SSQLM_DML
#define _SSQLM_DML

#include "REM.h"
#include "SYSM.h"
#include "retcodes.h"

class SSQLM_DML {

private:

	REM_RecordFileManager *rfm;
	REM_RecordFileHandle *attrmet;
	REM_RecordFileHandle *relmet;
	char *dbName;

	t_rc Open_Rel(char *dbName);
	t_rc Open_Attr(char *dbName);

public:

	SSQLM_DML(REM_RecordFileManager *rfm, char *dbName);
	~SSQLM_DML();
        
	t_rc Insert(const char *tName, const char *record);
	
};

#endif