all: print

# print:
# 	g++ main.cpp func1.cpp func2.cpp -o print

print:
	main.o func1.o func2.o
	g++ main.o func1.o func2.o -o print

main.o: main.cpp
	g++ -c main.cpp

func1.o: func1.cpp
	g++ -c func1.cpp

func2.o: func2.cpp
	g++ -c func2.cpp

clean:
	rm -rf *o print

