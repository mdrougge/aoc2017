
all: one.o main.o
	clang++ -O2 -o aoc one.o main.o

one.o: one.cpp one.h
	clang++ -O2 -c -std=c++11 one.cpp

main.o: main.cpp
	clang++ -O2 -c -std=c++11 main.cpp

clean:
	rm *.o

