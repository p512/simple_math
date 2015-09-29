CC=g++
STD=c++11
CFLAGS=-Ofast -march=native -mtune=native -Wall -Wextra -Wpedantic -std=$(STD)
CDEBUG=-O0 -g -std=$(STD)
LDFLAGS=-lm
EXEC=lsm

all: sm

sm: sm.hpp
	$(CC) $(CFLAGS) -c sm.hpp $(LDFLAGS)

main: main.cpp sm.hpp
	$(CC) $(CFLAGS) main.cpp $(LDFLAGS) -o $(EXEC)

test: sm.hpp test.cpp
	$(CC) $(CDEBUG) test.cpp $(LDFLAGS) -o test
	$(info Test file is compiled to ./test)

acc: sm.hpp accuracy.cpp
	$(CC) $(CFLAGS) accuracy.cpp $(LDFLAGS) -o acc

clean:
	rm -vf *.o *.so *.gch $(EXEC)
