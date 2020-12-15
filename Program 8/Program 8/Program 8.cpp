/*
program8.cpp
Dyllan Uplinger
J633V226
Homework #08
Bubble Sort (Dynamic Bubble Sort)
Copyright 2017
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

void bubbleSort(string[], int);

int main() {
  int count = 0;

  cout << "Enter Size: ";
  cin >> count;
  string* list = new string[count];

  for (int i = 0; i < count; i++) {
    cout << "Enter a Word: ";
    cin >> list[i];
  }
  bubbleSort(list, count);
  cout << "Your Sorted List is: ";
  for (int i = 0; i < count; i++) {
    cout << list[i] << " ";
  }
  cout << std::endl;
  delete[] list;
  return 0;
}
void bubbleSort(string words[], int num) {
  for (int i = 0; i < (num - 1); i++) {
    for (int j = 0; j < (num - i - 1); j++)
      if (words[j] > words[j + 1]) {
        swap(words[j], words[j + 1]);
      }
  }
}
