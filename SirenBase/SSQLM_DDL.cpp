#include "SSQLM_DDL.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

SSQLM_DDL::SSQLM_DDL(REM_RecordFileManager *rfm, char *dbName){
	this->rfm = rfm;
	this->dbName = (char*)malloc(sizeof(char)*strlen(dbName));                      //Allocate memory to store the database name
	strcpy(this->dbName,dbName);
	t_rc rc = Open_Rel(dbName);                                                   //Open database for relations
        DisplayReturnCode(rc);

	rc = Open_Attr(dbName);                                                       //Open database for attributes
        DisplayReturnCode(rc);

}

SSQLM_DDL::~SSQLM_DDL(){
}

t_rc SSQLM_DDL::CreateTable(const char *tName, const char *attributes){
	
	
	char pathname[255];
	char t_atrrs[200];
        strcpy(t_atrrs,"");
	char t_types[100];
	strcpy(t_types,"");

                                                                                        // Count attributes
	int recSize = 0;
	int numOfColumns=0;
	char *str;
	t_rc rc;

	int attrlength = strlen(attributes);                                            //Get attributes to store to table
	str = (char*)malloc(attrlength);
	strcpy(str,attributes);                                                         //Copy attributes to table
	char *tokens, *c_token;
	char *nextToken;

        tokens = strtok_r (str, "- ()", &nextToken);                                    //Split attributes to get INT and CHAR lengths and
        while (tokens != NULL)
	{
                if(strcmp(tokens,"INT")==0)                                             //For etch integer we want 4 bytes
                {
                    numOfColumns++;
                    recSize +=4;
                    strcat(t_types,tokens);                                             //Store tokens
                    strcat(t_types," ");
                    
                }
                else if(strcmp(tokens,"CHAR")==0){
                    numOfColumns++;
                    strcat(t_types,tokens);
                    
                    c_token=strtok_r (NULL,"- ()", &nextToken);                         //If we have CHAR we have to store the tokens so we get the next one token
                    printf("%s\n",c_token);
                    stringstream str;
                    str << c_token;
                    int x;
                    str >> x;
                    recSize +=x;                                                        //For each char sum to the size
                    strcat(t_types,"(");
                    strcat(t_types,c_token);
                    strcat(t_types,")");
                    strcat(t_types," ");
                }
                else
                {
                    
                    strcat(t_atrrs, tokens);                                            //Not integer nor char, attribute name it is
                    strcat(t_atrrs, " ");
                }
		tokens = strtok_r (NULL, "- ()", &nextToken);
                
	
        }
        
                                                                                	// Calculate record size and insert  attributes in attr.met      
        printf("Edit str %s, tName %s,t_arrs %s \n",t_types,tName,t_atrrs);
	rc = E_Attr(t_types, tName, t_atrrs);
	if (rc != OK) { return rc; }

                                                                                        // Create and insert the record for the rel.met
	rc = E_Rel(tName,recSize,numOfColumns);
	if (rc != OK) { return rc; }

                                                                                        // Create the database file
	snprintf(pathname,sizeof(pathname),"%s/%s",dbName,tName);
	rc = rfm->CreateRecordFile(pathname,recSize);
	if (rc != OK) { return rc; }

	return OK;
}

t_rc SSQLM_DDL::DropTable(char *tName){

	t_rc rc;
	char pathname[50];
	
        rc = Delete_Meta(tName);                                                    //Delete the table 
	if (rc != OK) {return rc;}
        
        snprintf(pathname,sizeof(pathname),"%s/%s",dbName,tName);
	rc = rfm->DestroyRecordFile(pathname);                                          //Delete the database file
	if (rc != OK) { return rc; }

	

	return OK;
}





t_rc SSQLM_DDL::Open_Rel(char *dbName){
	char pathname[255];
	this->relmet = new REM_RecordFileHandle();
	snprintf(pathname,sizeof(pathname),"%s/rel.met",dbName);                       
	t_rc rc = rfm->OpenRecordFile(pathname,*relmet);                                 //Open rel.met file from directory
	if (rc != OK) { return rc; }

	return OK;
}

t_rc SSQLM_DDL::Open_Attr(char *dbName){
	char pathname[255];
	this->attrmet = new REM_RecordFileHandle();                                     
	snprintf(pathname,sizeof(pathname),"%s/attr.met",dbName);                       
	t_rc rc = rfm->OpenRecordFile(pathname,*attrmet);                               //Open attr.met file from directory
	if (rc != OK) { return rc; }

	return OK;
}

t_rc SSQLM_DDL::E_Attr(char *str, const char *tName, char *t_atrrs){

	char *tokens, *n_tokens;
	char *nextToken, *t_next_token;
        int rec_size=0;
	
        tokens = strtok_r (str, " ", &nextToken);                               //Get next attribute type
        n_tokens = strtok_r (t_atrrs, " ", &t_next_token );                     //Get next attribute name
        
        
	char *char_token;                                                       //Used only in case of char attribute in table
	                                                     
	char buffer[15];
	char attr_string[200];
	REM_RecordID rid;
	t_rc rc;

	while (tokens != NULL)
	 {
		 if(strcmp(tokens,"INT") == 0){
                         
                         
			 strcpy(attr_string,tName);                             //Table name 
			 strcat(attr_string,":");
			 strcat(attr_string,n_tokens);                          //Attribute name
			 strcat(attr_string,":");
                         sprintf( buffer, "%d", rec_size );
			 strcat(attr_string,buffer);                            //Where the attribute starts in record (in Bytes)
			 strcat(attr_string,":");
			 strcat(attr_string,"TYPE_INT");                        //Attribute type
			 strcat(attr_string,":");
			 strcat(attr_string,"4");                               //Attribute size
			 strcat(attr_string,":");
			 strcat(attr_string,"-1::");                            //No index available
                         
                         rec_size +=4;
			 
                         printf("Attr %s\n",attr_string);
			 rc = attrmet->InsertRecord(attr_string,rid);
			 if (rc != OK) { return rc; }
                         
                         
			 
		 }
		 else if(strcmp(tokens,"CHAR") == 0){                           

			 char_token = strtok_r (NULL, "()", &nextToken);
                         stringstream str;                                      //Make the char* integer for the number of Characters required
                        str << char_token;
                        int x;
                        str >> x;
                        
			 strcpy(attr_string,tName);                             //Table name 
			 strcat(attr_string,":");
			 strcat(attr_string,n_tokens);                          //Attribute name
			 strcat(attr_string,":");
                         sprintf( buffer, "%d", rec_size );
			 strcat(attr_string,buffer);                            //Where the attribute starts in record (in Bytes)
			 strcat(attr_string,":");
			 strcat(attr_string,"TYPE_STRING");                     //Attribute type
			 strcat(attr_string,":");
			 strcat(attr_string,char_token);                        //Attribute size
			 strcat(attr_string,":");
			 strcat(attr_string,"-1::");                            //No index available
                         
                         rec_size += x;
                         
                         printf("Attr %s\n",attr_string);
			 rc = attrmet->InsertRecord(attr_string,rid);
			 if (rc != OK) { return rc; }

		 }
		 
                tokens = strtok_r (NULL, " ()", &nextToken);                    //Get next attribute type
                n_tokens = strtok_r (NULL, " ", &t_next_token );                //Get the next attribute name
                

	 }

	rc = attrmet->FlushPages();
	if (rc != OK) { return rc; }

	return OK;
}

t_rc SSQLM_DDL::E_Rel(const char *tName, int recSize, int numOfColumns){

	char buffer[5];
	REM_RecordID rid;
	t_rc rc;
	char record_string[256];

	strcpy(record_string,tName);                                                    //Get the table name
	strcat(record_string,";");
        sprintf( buffer, "%d", recSize );
        strcat(record_string,buffer);
	strcat(record_string,";");
        sprintf( buffer, "%d", numOfColumns );
        strcat(record_string,buffer);
	strcat(record_string,";");
	strcat(record_string,"0;;");

        printf("Rel %s\n",record_string);
	rc = relmet->InsertRecord(record_string,rid);                                   //Insert meta data data record
	if (rc != OK) { return rc; }

	rc = relmet->FlushPages();
	if (rc != OK) { return rc; }

	return OK;
}

t_rc SSQLM_DDL::Delete_Meta(const char *tName){
	
	char *pData;
	t_rc rc;
	REM_RecordHandle rh;
	REM_RecordID rid;

                                                                                        
	rc = F_R_RelMet(tName,rh);                                              //Find records of table
	if (rc != OK) { return rc; }

	rc = rh.GetRecordID(rid);                                                       //Get the record id
	if (rc != OK) {return rc; }
        
        int pid, slot;
        rid.GetPageID(pid);                                                             // Get page id and slot 
        rid.GetSlot(slot);
	
        rc = relmet->DeleteRecord(rid);                                                 // Delete metadata from rel.met
	if (rc != OK) {return rc; }
        rid.GetPageID(pid);
        rid.GetSlot(slot);
        printf("deleted rel RID %d %d\n",pid, slot);
        

	rc = relmet->FlushPages();
	if (rc != OK) {return rc; }

	
        int old_slot = 0;
	while(F_R_AttrMet(tName,rh) != STORM_EOF){                              //Find records of attributes
		rc = rh.GetRecordID(rid);                                               //Get the record id
		if (rc != OK) {return rc; }
                
                
                rid.GetPageID(pid);                                                     // Get page id and slot 
                rid.GetSlot(slot);
                
                if(old_slot!=0 && old_slot==slot) break;
                old_slot = slot;

		rc = attrmet->DeleteRecord(rid);                                        // Delete metadata from attr.met
		if (rc != OK) {return rc; }
                
                rid.GetPageID(pid);
                rid.GetSlot(slot);
                printf("deleted attr RID %d %d\n",pid, slot);

		rc = attrmet->FlushPages();
		if (rc != OK) {return rc; }
	}


	return OK;
}


t_rc SSQLM_DDL::F_R_RelMet(const char *tName, REM_RecordHandle &rh){
	t_rc rc;
	REM_RecordFileScan *rfs = new REM_RecordFileScan();

	int tNameLength = strlen(tName);
	rc = rfs->OpenRecordScan(*relmet,TYPE_STRING,tNameLength, 0, EQ_OP, (char*)tName); //Open record of relations with specific recordHandle
	if (rc != OK) {return rc; }

	rc = rfs->GetNextRecord(rh);                                                    //Get record
	if (rc != OK) {return rc; }

                                                                                        // Close FileScan
	rc = rfs->CloseRecordScan();
	if (rc != OK) {return rc; }

	return OK;
}
t_rc SSQLM_DDL::F_R_AttrMet(const char *tName, REM_RecordHandle &rh){
	t_rc rc;
	REM_RecordFileScan *rfs = new REM_RecordFileScan();

	int tNameLength = strlen(tName);
	rc = rfs->OpenRecordScan(*attrmet,TYPE_STRING,tNameLength, 0, EQ_OP, (char*)tName);     //Open record of attributes with specific recordHandle
	if (rc != OK) {return rc; }
        
	rc = rfs->GetNextRecord(rh);                                                            //Get record  
	if (rc != OK) {return rc; }

                                                                                        // Close FileScan
	rc = rfs->CloseRecordScan();
	if (rc != OK) {return rc; }

	return OK;
}

