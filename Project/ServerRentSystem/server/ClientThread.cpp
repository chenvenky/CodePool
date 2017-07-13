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
	const int BUFSIZE = 2048;   
	char buf[BUFSIZE];          // Note: buf[] can't be global/static variable --- thread safe
	int rlen = 0; 
	int pos = 0; 
	int logLen = sizeof(mrec); 
	while((rlen = recv(m_accfd, buf, BUFSIZE, 0)) > 0)
	{
		int pos = 0; 
		while(rlen >= logLen) 
		{
			memcpy((char*)(&mrec) + (sizeof(mrec) - logLen), buf + pos, logLen); 
			pos += logLen; 
			rlen -= logLen; 
			
			logList.push_back(mrec); 
			logLen = sizeof(mrec); 
		}

		if(rlen < logLen)
		{
			memcpy((char*)(&mrec) + (sizeof(mrec) - logLen), buf + pos, rlen); 
			logLen -= rlen; 
		}
	}

    cout << "Total records: " << logList.size() << endl; 

    while(logList.size())
    {
        logQu << logList.front(); 
        logList.pop_front(); 
    }


    delete this; 
}
