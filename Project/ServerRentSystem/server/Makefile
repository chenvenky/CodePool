TARGET=server
OBJS=ServerSocket.o LogThread.o ClientThread.o StoreThread.o LogDao.o FileDao.o LogQueue.o Server.o Test-Server.o
$(TARGET):$(OBJS)
	g++ -g $(OBJS) -o $(TARGET) -lpthread 
%.o:%.cpp
	g++ -c -g $< -o $@
clean: 
	cp /dev/null dbFile
	rm *.o 2>/dev/null 
	rm *.h.gch 2>/dev/null
