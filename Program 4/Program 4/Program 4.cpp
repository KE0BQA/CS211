/*
program4.cpp
Dyllan Uplinger
J633V226
Homework #04
Vending Machine
Copyright 2017
*/

/*
Write Menu
Get Option
Accept Money
Compute Change
Repeat if needed.
*/

#include <cctype>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;

// Displays Menu To Choose From
void writeMenu(void);
// Gets User Selection
int getSelection(int& price);
// Accepts and Sums Money Inserted
int acceptMoney(int price, int& money);
// Returns Change to User
void computeChange(int price, int money);

int main() {
  char repurchase = 0;
  int price = 0;
  int money = 0;

  cout << "Welcome to the Snack Vending Machine \n";
  cout << std::endl;
  do {
    writeMenu();
    getSelection(price);
    acceptMoney(price, money);
    computeChange(price, money);
    cout << std::endl << "Would you care to make another purchase? (Y/N): ";
    cin >> repurchase;
    switch (repurchase) {
    case 'y':
    case 'Y':
      repurchase = 0;
      break;
    default:
      repurchase = 1;
      break;
    }
  } while (repurchase == 0);
  cout << std::endl << "Thank you and enjoy your purchase!" << std::endl;
  return 0;
}

void writeMenu(void) {
  cout << "Avaliable snacks to choose from: \n"
    << "\t P - Potato Chips" << std::setw(10) << "$1.25 \n"
    << "\t S - Snickers Bar" << std::setw(10) << "$1.35 \n"
    << "\t T - Pop Tart" << std::setw(14) << "$0.95 \n"
    << "\t C - Cookies" << std::setw(15) << "$1.50 \n"
    << "\t B - Brownie" << std::setw(15) << "$1.75 \n"
    << "\t N - Nuts" << std::setw(18) << "$1.40 \n";
}

int getSelection(int& price) {
  char selection = 0;
  while (true) { // Runs Until Valid Answer
    cout << "Please Enter the Letter Labeling your Snack Selection: ";
    cin >> selection;
    selection = toupper(selection);
    switch (selection) {
    case 'P':
      price = 125;
      break;
    case 'S':
      price = 135;
      break;
    case 'T':
      price = 95;
      break;
    case 'C':
      price = 150;
      break;
    case 'B':
      price = 175;
      break;
    case 'N':
      price = 140;
      break;
    default:
      cout << "Invalid selection! \n";
      continue;
    }
    break;
  }
  return price;
}

int acceptMoney(int price, int& money) {
  char moneySelection = 0;
  money = 0; // Reset Money Every Run
  cout << std::endl;
  cout << "Money Accepted by the Machine \n"
    << "\t N - Nickel \n"
    << "\t Q - Quarter \n"
    << "\t D - Dollar \n";
  while (money < price) {
    cout << std::endl
      << "Your Selected Item Cost: " << price << std::setw(3) << " CENTS"
      << std::endl
      << "Your Total Inserted: " << std::setw(7) << money << std::setw(6)
      << " CENTS" << std::endl
      << "Insert amount (enter letter of choice): ";
    cin >> moneySelection;
    moneySelection = toupper(moneySelection);
    switch (moneySelection) {
    case 'N':
      money += 5;
      break;
    case 'Q':
      money += 25;
      break;
    case 'D':
      money += 100;
      break;
    default:
      cout << moneySelection << " is not recognized as a coin\n";
      continue;
    }
  }
  return money;
}

void computeChange(int price, int money) {
  cout << std::endl
    << "Your Total Inserted: " << std::setw(7) << money << std::setw(6)
    << " CENTS" << std::endl
    << "Dispensing Change: " << std::setw(9) << money - price << std::setw(6)
    << " CENTS" << std::endl;
}
