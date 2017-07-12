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

    list<MLogRec> logList; 
    MLogRec mrec; 

    while(1)
    {
        int len = sizeof(mrec); 
        int rlen = 0; 
        while(len)
        {
            rlen = recv(m_accfd, (char*)(&mrec) + (sizeof(mrec) - len), len, 0); 
            
            if(rlen <= 0)       // end or err
                goto label; 

            len -= rlen; 
        }

        logList.push_back(mrec); 
    }
    
label:
    cout << "Total records: " << logList.size() << endl; 

    while(logList.size())
    {
        logQu << logList.front(); 
        logList.pop_front(); 
    }


    delete this; 
}
