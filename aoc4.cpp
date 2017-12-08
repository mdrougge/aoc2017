#include "aoc.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <cstring>

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
    std::ifstream ifs("input/aoc4.in");
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
    --- Part Two ---
    
    For added security, yet another system policy has been put in place.
    Now, a valid passphrase must contain no two words that are anagrams
    of each other - that is, a passphrase is invalid if any word's
    letters can be rearranged to form any other word in the passphrase.
    
    For example:
    
    abcde fghij is a valid passphrase.
    abcde xyz ecdab is not valid - the letters from the third word can be rearranged to form the first word.
    a ab abc abd abf abj is a valid passphrase, because all letters need to be used when forming another word.
    iiii oiii ooii oooi oooo is valid.
    oiii ioii iioi iiio is not valid - any of these words can be rearranged to form any other word.

    Under this new system policy, how many passphrases are valid?
   */

  int
  cmp(const void* m1, const void* m2) {
    return *((const char*) m1) - *((const char*) m2);
  }
  
  
  void
  solvePart2(int argc, char** argv) {
    std::ifstream ifs("input/aoc4.in");
    std::vector<std::vector<std::string>> data = loadInput(ifs);
    
    int valid = 0;
    std::vector<std::vector<std::string>>::iterator passwords = data.begin();
    while (passwords != data.end()) {
      std::set<std::string> tokens{};
      for (std::string t : *passwords) {
	char tmp[t.size()];
	std::strcpy(tmp, t.c_str());
	
	std::qsort(tmp, t.size(), sizeof(char), cmp);
	tokens.insert(std::string{tmp});
      }

      if (tokens.size() == (*passwords).size()) {
	valid++;
      }
      passwords++;
    }
    
    std::printf("04 P 2: %d\n", valid);
  }
}
