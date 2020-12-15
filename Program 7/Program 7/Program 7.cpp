/*
program7.cpp
Dyllan Uplinger
J633V226
Homework #07
Bubble Sort
Copyright 2017
*/

/*
Gather 6 Words
Store in string
End if 0 found
Bubble Sort Alphabetic
Print String
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

const int numWords = 10;
void bubbleSort(string[], int);

int main() {
  string words;
  string list[numWords];
  int count = 0;

  cout << "Enter a word: ";
  cin >> words;

  while (words != "0" && count < numWords) {
    list[count++] = words;
    cout << "Enter a word: ";
    cin >> words;
  }
  bubbleSort(list, count);
  cout << "Your Sorted List is: ";
  for (int i = 0; i < count; i++) {
    cout << list[i] << " ";
  }
  cout << std::endl;
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
