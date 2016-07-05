#ifndef _REM_RecordFileScan
#define _REM_RecordFileScan

#include "retcodes.h"
#include "REM_Structs.h"
#include "REM_RecordFileHandle.h"
#include "REM_RecordHandle.h"

class REM_RecordFileScan { 
  private:
	
	REM_RecordFileHandle *rfh;
	STORM_FileHandle *sfh;
	
	t_attrType attr_type;
	int	attr_length;
	int	attr_offset; 
	t_compOp	compOp;
	void	*value;
	
	REM_FileHeader rem_file_header;
	
	STORM_PageHandle iter_page_handle;
	int iter_slot;
	
	bool is_open;
	
	bool Check(const char *pData) const;
	
  public:
	
	REM_RecordFileScan(); 
	~REM_RecordFileScan();
	
	t_rc OpenRecordScan (REM_RecordFileHandle &rfh, 
						 t_attrType attr_type,
						 int	attr_length, 
						 int	attrOffset, 
						 t_compOp	compOp, 
						 void	*value);
	t_rc GetNextRecord(REM_RecordHandle &rh); 
	t_rc CloseRecordScan();
	
};
#endif
