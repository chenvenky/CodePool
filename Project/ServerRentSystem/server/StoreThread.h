#ifndef __STORETHREAD_H__
#define __STORETHREAD_H__

#include <iostream>
#include "LogDao.h"
#include "LogThread.h"
using namespace std;

class StoreThread : public LogThread
{
public:
   StoreThread(LogDao& dao);
   ~StoreThread();
   virtual void run(void);  // 从存储队列取出数据，交给dao 

private:
   LogDao& m_dao;   // 将数据插入到数据库中
};

#endif  // __STORETHREAD_H__
