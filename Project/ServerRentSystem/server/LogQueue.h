#ifndef __LOGQUEUE_H__
#define __LOGQUEUE_H__

#include "data.h"
using namespace std;

// TODO: 把这个类写成单例模式
class LogQueue
{
public:
   LogQueue();      // 初始化条件变量， 条件变量
   ~LogQueue();     // 反初始化条件变量， 条件变量
   LogQueue& operator<<(MLogRec const log);     // 把一条记录存入存储队列
   LogQueue& operator>>(MLogRec& log);          // 从存储队列取出一条记录

private:
   list<MLogRec> m_log;             // 要存储的数据
   pthread_mutex_t m_mtx;           // 互斥量
   pthread_cond_t m_notFull;        // 未满 - 条件变量
   pthread_cond_t m_notEmpty;       // 非空 - 条件变量

   enum { QUEUESIZE = 100}; 
};

#endif  // __LOGQUEUE_H__

