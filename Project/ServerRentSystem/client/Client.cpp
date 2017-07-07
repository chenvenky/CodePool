#include "LogSender.h"
#include "LogReader.h"
#include "Client.h"


Client::Client(LogReader& reader, LogSender& sender)
{
   // TODO : implement
}


Client::~Client()
{
   // TODO : implement
}


void Client::dataMine(void)
{
   // TODO : implement
}

int main()
{
	try{
		dataMine();
	}
	catch(ClientException e){
	}
	
	
	return 0;
}
