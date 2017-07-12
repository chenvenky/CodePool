TARGET=server
OBJS=ServerSocket.o LogThread.o ClientThread.o StoreThread.o LogDao.o OracleDao.o FileDao.o LogQueue.o Server.o Test-Server.o
$(TARGET):$(OBJS)
	g++ -g $(OBJS) -o $(TARGET) -lpthread -lclntsh
%.o:%.cpp
	g++ -c -g $< -o $@ -std=c++0x
OracleDao.cpp:OracleDao.pc
	proc OracleDao.pc oname=OracleDao.cpp code=cpp parse=none
debug: 
	cp /dev/null dbFile
	rm -f tp* *.lis OracleDao.cpp
	rm -f *.o 2>/dev/null 
	rm -f *.h.gch 2>/dev/null
