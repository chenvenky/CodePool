#include "StoreThread.h"

StoreThread::StoreThread(LogDao &dao) : m_dao(dao)
{

}

StoreThread::~StoreThread()
{

}

// 从存储队列中取出数据，交给 dao
void StoreThread::run(void)
{
    extern LogQueue logQu; 

    MLogRec storeRec; 

    // ToDO
    while(1)
    {
        logQu >> storeRec; 
/*
        printf("%s\t", storeRec.logname); 
        printf("%d\t", storeRec.logintime); 
        printf("%d\t", storeRec.logouttime); 
        printf("%d\t", storeRec.durations);
        printf("%s\n", storeRec.logip); 
*/
        // TODO: 存入数据库或数据库文件

        // 存入数据库文件
        m_dao.insert(storeRec); 

    }

   delete this; 
}
