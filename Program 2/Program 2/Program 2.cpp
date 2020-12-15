/*
program2.cpp
Dyllan Uplinger
J633V226
Homework #02
Draw to the terminal 3 shapes
Copyright 2017
*/

#include <cmath>
#include <iostream>

using std::cout;

int main() {
  // Triangle
  for (int row = 0; row <= 4; row++) {
    for (int width = row; width > 0; width--) {
      cout << " ";
    }
    for (int height = (2 * (4 - row)); height >= 1; height--) {
      cout << "#";
    }
    cout << std::endl;
  }
  // Triangle

  cout << "\n";

  // Diamond
  for (int row = 7; row >= 1; row--) {
    for (int width = (abs(4 - row)); width > 0; width--) {
      cout << " ";
    }
    for (int height = (2 * (4 - abs(4 - row))); height >= 1; height--) {
      cout << "#";
    }
    cout << std::endl;
  }
  // Diamond

  cout << "\n\n";

  // X-Shape
  int e = 0, f = 0, NUM2 = 3;

  for (e = -NUM2; e <= NUM2; e++) {
    for (f = -NUM2; f <= NUM2; f++) {
      if ((abs(e) == abs(f))) {
        cout << "#";
      }
      else {
        cout << " ";
      }
    }
    cout << std::endl;
  }

  return 0;
}
