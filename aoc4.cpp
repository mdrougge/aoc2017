#include "aoc4.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

namespace aoc4 {

  std::vector<std::vector<std::string>>
  loadInput(std::istream & is) {
    std::vector<std::vector<std::string>> result{};
    std::string line;
    while (std::getline(is, line)) {
      std::stringstream ss(line);
      std::string token{};
      std::vector<std::string> set{};
      while (std::getline(ss, token, ' ')) {
	set.push_back(token);
      }
      result.push_back(set);
    }
    return result;
  }

  void
  solve(int argc, char** argv) {
    solvePart1(argc, argv);
    solvePart2(argc, argv);
  }

  /*
    --- Day 4: High-Entropy Passphrases ---
    
    A new system policy has been put in place that requires all accounts to use
    a passphrase instead of simply a password. A passphrase consists of a
    series of words (lowercase letters) separated by spaces.
    
    To ensure security, a valid passphrase must contain no duplicate words.
    
    For example:
    
    aa bb cc dd ee is valid.
    aa bb cc dd aa is not valid - the word aa appears more than once.
    aa bb cc dd aaa is valid - aa and aaa count as different words.

    The system's full passphrase list is available as your puzzle input.
    How many passphrases are valid?
  */

  void
  solvePart1(int argc, char** argv) {
    std::ifstream ifs("aoc4.input");
    std::vector<std::vector<std::string>> data = loadInput(ifs);

    int valid = 0;
    std::vector<std::vector<std::string>>::iterator passwords = data.begin();
    while (passwords != data.end()) {
      std::set<std::string> tokens{};
      for (std::string t : *passwords) {
	tokens.insert(t);
      }

      if (tokens.size() == (*passwords).size()) {
	valid++;
      }
      passwords++;
    }
    
    std::printf("04 P 1: %d\n", valid);
  }
  
  /*
   */
  void
  solvePart2(int argc, char** argv) {
    std::ifstream is("aoc2-1.input");


    std::printf("04 P 2: TBD\n");
  }
}
