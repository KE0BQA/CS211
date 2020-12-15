/*
program1.cpp
Dyllan Uplinger
20170831
J633V226
Homework #01
Prompt user for two Numbers and choice of operation; will display results
Copyright 2017
*/

#include <iostream>

using std::cin;
using std::cout;

int main() {
  double firstInteger;
  double secondInteger;
  int operation;
  double finalValue = 0;

  cout << "This Program will prompt for two integers and an operation and then "
    "display the result of applying the operation to the numbers\n";

  cout << "Enter The First Integer:\n";
  cin >> firstInteger;

  cout << "Enter The Second Integer:\n";
  cin >> secondInteger;

  cout << "Available Operations are:\n\t1.) Addition\n\t2.) Subtraction\n\t3.) "
    "Multiplication\n\t4.) Division\nPlease Select a Number:\n";
  cin >> operation;

  // Preventing Divide by 0
  if (operation == 4 && secondInteger == 0) {
    cout << "Can Not Divide by Zero; Program Exiting\n";
    return 0;
  }

  // Preventing Invalid Operations
  if (operation > 4 || operation < 1) {
    cout << " \n Invalid Operation. Valid Choices were 1, 2, 3 or 4. Quitting "
      "Program\n";
    return 0;
  }

  if (operation == 1) {
    finalValue = firstInteger + secondInteger;
    cout << firstInteger << " + " << secondInteger << " = " << finalValue
      << "\n";
    return 0;
  }
  else if (operation == 2) {
    finalValue = firstInteger - secondInteger;
    cout << firstInteger << " - " << secondInteger << " = " << finalValue
      << "\n";
    return 0;
  }
  else if (operation == 3) {
    finalValue = firstInteger * secondInteger;
    cout << firstInteger << " * " << secondInteger << " = " << finalValue
      << "\n";
    return 0;
  }
  else if (operation == 4) {
    finalValue = firstInteger / secondInteger;
    cout << firstInteger << " / " << secondInteger << " = " << finalValue
      << "\n";
    return 0;
  }
  return 0;
}
