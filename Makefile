CFLAGS=--std=c++2a -g -Wall

all: main

main: main.cpp server.cpp
	g++ $(CFLAGS) -o main main.cpp server.cpp

clean:
	rm main && rm -r *.o