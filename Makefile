CC=g++
CFLAGS=-Ofast -march=native -mtune=native -std=c++11
LDFLAGS=-lm
EXEC=lsm

all: sm

sm: sm.hpp
	$(CC) $(CFLAGS) -c sm.hpp $(LDFLAGS)

main: main.cpp sm.hpp
	$(CC) $(CFLAGS) main.cpp $(LDFLAGS) -o $(EXEC)

test: test.cpp
	$(CC) $(CFLAGS) test.cpp $(LDFLAGS) -o test
	$(info Test file is compiled to ./test)
clean:
	rm -vf *.o *.so *.gch $(EXEC)
