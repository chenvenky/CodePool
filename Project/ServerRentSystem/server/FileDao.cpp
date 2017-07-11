#include "FileDao.h"

// 初始化 文件输出流
FileDao::FileDao(std::string const& dbFile) : m_ofs(dbFile.c_str()) 
{
    if(!m_ofs)
        throw FileException("把数据保存到 数据库文件时： 文件 " + dbFile + "无法打开"); 
}


// 关闭 文件输出流
FileDao::~FileDao()
{
    m_ofs.close(); 
}


// 把数据写入数据文件
void FileDao::insert(MLogRec const& log)
{
    m_ofs   << log.logname << " " << log.logintime << " " << log.logouttime << " "
            << log.durations << " " << log.logip << endl; 
}
