/*
program9.cpp
Dyllan Uplinger
J633V226
Homework #09
Temperature Work (From File)
Copyright 2017
*/

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::ifstream;

void input(double celsius[][24], int days);
void convert(double celsius[][24], int days);
void showWarmer(double celsius[][24], int days);
double findAverage(double celsius[][24], int days);
void findDailyMaxMinMean(double dayTemps[], double &max, double &min,
                         double &mean);

int main() {
  double celsius[7][24];
  int days = 7;
  double mean, max, min;

  cout.setf(std::ios::fixed);
  cout.setf(std::ios::showpoint);
  cout.precision(2);

  input(celsius, days);
  convert(celsius, days);
  showWarmer(celsius, days);
  cout << "The average temperature over all the days was: "
       << findAverage(celsius, days) << std::endl
       << std::endl;
  cout << "The Maximum, Minimum, and Mean Temperatures for each day:"
       << std::endl
       << std::endl;
  for (int day = 0; day < days; day++) {
    findDailyMaxMinMean(celsius[day], max, min, mean);
    cout << "Day " << day + 1 << ": Max " << max << " C, Min " << min
         << " C, Mean " << mean << " C" << std::endl;
  }
  return 0;
}

void input(double celsius[][24], int days) {
  ifstream fin;
  fin.open("temperature.dat");
  if (fin.fail()) {
    cout << "Failed to open input file. Exiting.... \n";
    exit(1);
  }
  while (!(fin.eof())) {
    for (int day = 0; day < days; day++) {
      for (int hour = 0; hour < 24; hour++) {
        fin >> celsius[day][hour];
      }
    }
    fin.close();
  }
}
void convert(double celsius[][24], int days) {
  for (int day = 0; day < days; day++) {
    for (int hour = 0; hour < 24; hour++) {
      celsius[day][hour] = ((celsius[day][hour] - 32) * 5 / 9);
    }
  }
}
void showWarmer(double celsius[][24], int days) {
  double cutoff = 0;
  cout << "Enter the value for which to find warmer temperatures (C): ";
  cin >> cutoff;
  cout << std::endl
       << "Times at which termperatures warmer than " << cutoff
       << " C were found:" << std::endl
       << std::endl;
  for (int day = 0; day < days; day++) {
    for (int hour = 0; hour < 24; hour++) {
      if (celsius[day][hour] > cutoff)
        cout << "At day " << day + 1 << ","
             << " hour " << hour + 1 << ","
             << " the temp was " << celsius[day][hour] << " C" << std::endl;
    }
  }
  cout << std::endl;
}
double findAverage(double celsius[][24], int days) {
  double total = 0;
  for (int day = 0; day < days; day++) {
    for (int hour = 0; hour < 24; hour++) {
      total += celsius[day][hour];
    }
  }
  return (total / (days * 24));
}
void findDailyMaxMinMean(double dayTemps[], double &max, double &min,
                         double &mean) {
  mean = 0;
  max = dayTemps[0];
  min = dayTemps[0];
  for (int hour = 0; hour < 24; hour++) {
    if (max < dayTemps[hour]) {
      max = dayTemps[hour];
    }
    if (min > dayTemps[hour]) {
      min = dayTemps[hour];
    }
    mean += dayTemps[hour];
  }
  mean = mean / 24;
}
