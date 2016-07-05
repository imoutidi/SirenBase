#include "SYSM_DBM.h"

SYSM_DBM::SYSM_DBM(REM_RecordFileManager *rfm){
	this->rfm = rfm;
	open = false;
	this->active_db = (char*)malloc(sizeof(char)*255);
}

SYSM_DBM::~SYSM_DBM(){
	
}

t_rc SYSM_DBM::CreateDatabase (const char *db_name){
	
                                                                                        // Create directory to system
	char dir_name[260];
        char system_cmd[350];                                                           // Stores the system call
	strcpy(dir_name,db_name);							
	//snprintf(dirname,sizeof(dirname),"./data/%s",d        bName);                 //create the path for the directory (database)
        snprintf(system_cmd, sizeof(system_cmd), "mkdir %s", dir_name);
        system(system_cmd);                             				//create the directory given the path			
                                                                                        // Create the rel.met file
	char path_name[260];
	snprintf(path_name,sizeof(path_name),"%s/rel.met",dir_name);
	t_rc rc = this->rfm->CreateRecordFile(path_name,256);                           // Create the record file to store rel.met
	if (rc != OK) { return rc; }

                                                                                        // Create the attr.met file
	snprintf(path_name,sizeof(path_name),"%s/attr.met",dir_name);
	rc = this->rfm->CreateRecordFile(path_name,256);                                 // Create the record file to store attr.met
	if (rc != OK) { return rc; }
	

	return OK;
}

t_rc SYSM_DBM::OpenDatabase (const char *db_name) {

                                                                                        // Check if  another database id open
	if(open){
		return (SYSM_OTHERDBISOPEN);
	}
                                                                                
	active_db = (char*)malloc(strlen(db_name));
	strcpy(active_db,db_name);                                                      //Store witch database is open
	open = true;
	return OK;
}

t_rc SYSM_DBM::CloseDatabase(){

	if (!open) { return SYSM_DBCLOSED; }
                                                                                        //close relmet, attrmet
	delete active_db;                                                               //Make database not active
	open=false;
	return OK;
}

const char *SYSM_DBM::getdbName(){

	return active_db;
}

bool SYSM_DBM::isOpen(){
	if (open){
		return true;
	}
	return false;	
}


t_rc SYSM_DBM::DropDatabase (const char *db_name){
	char dir[260];                                                                  
        char system_cmd[350];                                                           //Store system call 
        strcpy(dir,db_name);
        snprintf(system_cmd, sizeof(system_cmd), "rm -r %s", dir);                      // Make system call to delete the file with database
	
	system (system_cmd);
	return OK;
}
