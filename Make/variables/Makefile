# declare variables
CC=g++

CFLAGS=-c -Wall

print:
	main.o func1.o func2.o
	$(CC) main.o func1.o func2.o -o print

main.o: main.cpp
	$(CC) -c main.cpp

func1.o: func1.cpp
	$(CC) -c func1.cpp

func2.o: func2.cpp
	$(CC)-c func2.cpp

clean:
	rm -rf *o print

