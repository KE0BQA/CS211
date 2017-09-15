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

#include <iostream>
#include <iomanip>

using namespace std;

double printToScreen(double loanAmount_2, double interst_2, double payment_2);
double calculateMonthlyInterest(double loanAmount_3, double interest_3);

int main(void) {
  double loanAmount_1;
  double interest_1;
  double payment_1;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "Amount of Loan:\n";
  cin >> loanAmount_1;

  cout << "Interest Rate:\n";
  cin >> interest_1;
  interest_1 = interest_1 / 100;

  cout << "Monthly Payment:\n";
  cin >> payment_1;

  printToScreen(loanAmount_1, interest_1, payment_1);

  cout << "EndP\n";

  return 0;
}

double printToScreen(double loanAmount_2, double interest_2, double payment_2) {
  for (int year = 1; year <= 3; year++) {
      double yearlyPrincipal = 0;
      double yearlyInterest = 0;
      // double yearlyBalance = 0;
      cout << "Year " << year << setw(20);
      cout << "Interest" << setw(25) << "Principal";
      cout << endl;
      cout << setw(10) << "---" << setw(16) << "--------";
      cout << setw(25) << "---------";
      cout << endl;

    for (int month = 1; month <= 12; month++) {
      cout << setw(10) << month;
      cout << setw(16) << calculateMonthlyInterest(loanAmount_2, interest_2);
      cout << setw(25) << (payment_2 - calculateMonthlyInterest(loanAmount_2, interest_2));
      // yearlyBalance = (loanAmount_2);
      yearlyPrincipal = (yearlyPrincipal + (payment_2 - calculateMonthlyInterest(loanAmount_2, interest_2)));
      yearlyInterest = (yearlyInterest + (calculateMonthlyInterest(loanAmount_2, interest_2)));
      loanAmount_2 = (loanAmount_2 + calculateMonthlyInterest(loanAmount_2, interest_2));
      loanAmount_2 = (loanAmount_2 - payment_2);
      cout << endl;
    }

      cout << setw(10) << "---" << setw(16) << "--------";
      cout << setw(25) << "---------" << endl;
      cout << endl;
      cout << "Year " << year << " Totals: ";
      cout << setw(11) << yearlyInterest << setw(25) << yearlyPrincipal <<endl;
      cout << "Remaining Balance at year end:" << setw(21) << loanAmount_2;
      cout << endl <<endl;
  }
  return 0;
}

double calculateMonthlyInterest(double loanAmount_3, double interest_3) {
  double monthlyInterest;
  monthlyInterest = (loanAmount_3 * (interest_3/12));
  return monthlyInterest;
}
