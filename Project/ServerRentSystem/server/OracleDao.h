#ifndef __ORACLEDAO_H__
#define __ORACLEDAO_H__

#include "LogDao.h"
#include <fstream>
class OracleDao : public LogDao
{
public:
   OracleDao(std::string const& user, std::string const& passwd);   // 建立数据库连接
   ~OracleDao();    // 释放数据库连接
   virtual void insert(MLogRec const& log);     // 把数据插入 Oracle 数据库

};

#endif  // __ORACLEDAO_H__
