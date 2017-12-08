CC = clang++
CC_FLAGS = -O2 -std=c++11
LD = clang++
LD_FLAGS =

OBJECTS = main.o aoc1.o aoc2.o aoc3.o aoc4.o aoc5.o
TARGET = aoc

all: $(OBJECTS)
	$(LD) -o $(TARGET) $(OBJECTS)

aoc1.o: aoc1.cpp aoc.h
	$(CC) $(CC_FLAGS) -c aoc1.cpp

aoc2.o: aoc2.cpp aoc.h
	$(CC) $(CC_FLAGS) -c aoc2.cpp

aoc3.o: aoc3.cpp aoc.h
	$(CC) $(CC_FLAGS) -c aoc3.cpp

aoc4.o: aoc4.cpp aoc.h
	$(CC) $(CC_FLAGS) -c aoc4.cpp

aoc5.o: aoc5.cpp aoc.h
	$(CC) $(CC_FLAGS) -c aoc5.cpp

main.o: main.cpp aoc.h
	$(CC) $(CC_FLAGS) -c main.cpp

clean:
	rm -f *.o *~ $(TARGET)
