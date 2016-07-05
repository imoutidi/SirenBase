#ifndef _REM_Components_h
#define _REM_Components_h

#include "components.h"

typedef enum {
	NOT_FULL_PAGE,                                                                  // We can save records
	FULL_PAGE                                                                       // We can't save records
} RM_PageType;
typedef struct REM_PageHeader {

	int n_records;                                                                   // Number of records a page currently have
	
} REM_PageHeader;
#define REM_PAGEHEADER_SIZE sizeof(REM_PageHeader)

typedef struct REM_FileHeader {

	int n_records;                                                                  // Number of all records in the file.
	int record_size;                                                                // Size / record.
	int records_per_page;                                                   	// Number of records that can be hold by page.
	bool is_last_page_full;
	
} REM_FileHeader;
#define REM_FILEHEADER_SIZE sizeof(REM_FileHeader)

#endif