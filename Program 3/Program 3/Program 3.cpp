/*
program3.cpp
Dyllan Uplinger
J633V226
Homework #03
Calculate Loan Information
Copyright 2017
*/

/*
1. Gather Loan Amount Interest and Monthly Payment
2. Calculate Monthly Interest
3. Calculate Monthly Principle
4. Subtract Principal from Balance
5. Repeat Every Month x12
6. Calculate Total Yearly Interest
7. Calculate Total Monthly Interest
8. Calculate Total Yearly Balance Remaining
9. Repeat Every Year x3
*/

#include <iomanip>
#include <iostream>

using std::cout;

int main() {
  double loanAmount = 0;
  double loanInterest = 0;
  double monthlyPayment = 0;
  double monthlyInterest = 0;

  cout.setf(std::ios::fixed);
  cout.setf(std::ios::showpoint);
  cout.precision(2);

  cout << "Amount of Loan:\n";
  std::cin >> loanAmount;

  cout << "Interest Rate:\n";
  std::cin >> loanInterest;
  loanInterest = (loanInterest / 100); // Changes interest to decimal

  cout << "Monthly Payment:\n";
  std::cin >> monthlyPayment;

  for (int year = 1; year <= 3; year++) { // Creates 3 Years
    double yearlyInterest = 0;            // Both Vars Need to Reset Every Year
    double yearlyPrincipal = 0;
    cout << "Year " << year;
    cout << std::setw(20) << "Interest" << std::setw(25) << "Principal"
      << std::endl;
    cout << std::setw(10) << "---" << std::setw(16) << "--------"
      << std::setw(25) << "---------" << std::endl;
    for (int month = 1; month <= 12; month++) { // Creates 12 Months per year
      monthlyInterest = (loanAmount * (loanInterest / 12));
      yearlyPrincipal += (monthlyPayment - monthlyInterest);
      yearlyInterest += monthlyInterest;
      cout << std::setw(9) << month << ":" << std::setw(16) << monthlyInterest
        << std::setw(25) << (monthlyPayment - monthlyInterest);
      loanAmount += monthlyInterest;
      loanAmount -= monthlyPayment;
      cout << std::endl;
    }
    cout << std::setw(10) << "---" << std::setw(16) << "--------"
      << std::setw(25) << "---------" << std::endl;
    cout << "Year " << year << " Totals: " << std::setw(11) << yearlyInterest
      << std::setw(25) << yearlyPrincipal << std::endl;
    cout << "Remaining Balance at year end:";
    cout << std::setw(21) << loanAmount;
    cout << std::endl;
    cout << std::endl;
  }
  return 0;
}
