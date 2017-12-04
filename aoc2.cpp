/*
 */

/*
 */

#include "aoc2.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

namespace aoc2 {
  
  
  std::vector<int>
  convert(std::string str) {
    char tmp[] = "0";
    std::vector<int> res{};
    std::string::iterator it = str.begin();
    while (it != str.end()) {
      tmp[0] = *it;
      res.push_back(atoi(tmp));
      it++;
    }
    return res;
  }
  
  void
  solve(int argc, char** argv) {
    solvePart1(argc, argv);
    solvePart2(argc, argv);
  }
  
  void
  solvePart1(int argc, char** argv) {
    std::printf("02 P 1: TBD\n");
  }
  
  /*
   */
  void
  solvePart2(int argc, char** argv) {
    std::printf("02 P 2: TBD\n");
  }
}
