#include "aoc2.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
namespace aoc2 {

  std::vector<std::vector<int>>
  loadInput(std::istream & is) {
    std::vector<std::vector<int>> result{};
    std::string line{};
    while (std::getline(is, line)) {
      std::vector<int> vc{};
      std::string token{};
      std::stringstream ss{line};
      while (std::getline(ss, token, '\t')) {
	vc.push_back(atoi(token.c_str()));
      }
      result.push_back(vc);
    }
    return result;
  }

  void
  solve(int argc, char** argv) {
    solvePart1(argc, argv);
    solvePart2(argc, argv);
  }

  /*
    --- Day 2: Corruption Checksum ---
    
    As you walk through the door, a glowing humanoid shape yells in your
    direction. "You there! Your state appears to be idle. Come help us repair
    the corruption in this spreadsheet - if we take another millisecond, we'll
    have to display an hourglass cursor!"
    
    The spreadsheet consists of rows of apparently-random numbers. To make sure
    the recovery process is on the right track, they need you to calculate the
    spreadsheet's checksum. For each row, determine the difference between the
    largest value and the smallest value; the checksum is the sum of all of
    these differences.
    
    For example, given the following spreadsheet:
    
    5 1 9 5
    7 5 3
    2 4 6 8
    The first row's largest and smallest values are 9 and 1, and their difference is 8.
    The second row's largest and smallest values are 7 and 3, and their difference is 4.
    The third row's difference is 6.
    In this example, the spreadsheet's checksum would be 8 + 4 + 6 = 18.
  */

  void
  solvePart1(int argc, char** argv) {
    std::ifstream ifs("input/aoc2.in");
    std::vector<std::vector<int>> data = loadInput(ifs);
    int cs = 0;
    std::vector<std::vector<int>>::iterator row = data.begin();
    while (row != data.end()) {
      std::vector<int>::iterator col = (*row).begin();
      int min = *col;
      int max = *col;
      while (col != (*row).end()) {
	min = min > *col ? *col : min;
	max = max < *col ? *col : max;
	col++;
      }
      cs += max - min;
      row++;
    }
    
    std::printf("02 P 1: %d\n", cs);
  }
  
  /*
    --- Part Two ---
    
    "Great work; looks like we're on the right track after all. Here's a star
    for your effort." However, the program seems a little worried. Can programs
    be worried?

    "Based on what we're seeing, it looks like all the User wanted is some
    information about the evenly divisible values in the spreadsheet.
    Unfortunately, none of us are equipped for that kind of calculation - most
    of us specialize in bitwise operations."
    
    It sounds like the goal is to find the only two numbers in each row where
    one evenly divides the other - that is, where the result of the division
    operation is a whole number. They would like you to find those numbers on
    each line, divide them, and add up each line's result.
    
    For example, given the following spreadsheet:
    
    5 9 2 8
    9 4 7 3
    3 8 6 5
    In the first row, the only two numbers that evenly divide are 8 and 2; the result of this division is 4.
    In the second row, the two numbers are 9 and 3; the result is 3.
    In the third row, the result is 2.
    In this example, the sum of the results would be 4 + 3 + 2 = 9.
    
    What is the sum of each row's result in your puzzle input?
   */
  void
  solvePart2(int argc, char** argv) {
    std::ifstream is("input/aoc2.in");
    std::vector<std::vector<int>> data = loadInput(is);

    int cs = 0;
    std::vector<std::vector<int>>::iterator row = data.begin();
    while (row != data.end()) {
      int found = 0;
      for (std::vector<int>::iterator i1 = (*row).begin(); i1 != (*row).end(); i1++) {
	for (std::vector<int>::iterator i2 = (*row).begin(); i2 != (*row).end(); i2++) {
	  if (i1 != i2 && !(*i1 % *i2)) {
	    cs += *i1 / *i2;
	  }
	}
      }
      row++;
    }

    std::printf("02 P 2: %d\n", cs);
  }
}
