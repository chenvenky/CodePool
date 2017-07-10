TARGET=client
OBJS=LogReader.o LogSender.o SocketSender.o Test-Client.o Client.o
$(TARGET):$(OBJS)
	g++ -g $(OBJS) -o $(TARGET) 
%.o:%.cpp
	g++ -c -g $< -o $@
clean: 
	rm *.h.gch *.o 2>/dev/null
	rm a.out 2>/dev/null 
