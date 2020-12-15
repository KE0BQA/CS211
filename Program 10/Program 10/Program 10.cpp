/*
program10.cpp
Dyllan Uplinger
J633V226
Homework #10
Postal Code
Copyright 2017
*/

#include <fstream>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::ofstream;
using std::stoi;
using std::string;

struct Zipcode {
  int romanZipcode;
  string postnetCode;
};

Zipcode fillZipcode(const string zip);
string romanToPOSTNET(const int r);
int postnetToRoman(const string p);
void printRomanZip(const Zipcode zip);
void printPOSTNET(const Zipcode zip);
void writeToFile(const Zipcode zip);
void processZip(int prompt);
int main() {
  int mainMenu;
  cout << "This program is able to convert zip codes to a POSTNET format "
    << "and vice versa\n"
    << "\t1. Convert zip code to POSTNET\n"
    << "\t2. Convert POSTNET to zip code\n"
    << "\t3. Quit\n";
  do {
    cout << "Please make your selection: ";
    cin >> mainMenu;
    switch (mainMenu) {
    case 1:
    case 2:
      processZip(mainMenu);
      break;
    default:
      if (mainMenu != 3)
        cout << "Invalid choice...\n";
      else
        cout << "\n";
    }
  } while (mainMenu != 3);
  return 0;
}

Zipcode fillZipcode(const string zip) {
  Zipcode fill;
  auto length = zip.length();
  switch (length) {
  case 5:
    fill.romanZipcode = stoi(zip);
    fill.postnetCode = romanToPOSTNET(stoi(zip));
    break;
  case 25:
    fill.postnetCode = zip;
    fill.romanZipcode = postnetToRoman(zip);
    break;
  }
  return fill;
}
string romanToPOSTNET(const int r) {
  string postnet;
  string zip = std::to_string(r);
  for (int i = 0; i < 5; i++) {
    switch (zip[i]) {
    case '0':
      postnet += "11000";
      break;
    case '1':
      postnet += "00011";
      break;
    case '2':
      postnet += "00101";
      break;
    case '3':
      postnet += "00110";
      break;
    case '4':
      postnet += "01001";
      break;
    case '5':
      postnet += "01010";
      break;
    case '6':
      postnet += "01100";
      break;
    case '7':
      postnet += "10001";
      break;
    case '8':
      postnet += "10010";
      break;
    case '9':
      postnet += "10100";
      break;
    }
  }
  return postnet;
}
int postnetToRoman(const string p) {
  string roman;
  for (int i = 0; i < 5; i++) {
    string breakDown;
    breakDown = p.substr(5 * i, 5);
    if (breakDown == "11000") {
      roman += '0';
    }
    else if (breakDown == "00011") {
      roman += '1';
    }
    else if (breakDown == "00101") {
      roman += '2';
    }
    else if (breakDown == "00110") {
      roman += '3';
    }
    else if (breakDown == "01001") {
      roman += '4';
    }
    else if (breakDown == "01010") {
      roman += '5';
    }
    else if (breakDown == "01100") {
      roman += '6';
    }
    else if (breakDown == "10001") {
      roman += '7';
    }
    else if (breakDown == "10010") {
      roman += '8';
    }
    else if (breakDown == "10100") {
      roman += '9';
    }
  }
  return stoi(roman);
}
void printRomanZip(const Zipcode zip) {
  cout << "Your zip code is " << zip.romanZipcode
    << ", and the bar code looks like this: " << std::endl;
}
void printPOSTNET(const Zipcode zip) {
  cout << "|";
  for (int i = 0; i < 25; i++) {
    if (zip.postnetCode[i] == '1') {
      cout << "|";
    }
    else {
      cout << " ";
    }
  }
  cout << "|" << std::endl;
  for (int i = 0; i < 27; i++) {
    cout << "|";
  }
  cout << std::endl;
}
void writeToFile(const Zipcode zip) {
  string filename = std::to_string(zip.romanZipcode) + ".txt";
  ofstream outFile(filename);
  outFile << "|";
  for (int i = 0; i < 25; i++) {
    if (zip.postnetCode[i] == '1') {
      outFile << "|";
    }
    else {
      outFile << " ";
    }
  }
  outFile << "|" << std::endl;
  for (int i = 0; i < 27; i++) {
    outFile << "|";
  }
  outFile.close();
  cout << "Your Zip Code was saved in " << zip.romanZipcode << ".txt"
    << std::endl;
}
void processZip(int prompt) {
  Zipcode structure;
  string input;
  if (prompt == 1) {
    cout << "Enter a zip code in roman format (#####): ";
    cin >> input;
  }
  else {
    cout << "Enter a zip code in bar code format(1s and 0s) : ";
    cin >> input;
    input = input.substr(1, 25);
  }
  structure = fillZipcode(input);
  printRomanZip(structure);
  printPOSTNET(structure);
  writeToFile(structure);
}
