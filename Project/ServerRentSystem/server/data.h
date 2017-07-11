#ifndef _DATA_H_
#define _DATA_H_

#include "ServerException.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <sys/mman.h>

#include <iostream>
#include <fstream>
#include <list>

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


// External variables
extern char **environ;      // Defined by libc

#endif //_DATA_H_
