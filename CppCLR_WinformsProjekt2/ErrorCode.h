#ifndef __ERRORCODE_H__
#define __ERRORCODE_H__
//---------------------------------------------------------------------------

const int WAR_NOACTION = 2;
const int ERR_WARNING  = 1;

const int ERR_NOERROR = 0;
const int OK = 0;

//--------- Data Error -----------------------
const int ERR_INVALID_PARAMETER       = -10;
const int ERR_DATA                    = -11;
const int ERR_OUT_OF_RANGE						= -12;

const int ERR_INVALID_POINTER_ACCESS  = -15;

//--------- Memory Error -----------------------
const int ERR_MEMORY    = -20;
const int ERR_EXCEPTION = -21;

//--------- DEVICE Error -----------------------
const int ERR_OPEN          = -40;
const int ERR_CLOSE         = -41;

const int ERR_NOT_OPEN      = -45;
const int ERR_NOT_CONNECTED = -46;
const int ERR_NOT_INIT      = -47;
const int ERR_HANDLING      = -48;

const int ERR_READ          = -50;
const int ERR_WRITE         = -51;

//--------- Library Error -----------------------
const int ERR_LIBRARY									= -60;


//--------- Data Acquisition Error -----------------------
const int ERR_DATA_ACQUISITION       = -80;
const int ERR_DATA_ACQUISITION_STOP  = -81;
const int ERR_DATA_ACQUISITION_START = -82;


//--------- Time Error -----------------------
const int ERR_TIMEOUT = -100;



//----------- Error Message ------------------
const char MSG_ERR_BADMEMALLOC[] = "Not enought memory available!";
const char MSG_INTERNAL_SOFTWARE_ERROR[] = "An internal Error accour";
#endif