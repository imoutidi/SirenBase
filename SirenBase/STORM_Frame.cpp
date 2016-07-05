/* ============================================================================================== */
// STORM_Frame.cpp
//
// Implementation of the memory frame. Each frame is associated to a disk page.
// 
// 
// 
//
//
//
//
//
// -----------------------
// Last update: 9/3/2009
/* ============================================================================================== */

#include "STORM_Frame.h"
#include <stdlib.h>

//-----------------------------------------------------------------------------------------------
// Constructor
//
//
//-----------------------------------------------------------------------------------------------
STORM_Frame::STORM_Frame()
{
	m_reservedBit = false;
	m_fileID = INVALID_FILEID;
	m_page.pageID = INVALID_NUMBER;
	m_dirtyBit = false;	  
	m_pinCount = 0;	  
			  
	m_p_previous = NULL; 
	m_p_next = NULL;     
}


//-----------------------------------------------------------------------------------------------
// Destructor
//
//
//-----------------------------------------------------------------------------------------------
STORM_Frame::~STORM_Frame()
{


}


