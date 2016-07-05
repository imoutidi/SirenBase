
#include "STORM.h"
#include "REM.h"
#include "SYSM.h"
#include "SSQLM.h"
#include <iostream>
#include <stdio.h>

void testStorm() {
	
	STORM_StorageManager mgr;
	STORM_FileHandle fh;
	t_rc rc;
	int nAllocPages, nResPages;
	STORM_PageHandle ph;
	char *data;
	int val;
	int pid;
	int nreqs, nreads, nwrites, npinned, nframes;
	
	// ====================== STEP 1 =======================================//
	// Create the file. 
	// Open the file.
	// Reserve 100 pages.
	// Store something in each page.
	// Close the file.
	//======================================================================//
	
	rc = mgr.CreateFile("test.dat");
	if (rc != OK) {DisplayReturnCode(rc); Pause(); exit(-1);}
        
	rc = mgr.OpenFile("test.dat", fh);
	if (rc != OK) {DisplayReturnCode(rc); Pause(); exit(-1);}
	
	nAllocPages = fh.GetNumAllocatedPages();
	nResPages = fh.GetNumReservedPages();
	
	for (int i=1; i<=100; i++)
	{
		rc = fh.ReservePage(ph);
		if (rc != OK) {DisplayReturnCode(rc); Pause(); exit(-1);}
		
		// Copy something to the page.
		rc = ph.GetDataPtr(&data);
		memcpy(data, &i, sizeof(int));  
		
		// Mark the page as dirty.
		rc = ph.GetPageID(pid);
		if (rc != OK) {DisplayReturnCode(rc); exit(-1);}
		
		rc = fh.MarkPageDirty(pid);
		if (rc != OK) {DisplayReturnCode(rc); exit(-1);}
		
		// Unpin the page
		rc = fh.UnpinPage(pid);
		if (rc != OK) {DisplayReturnCode(rc); exit(-1);}
	}
	
	mgr.GetStats(nreqs, nreads, nwrites, npinned, nframes);
	printf("reqs: %d, reads: %d, writes: %d, pinned: %d, frames: %d\n", nreqs, nreads, nwrites, npinned, nframes);
	printf("allocated pages: %d, reserved pages: %d\n", fh.GetNumAllocatedPages(), fh.GetNumReservedPages());
	
	rc = mgr.CloseFile(fh);
	if (rc != OK) {DisplayReturnCode(rc); exit(-1);}
	
	Pause();
	
	// ====================== STEP 2 =======================================//
	// Open the file again. 
	// Read every page of the file and print the page contents.
	// Release the first 50 pages.
	// Close the file.
	//======================================================================//
	
	rc = mgr.OpenFile("test.dat", fh);
	if (rc != OK){DisplayReturnCode(rc); exit(-1);}
	
	printf("allocated pages: %d, reserved pages: %d\n", fh.GetNumAllocatedPages(), fh.GetNumReservedPages());
	
	// Display page contents.
	while (fh.GetNextPage(ph) != STORM_EOF)
	{
		rc = ph.GetDataPtr(&data);
		if (rc != OK) {DisplayReturnCode(rc);exit(-1);}
		memcpy(&val, data, sizeof(int));
		
		ph.GetPageID(pid);
		printf("contents of page %d = %d\n", pid, val);
		
		// Unpin the page
		rc = fh.UnpinPage(pid);
		if (rc != OK) {DisplayReturnCode(rc); exit(-1);}
	}
	
	// Release pages from 1 to 50.
	for (int p=1; p<=50; p++)
	{
		rc = fh.ReleasePage(p);
		if (rc != OK) {DisplayReturnCode(rc); exit(-1);}
	}
	
	printf("allocated pages: %d, reserved pages: %d\n", fh.GetNumAllocatedPages(), fh.GetNumReservedPages());
	
	rc = mgr.CloseFile(fh);
	if (rc != OK) {DisplayReturnCode(rc); exit(-1);}
	
	Pause();
	
	// ====================== STEP 3 =======================================//
	// Open the file again. 
	// Read every page of the file and print the page contents.
	// Close the file.
	// Finally, destroy the file.
	//
	// We expect to see only 50 pages staring from 51 up to 100, since the
	// first 50 have been released in the previous step.
	//======================================================================//
	
	rc = mgr.OpenFile("test.dat", fh);
	if (rc != OK){DisplayReturnCode(rc); exit(-1);}
	
	// Display page contents.
	while (fh.GetNextPage(ph) != STORM_EOF)
	{
		rc = ph.GetDataPtr(&data);
		if (rc != OK) {DisplayReturnCode(rc);exit(-1);}
		memcpy(&val, data, sizeof(int));
		
		ph.GetPageID(pid);
		printf("contents of page %d = %d\n", pid, val);
		
		// Unpin the page
		fh.UnpinPage(pid);
	}
	
	printf("allocated pages: %d, reserved pages: %d\n", fh.GetNumAllocatedPages(), fh.GetNumReservedPages());
	
	rc = mgr.CloseFile(fh);
	if (rc != OK) {DisplayReturnCode(rc); exit(-1);}
	
	Pause();
	
	rc = mgr.DestroyFile("test.dat");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}
	
}

void testREM() {
    
	STORM_StorageManager mgr;
	STORM_FileHandle fh;
	t_rc rc;
	STORM_PageHandle ph;
	
	REM_RecordFileManager *rmgr = new REM_RecordFileManager(&mgr);
	
	REM_RecordFileHandle rfh;
//	create 3 temp data files for testing	
	rc = rmgr->CreateRecordFile("temp.dat", 40);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	rc = rmgr->CreateRecordFile("temp2.dat", 40);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	rc = rmgr->CreateRecordFile("temp3.dat", 40);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
//	open the first one	
	rc = rmgr->OpenRecordFile("temp.dat", rfh);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	REM_RecordID r_id1, r_id2, r_id3;
	int pageID, slot;
//	inserting a record in the first temp file	
	rc = rfh.InsertRecord("this is a record", r_id1);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	rc = r_id1.GetPageID(pageID);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	rc = r_id1.GetSlot(slot);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	printf("Record inserted in page with id = %d in slot = %d \n", pageID, slot);
	
	rc = rfh.InsertRecord("this is another record", r_id2);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
		
	rc = r_id2.GetPageID(pageID);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	rc = r_id2.GetSlot(slot);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	printf("Record inserted in page with id = %d in slot = %d \n", pageID, slot);

	rc = rfh.InsertRecord("this is yet another record", r_id3);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
		
	rc = r_id3.GetPageID(pageID);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	rc = r_id3.GetSlot(slot);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	printf("Record inserted in page with id = %d in slot = %d \n", pageID, slot);
	
	REM_RecordHandle rh;
	char *pData;
//	test reading abilities, read record 1	
	rc = rfh.ReadRecord(r_id1, rh);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	rh.GetData(pData);
	printf("Read record %d, contains \'%s\' \n",1, pData);

	rc = rfh.ReadRecord(r_id2, rh);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	rh.GetData(pData);
	printf("Read record %d, contains \'%s\' \n",2, pData);

	rc = rfh.ReadRecord(r_id3, rh);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	rh.GetData(pData);
	printf("Read record %d, contains \'%s\' \n",3, pData);
	
	
	
	REM_RecordFileScan fs;
	
	
	rc = fs.OpenRecordScan(rfh, TYPE_STRING, 18, 0, EQ_OP, (char*)"this is yet another record");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	rc = fs.GetNextRecord(rh);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	rh.GetData(pData);
	printf("File scan found record  \'%s\' \n", pData);
	
//	delete record 1	
	rfh.DeleteRecord(r_id1);
//	try to read it	
	rc = rfh.ReadRecord(r_id1, rh);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	rh.GetData(pData);
	printf("Read record %d, contains \'%s\' \t*record 1 is deleted and replaced by the last one*\n",1, pData);
	

	memcpy(pData, "this is no record", 40);
	
	rfh.UpdateRecord(rh);
	
	rc = rfh.ReadRecord(r_id1, rh);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	rh.GetData(pData);
	printf("Read record %d, contains \'%s\' \t\t*record 1 is updated to new context*\n",1, pData);
	
	rc = rmgr->CloseRecordFile(rfh);
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

//	destroying the record file
	rc = rmgr->DestroyRecordFile("temp.dat");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
	rc = rmgr->DestroyRecordFile("temp2.dat");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	rc = rmgr->DestroyRecordFile("temp3.dat");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	
}

void testSYSM() {

	STORM_StorageManager mgr;
	REM_RecordFileManager *rfm = new REM_RecordFileManager(&mgr);

	SYSM_DBM *sdm = new SYSM_DBM(rfm);

	// Create the folder "testingDB" which contains the files rel.met and attr.met
	t_rc rc= sdm->CreateDatabase("DataBase");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

//	// Open the database to use it
	rc = sdm->OpenDatabase("DataBase");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	rc = sdm->DropDatabase("DataBase");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	delete sdm;
	delete rfm;
}

void testSSQLM() {

	STORM_StorageManager *mgr = new STORM_StorageManager();
	REM_RecordFileManager *rfm = new REM_RecordFileManager(mgr);
	SYSM_DBM *sdm = new SYSM_DBM(rfm);
	
        t_rc rc = sdm->DropDatabase("DataBase");
        
        rc = sdm->CreateDatabase("DataBase");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	// Open the database to use it
        SSQLM_DDL *ddlm = new SSQLM_DDL(rfm,"DataBase");
        
	rc = sdm->OpenDatabase("DataBase");
        
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	
	//Get the name of the active db
	char dbName[50];
	strcpy(dbName,sdm->getdbName());

	// Create a table with name "table1"
	rc = ddlm->CreateTable("table1","id INT- name CHAR(15)- surname CHAR(15)");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	rc = ddlm->CreateTable("table2","id INT- aem INT- grade INT");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}

	rc = ddlm->CreateTable("table3","id INT- otherid INT");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}

	rc = ddlm->CreateTable("table4","asd INT- asdd INT- asddd INT");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}

	// Drop table
	rc = ddlm->DropTable("table4");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	
	delete ddlm;
	delete sdm;
	delete rfm;
	delete mgr;

	STORM_StorageManager *mgr2 = new STORM_StorageManager();
	REM_RecordFileManager *rfm2 = new REM_RecordFileManager(mgr2);

	SYSM_DBM *sdm2 = new SYSM_DBM(rfm2);

	


	//test DML part

	SSQLM_DML *dmlm = new SSQLM_DML(rfm2,"DataBase");
//	add "-" to reache the apropriate size of a record
	rc = dmlm->Insert("table1","1---Christos-------Melidis--------");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}

	rc = dmlm->Insert("table1","2---Kiriakos-------Adam-----------");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	rc = dmlm->Insert("table1","3---Hraklhs--------Moutidis-------");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	




	rc = dmlm->Insert("table2","1---1816--10");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	rc = dmlm->Insert("table2","2---1890--10");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	rc = dmlm->Insert("table2","3---1214--11");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	



	
	rc = dmlm->Insert("table3","1---4567");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	rc = dmlm->Insert("table3","123-432");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	rc = dmlm->Insert("table3","12341234");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}	

	rc = dmlm->Insert("table3","09874321");
	if (rc != OK) {DisplayReturnCode(rc);exit(-1);}


	delete dmlm;
	delete sdm2;
	delete rfm2;
	delete mgr2;


}

int main()	{
	
	testREM();
	
//	testSYSM();
	
//      testSSQLM();

	return (0);
}
