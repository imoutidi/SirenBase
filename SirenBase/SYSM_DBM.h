#ifndef _SYSM_DBManager
#define _SYSM_DBManager

#include <fstream>

#include <sys/types.h>
#include <sys/io.h>
#include <sys/dir.h>
#include "REM.h"
#include "retcodes.h"


class SYSM_DBM {
	
private:

	bool open;
	char *active_db;
	
	REM_RecordFileManager *rfm;
	
public:
	SYSM_DBM(REM_RecordFileManager *rfm);
	~SYSM_DBM();
	t_rc CreateDatabase(const char *db_name);
	t_rc DropDatabase (const char *db_name);
	t_rc OpenDatabase (const char *db_name);
	t_rc CloseDatabase ();
	const char *getdbName();
	bool isOpen();	
};
#endif


