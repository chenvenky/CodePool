#ifndef _DATA_H_
#define _DATA_H_

#include "ClientException.h"

typedef struct
{
	char logname[32];
	int pid;
	short int  type;
	int logtime;
	char logip[257];
}LogRec;

typedef struct
{
	char logname[32];
	int logintime;
	int logouttime;
	int durations;
	char logip[257];
}MLogRec;

#endif //_DATA_H_

