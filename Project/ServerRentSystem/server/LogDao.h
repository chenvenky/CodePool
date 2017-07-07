#ifndef __LOGDAO_H__
#define __LOGDAO_H__

#include <iostream>
#include "data.h"

using namespace std;

class LogDao
{
public:
   virtual void insert(MLogRec const& log) = 0;     // 为插入数据提供统一的抽象接口
   virtual ~LogDao();                               
};

#endif  // __LOGDAO_H__
