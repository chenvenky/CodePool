#include "LogSender.h"
#include "LogReader.h"
#include "Client.h"


Client::Client(LogReader& reader, LogSender& sender) : m_reader(reader), m_sender(sender)
{

}


Client::~Client()
{

}


void Client::dataMine() throw(ClientException)
{
   list<MLogRec> logs = m_reader.readLog(); 
   m_sender.sendLog(logs); 

}

