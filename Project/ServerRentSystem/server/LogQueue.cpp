#include "LogQueue.h"

// 初始化互斥量，条件变量
LogQueue::LogQueue()
{
}


// 反初始化互斥量，条件变量
LogQueue::~LogQueue()
{
   // TODO : implement
}

// 把一条记录放入存储队列
LogQueue& LogQueue::operator<<(MLogRec const log)
{
   // TODO : implement
}


// 从存储队列中取出一条记录
LogQueue& LogQueue::operator>>(MLogRec& log)
{
   // TODO : implement
}
