CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

PA01 : PA01.o LinkedList.o Node.o PrecondViolatedExcep.o
	$(CC) $(LFLAGS) -std=c++11 PrecondViolatedExcep.o Node.o LinkedList.o PA01.o -o PA01

PA01.o : LinkedList.cpp PA01.cpp
	$(CC) $(CFLAGS) -std=c++11 PA01.cpp

LinkedList.o : LinkedList.h LinkedList.cpp ListInterface.h PrecondViolatedExcep.cpp
	$(CC) $(CFLAGS) -std=c++11 LinkedList.cpp
	
PrecondViolatedExcep.o : PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	$(CC) $(CFLAGS) -std=c++11 PrecondViolatedExcep.cpp
	
Node.o : Node.h Node.cpp
	$(CC) $(CFLAGS) -std=c++11 Node.cpp

clean:
	\rm *.o PA01
