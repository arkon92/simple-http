CFLAGS=--std=c++2a

all: main.o

main.o: main.cpp
	g++ $(CFLAGS) main.cpp -o main.o
