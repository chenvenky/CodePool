TARGET=client
OBJS=LogReader.o LogSender.o SocketSender.o Test-Client.o Client.o
$(TARGET):$(OBJS)
	g++ -g $(OBJS) -o $(TARGET) 
%.o:%.cpp
	g++ -c -g $< -o $@
clean: 
	rm -f wtmpx.* 2>/dev/null 
	rm -f *.o 2>/dev/null
	rm -f *.h.gch 2>/dev/null
	rm -f a.out 2>/dev/null

debug:
	cp wtmpxBackup wtmpx
	cat /dev/null > loginsFile
	cat /dev/null > failFile
	make clean
