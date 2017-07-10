//#include "LogReader.h"
#include "SocketSender.h"


// Test for debug
int main()
{
    string failFile = "failFile"; 
    string Ip = "127.0.1.1"; 
    int port = 8000; 

    SocketSender sender(failFile, Ip, port); 
    list<MLogRec> log;
     
    MLogRec mrec; 
    strcpy(mrec.logname, "chenwenke"); 
    mrec.logintime = 20170710; 
    mrec.logouttime = 20170711; 
    mrec.durations = 1; 
    strcpy(mrec.logip, "192.168.0.1"); 
    log.push_back(mrec); 

    sender.sendLog(log); 

    return 0; 
}
