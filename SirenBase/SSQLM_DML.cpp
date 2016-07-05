
#include "SSQLM_DML.h"
#include "SSQLM_DDL.h"
#include <string>
#include <iostream>
#include <cstring>


using namespace std;

SSQLM_DML::SSQLM_DML(REM_RecordFileManager *rfm, char *dbName){
	this->rfm = rfm;
	this->dbName = dbName;
	t_rc rc = Open_Rel(dbName);                                                   //Open rel.met file
	rc = Open_Attr(dbName);                                                       //Open attr.met file
}

SSQLM_DML::~SSQLM_DML(){

	rfm->CloseRecordFile(*attrmet);
	rfm->CloseRecordFile(*relmet);
	delete(attrmet);
	delete(relmet);
	delete(rfm);
	
}

t_rc SSQLM_DML::Insert(const char *tName,const char *record){
	
	char pathname[50];								
	REM_RecordFileHandle *rfh = new REM_RecordFileHandle();                         //Open record file to write
	REM_RecordID rid;												
																	
																	
                                                                                        //Open the record file with table infos
	snprintf(pathname,sizeof(pathname),"%s/%s",dbName,tName);
	t_rc rc = rfm->OpenRecordFile(pathname,*rfh);
	if (rc != OK) { return rc; }

                                                                                        // Insert new record							
	rc = rfh->InsertRecord(record,rid);						
	if (rc != OK) { return rc; }							

	// Close the table file
	rc = rfm->CloseRecordFile(*rfh);
	if (rc != OK) { return rc; }
	
	return OK;
}


t_rc SSQLM_DML::Open_Rel(char *dbName){
	char pathname[255];
	this->relmet = new REM_RecordFileHandle();
	snprintf(pathname,sizeof(pathname),"%s/rel.met",dbName);
	t_rc rc = rfm->OpenRecordFile(pathname,*relmet);                                //Open rel.met
	if (rc != OK) { return rc; }

	return OK;
}

t_rc SSQLM_DML::Open_Attr(char *dbName){
	char pathname[255];
	this->attrmet = new REM_RecordFileHandle();
	snprintf(pathname,sizeof(pathname),"%s/attr.met",dbName);                       //Open attr.met
	t_rc rc = rfm->OpenRecordFile(pathname,*attrmet);
	if (rc != OK) { return rc; }

	return OK;
}