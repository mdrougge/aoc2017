#include "aoc.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstring>

/*
  --- Day 3: Spiral Memory ---
  
  You come across an experimental new kind of memory stored on an infinite
  two-dimensional grid.
  
  Each square on the grid is allocated in a spiral pattern starting at a
  location marked 1 and then counting up while spiraling outward. For example,
  the first few squares are allocated like this:
  
  17  16  15  14  13
  18   5   4   3  12
  19   6   1   2  11
  20   7   8   9  10
  21  22  23---> ...
  While this is very space-efficient (no squares are skipped), requested data
  must be carried back to square 1 (the location of the only access port for
  this memory system) by programs that can only move up, down, left, or right.
  They always take the shortest path: the Manhattan Distance between the
  location of the data and square 1.
  
  For example:
  
  Data from square 1 is carried 0 steps, since it's at the access port.
  Data from square 12 is carried 3 steps, such as: down, left, left.
  Data from square 23 is carried only 2 steps: up twice.
  Data from square 1024 must be carried 31 steps.
  
  How many steps are required to carry the data from the square identified in
  your puzzle input all the way to the access port?
 */


/*
  --- Part Two ---
  
  As a stress test on the system, the programs here clear the grid and then
  store the value 1 in square 1. Then, in the same allocation order as shown
  above, they store the sum of the values in all adjacent squares, including
  diagonals.
  
  So, the first few squares' values are chosen as follows:
  
  Square 1 starts with the value 1.
  
  Square 2 has only one adjacent filled square (with value 1), so it also
  stores 1.
  
  Square 3 has both of the above squares as neighbors and stores the sum of
  their values, 2.
  
  Square 4 has all three of the aforementioned squares as neighbors and stores
  the sum of their values, 4.
  
  Square 5 only has the first and fourth squares as neighbors, so it gets the
  value 5.
  
  Once a square is written, its value does not change. Therefore, the first few
  squares would receive the following values:
  
  147  142  133  122   59
  304    5    4    2   57
  330   10    1    1   54
  351   11   23   25   26
  362  747  806--->   ...
  
  What is the first value written that is larger than your puzzle input?
*/

namespace aoc3 {

  struct point {
    int x;
    int y;
  };

  point headTrans[4] =  {
    {0, 1}, {-1, 0}, {0, -1}, {1, 0}
  };

  point cornerTrans[4] = {
    {1,1},{-1,1},{-1,-1}, {1, -1}
  };

  point
  matcher[8] = {
      {-1, 1}, {0, 1}, {1, 1},
      {-1, 0}, {1, 0},
      {-1, -1}, {0, -1}, {1, -1}
  };
  
  void
  solve(int argc, char** argv) {
    solvePart1And2(argc, argv);
  }

  point
  add(point c1, point c2) {
    return point{c1.x + c2.x, c1.y + c2.y};
  }

  point
  multiply(point c1, point c2) {
    return point{c1.x * c2.x, c1.y * c2.y};
  }

  int
  offset(int width, point p) {
    int pivot = (width * width) / 2;
    return (width * p.y + p.x) + pivot;
  }

  point
  offset(int width, int index) {
    int pivot = (width * width) / 2;
    return point{(index - pivot) % width, (index - pivot) / width};
  }

  int
  addChecksum(int side, point & pos, std::vector<int> & mem) {
    int centerIndex = offset(side, pos);
    for (point m : matcher) {
      int i = offset(side, add(pos, m));
      if (i < mem.size()) {
	mem[centerIndex] += mem[i];
      }
    }
    return mem[centerIndex];
  }
  
  point
  alg(int side, std::vector<int> & mem, int index, int & cs) {
    int v = 1;
    int radius = 1;
    point pos{1, - 1};
    bool stopCS = false;
    mem.push_back(v);
    while (v < index) {
      for (int transIndex = 0; transIndex < 4; transIndex++) {
	point corner = multiply(cornerTrans[transIndex], point{radius, radius});
	while ((pos.x != corner.x || pos.y != corner.y) && v < index) {
	  v++;
	  pos = add(pos, headTrans[transIndex]);
	  if (!stopCS) {
	    cs = addChecksum(side, pos, mem);
	    if (cs > index) {
	      stopCS = true;
	    }
	  }
	}
      }
      if (v < index - 1) {
      	radius++;
      	pos = point{pos.x + 1, pos.y};
      	v++;
	if (!stopCS) {
	  cs = addChecksum(side, pos, mem);
	  if (cs > index) {
	    stopCS = true;
	  }
	}
      }
    }
    return pos;
  }

  void
  solvePart1And2(int argc, char** argv) {
    // puzzle input: 265149
    int data = 265149; // expected 438 and for part 2 266330
    int side = (std::sqrt(data) + 1);
    std::vector<int> mem(side * side);
    for (int i = 0; i < side * side; i++) {
      mem.push_back(0);
    }
    mem[offset(side, point{0,0})] = 1;

    int cs = 0;
    point res = alg(side, mem, data, cs);
    int distance = std::abs((-res.x)) + std::abs((-res.y));
 
    std::printf("O3 P1: %d\nO3 P2: %d\n", distance, cs);
  }

}
