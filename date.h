#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;
    int daysinMonth[13] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    Date(int m, int d, int y); // Constructor declaration

    void printNumeric();
    void printMonthDayYear();
    void printDayMonthYear();
    bool isvalidDate(int month, int day, int year);

private:

    string getmonthName(int month);
};

#endif