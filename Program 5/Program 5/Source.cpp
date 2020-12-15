/*
program5.cpp
Dyllan Uplinger
J633V226
Homework #05
Bingo Array
Copyright 2017
*/

#include <iostream>

using std::cout;

const int SIZE = 5;
const char dog[SIZE] = { 'B', 'I', 'N', 'G', 'O' };

int main() {
  for (int num = 0; num < 6; num++) { // Prints out Total Number of Blocks
    cout << "There was a farmer had a dog" << std::endl << "and ";
    for (int fullName = 0; fullName < 5; fullName++) { // Prints out entire Name
      cout << dog[fullName] << " ";
    }
    cout << " was his name-o" << std::endl;
    for (int row = 0; row < 3; row++) {
      for (int clap = 0; clap < 5; clap++) { // Outputs needed "*"
        if (clap <= (num - 1)) {
          cout << "* ";
        }
        else {
          cout << dog[clap] << " ";
        }
      }
      cout << std::endl;
    }
    cout << "And ";
    for (int fullName = 0; fullName < 5; fullName++) { // Full Name
      cout << dog[fullName] << " ";
    }
    cout << " was his name-o" << std::endl << std::endl;
  }
  return 0;
}
