#include "StoreThread.h"

StoreThread::StoreThread(LogDao &dao) : m_dao(dao)
{

}

StoreThread::~StoreThread()
{
   // TODO : implement
}

// 从存储队列中取出数据，交给 dao
void StoreThread::run(void)
{
   // TODO : implement
}
