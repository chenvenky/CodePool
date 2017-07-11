#include "LogQueue.h"

// 初始化互斥量，条件变量
LogQueue::LogQueue()
{
    m_mtx = PTHREAD_MUTEX_INITIALIZER; 
    m_notFull = PTHREAD_COND_INITIALIZER; 
    m_notEmpty = PTHREAD_COND_INITIALIZER; 
}


// 如果动态分配，反初始化互斥量，条件变量
LogQueue::~LogQueue()
{
   
}

// 把一条记录放入存储队列
LogQueue& LogQueue::operator<<(MLogRec const log)
{
   pthread_mutex_lock(&m_mtx); 
   while(m_log.size() >= 100)
   {
       pthread_cond_wait(&m_notFull, &m_mtx); 
   }
   m_log.push_back(log); 
   pthread_cond_broadcast(&m_notEmpty); 
   pthread_mutex_unlock(&m_mtx); 

   return *this; 
}


// 从存储队列中取出一条记录
LogQueue& LogQueue::operator>>(MLogRec& log)
{
    pthread_mutex_lock(&m_mtx); 
    while(m_log.size() == 0)
    {
        pthread_cond_wait(&m_notEmpty, &m_mtx); 
    }
    
    log = m_log.front(); 
    m_log.pop_front(); 

    pthread_cond_broadcast(&m_notFull); 
    pthread_mutex_unlock(&m_mtx); 

    return *this; 
}

LogQueue logQu; 
