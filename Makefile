CC = clang++
CC_FLAGS = -O2 -std=c++11
LD = clang++
LD_FLAGS =

OBJECTS = main.o one.o
TARGET = aoc

all: $(OBJECTS)
	$(LD) -o $(TARGET) $(OBJECTS)

one.o: one.cpp one.h
	$(CC) $(CC_FLAGS) -c one.cpp

main.o: main.cpp one.h
	$(CC) $(CC_FLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET)
