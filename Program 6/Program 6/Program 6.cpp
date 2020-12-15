/*
program6.cpp
Dyllan Uplinger
J633V226
Homework #06
Caesar Shift
Copyright 2017
*/

#include <cctype>
#include <iostream>

using std::cin;
using std::cout;

void printEntry(char a[], int size); // Print Message
void encrypt(char a[], int size);    // Apply Shift
void decrypt(char a[], int size);    // Remove Shift

const int size = 200;
int shift = 4;

int main() {
  char message[size], letter;
  int count = 0;

  cout << "Please enter a message (200 Character Limit): ";
  cin.get(letter);
  while (letter != '\n' && count < size) { // Check to not exceed the array
    message[count] = letter;
    count++;
    cin.get(letter);
  }
  for (int i = 0; i < count; i++) { // Convert to Uppercase
    message[i] = toupper(message[i]);
  }
  printEntry(message, count);
  encrypt(message, count);
  decrypt(message, count);

  return 0;
}

void printEntry(char a[], int size) {
  for (int i = 0; i < size; i++) {
    cout << a[i];
  }
  cout << std::endl;
}
void encrypt(char a[], int size) {
  for (int i = 0; i < size; i++) {
    if (a[i] != ' ') {
      if (a[i] < 'W') {
        a[i] += shift;
      }
      else {
        a[i] -= 22;
      }
    }
  }
  printEntry(a, size);
}
void decrypt(char a[], int size) {
  for (int i = 0; i < size; i++) {
    if (a[i] != ' ') {
      if (a[i] > 'D') {
        a[i] -= shift;
      }
      else {
        a[i] += 22;
      }
    }
  }
  printEntry(a, size);
}
