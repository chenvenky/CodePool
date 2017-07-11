#include "ClientThread.h"


ClientThread::ClientThread(int accfd) : m_accfd(accfd)
{

}


ClientThread::~ClientThread()
{

}

// 接收客户端数据的线程处理函数, 并把数据放入存储队列
void ClientThread::run(void)
{
    
    extern LogQueue logQu; 
    char buf[1024]; 
    int count = 0; 

    list<MLogRec> logList; 
    while(recv(m_accfd, buf, sizeof(buf), 0))
    {
//        printf("%s\n", buf);  
    	MLogRec mrec; 
          
    	sscanf(buf, "%s %d %d %d %s", mrec.logname, &mrec.logintime, &mrec.logouttime, &mrec.durations, mrec.logip); 
        strcpy(buf, ""); 

        logList.push_back(mrec); 
        
/*      
        printf("%s\t", mrec.logname); 
        printf("%d\t", mrec.logintime); 
        printf("%d\t", mrec.logouttime); 
        printf("%d\t", mrec.durations); 
        printf("%s\n", mrec.logip); 

        strcpy(buf, ""); 
        count++; 
*/
    }

    while(logList.size())
    {
        logQu << logList.front(); 
        logList.pop_front(); 
    }

//    printf("Total:\t%d\n", count); 


    delete this; 
}
