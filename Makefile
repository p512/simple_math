CC=g++
CFLAGS=-Ofast -march=native -mtune=native -std=c++11
LDFLAGS=-lm
EXEC=lsm

all: sm

sm: sm.hpp
	$(CC) $(CFLAGS) -c sm.hpp $(LDFLAGS)

main: main.cpp sm
	$(CC) $(CFLAGS) main.cpp $(LDFLAGS) -o $(EXEC)

clean:
	rm -f *.o
	rm -f *.so
