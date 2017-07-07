#ifndef __CLIENTEXCEPTION_H__
#define __CLIENTEXCEPTION_H__
#include <iostream>
using namespace std;
class ClientException:public exception
{
	private:
		string m_msg;
	public:
		ClientException():m_msg("客户机异常"){}
		ClientException(string const& msg):m_msg("客户机异常")
    	{
		    m_msg += msg;
		    m_msg += "!";
	    }
		virtual ~ClientException()throw(){}
		char const* what()throw()
		{
			return m_msg.c_str();
		}
};

class BackupException:public ClientException
{
	public:
		BackupException():ClientException("备份异常"){}
		BackupException(string const& msg):ClientException(msg){}
};

class SendException:public ClientException
{
	public:
		SendException():ClientException("发送数据异常"){}
};

class ReadException:public ClientException
{
	public:
		ReadException():ClientException("读取日志文件异常"){}
		ReadException(string const& msg):ClientException(msg){}
};

class SocketException:public ClientException
{
	public:
		SocketException():ClientException("建立网络连接异常"){}
		SocketException(string const& msg):ClientException(msg){}
};

class SaveException:public ClientException
{
	public:
		SaveException():ClientException("保存日志文件异常"){}
		SaveException(string const& msg):ClientException(msg){}
};
#endif  // _CLIENTEXCEPTION_H__
