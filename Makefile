CC = clang++
CC_FLAGS = -O2 -std=c++11
LD = clang++
LD_FLAGS =

OBJECTS = main.o aoc1.o aoc2.o
TARGET = aoc

all: $(OBJECTS)
	$(LD) -o $(TARGET) $(OBJECTS)

aoc1.o: aoc1.cpp aoc1.h
	$(CC) $(CC_FLAGS) -c aoc1.cpp

aoc2.o: aoc2.cpp aoc2.h
	$(CC) $(CC_FLAGS) -c aoc2.cpp

main.o: main.cpp
	$(CC) $(CC_FLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET)
