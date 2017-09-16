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
  2. Calulate Monthly Interest
  3. Calculate Monthly Principle
  4. Subtract Principal from Balance
  5. Repeat
  6. Calculate Total Yearly Interest
  7. Calculate Total Monthly Interest
  8. Calculate Total Yearly Balance Remaining
*/

#include <iomanip>
#include <iostream>

// using namespace std;
using std::cout;
using std::cin;
using std::setw;

double printToScreen(double loanAmount_2, double interst_2, double payment_2);
double calculateMonthlyInterest(double loanAmount_3, double interest_3);

int main() {
  double loanAmount_1;
  double interest_1;
  double payment_1;

  cout.setf(std::ios::fixed);
  cout.setf(std::ios::showpoint);
  cout.precision(2);

  cout << "Amount of Loan:\n";
  cin >> loanAmount_1;

  cout << "Interest Rate:\n";
  cin >> interest_1;
  interest_1 = interest_1 / 100;

  cout << "Monthly Payment:\n";
  cin >> payment_1;

  printToScreen(loanAmount_1, interest_1, payment_1);

  return 0;
}

double printToScreen(double loanAmount_2, double interest_2, double payment_2) {
  for (int year = 1; year <= 3; year++) {
    double yearlyPrincipal = 0;
    double yearlyInterest = 0;
    cout << "Year " << year << setw(20) << "Interest" << setw(25)
         << "Principal";
    cout << std::endl;
    cout << setw(10) << "---" << setw(16) << "--------" << setw(25)
         << "---------";
    cout << std::endl;
    for (int month = 1; month <= 12; month++) {
      cout << setw(10) << month << setw(16)
           << calculateMonthlyInterest(loanAmount_2, interest_2) << setw(25)
           << (payment_2 - calculateMonthlyInterest(loanAmount_2, interest_2));
      yearlyPrincipal +=
          (payment_2 - calculateMonthlyInterest(loanAmount_2, interest_2));
      yearlyInterest += (calculateMonthlyInterest(loanAmount_2, interest_2));
      loanAmount_2 += calculateMonthlyInterest(loanAmount_2, interest_2);
      loanAmount_2 -= payment_2;
      cout << std::endl;
    }
    cout << setw(10) << "---" << setw(16) << "--------" << setw(25)
         << "---------" << std::endl;
    cout << "Year " << year << " Totals: " << setw(11) << yearlyInterest
         << setw(25) << yearlyPrincipal;
    cout << std::endl;
    cout << "Remaining Balance at year end:";
    cout << setw(21) << loanAmount_2;
    cout << std::endl;
    cout << std::endl;
  }
  return 0;
}

double calculateMonthlyInterest(double loanAmount_3, double interest_3) {
  double monthlyInterest;
  monthlyInterest = (loanAmount_3 * (interest_3 / 12));
  return monthlyInterest;
}
