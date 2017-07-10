TARGET=client
OBJS=LogReader.o LogSender.o SocketSender.o Test-Client.o Client.o
$(TARGET):$(OBJS)
	g++ -g $(OBJS) -o $(TARGET) 
%.o:%.cpp
	g++ -c -g $< -o $@

clean: 
	rm wtmpx.* 2>/dev/null 
	rm *.o 2>/dev/null
	rm *.h.gch 2>/dev/null
	rm a.out 2>/dev/null

debug:
	cp wtmpx.* wtmpx
	cat /dev/null > loginsFile
	cat /dev/null > failFile
