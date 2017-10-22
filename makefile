CXXFLAGS += -std=c++11 
CC = g++ 

test: test.o mdatapub.o
	$(CC) $(CXXFLAGS) -o test test.o mdatapub.o

test.o: test.cpp broadcaster.h mdatapub.h
	$(CC) $(CXXFLAGS) -c test.cpp

mdatapub.o : mdatapub.cpp mdatapub.h
	$(CC) $(CXXFLAGS) -c mdatapub.cpp

clean :
	rm test test.o mdatapub.o
