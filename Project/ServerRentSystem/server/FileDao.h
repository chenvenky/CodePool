#ifndef __FILEDAO_H__
#define __FILEDAO_H__

#include "LogDao.h"
#include <fstream>

class FileDao : public LogDao
{
public:
   FileDao(std::string const& dbFile);  // 初始化 文件输出流
   ~FileDao();                          // 关闭 文件输出流
   void insert(MLogRec const& log);     // 把数据写入数据文件 

private:
   ofstream m_ofs;      // 文件输出流
};

#endif  // __FILEDAO_H__
