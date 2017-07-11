#include "ClientThread.h"


ClientThread::ClientThread(int accfd) : m_accfd(accfd)
{

}


ClientThread::~ClientThread()
{
   // TODO : implement
}

// 接收客户端数据的线程处理函数, 并把数据放入存储队列
void ClientThread::run(void)
{
    pthread_detach(pthread_self());     // detach thread
    
    char buf[1024]; 
    int count = 0; 
    while(recv(m_accfd, buf, sizeof(buf), 0))
    {
//        printf("%s\n", buf);  
    	MLogRec mrec2; 
          
    	sscanf(buf, "%s %d %d %d %s", mrec2.logname, &mrec2.logintime, &mrec2.logouttime, &mrec2.durations, mrec2.logip); 
    
        printf("%s\t", mrec2.logname); 
        printf("%d\t", mrec2.logintime); 
        printf("%d\t", mrec2.logouttime); 
        printf("%d\t", mrec2.durations); 
        printf("%s\n", mrec2.logip); 

        strcpy(buf, ""); 
        count++; 
    }

    printf("Total:\t%d\n", count); 


    delete this; 
}
