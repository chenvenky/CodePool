#ifndef __CLIENT_H__
#define __CLIENT_H__


#include "LogReader.h"
#include "LogSender.h"
#include "ClientException.h"
class LogSender;
class LogReader;

class Client
{
public:
   Client(LogReader& reader, LogSender& sender);
   ~Client();
   void dataMine() throw(ClientException); 

private:
   LogReader& m_reader;
   LogSender& m_sender;
};

#endif      // __CLIENT_H__
