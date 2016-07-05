#ifndef _SSQLM_DDL
#define _SSQLM_DDL

#include "REM.h"
#include "retcodes.h"

class SSQLM_DDL{

private:

	REM_RecordFileManager *rfm;
	REM_RecordFileHandle *attrmet;
	REM_RecordFileHandle *relmet;
	char *dbName;

	t_rc Open_Rel(char *dbName);
	t_rc Open_Attr(char *dbName);

	t_rc E_Attr(char *str, const char *tName, char *t_names);           //Edit attridute metadata table
	t_rc E_Rel(const char *tName, int recSize, int numOfColumns);       //Edit relations metadata table
	t_rc Delete_Meta(const char *tName);                                    //Delete metadata table
        t_rc F_R_RelMet(const char *tName, REM_RecordHandle &rh);               //Find record in relation metadata table
        t_rc F_R_AttrMet(const char *tName, REM_RecordHandle &rh);              //Find record in attributes metadata table
	
public:

	SSQLM_DDL(REM_RecordFileManager *rfm, char *dbName);
	~SSQLM_DDL();

	

	t_rc CreateTable(const char *tname, const char *attributes);
	t_rc DropTable(char *tname);
	
};

#endif