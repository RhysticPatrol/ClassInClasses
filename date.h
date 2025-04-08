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
    static const int daysinMonth[13];
    bool valid; // track if date is valid

public:
    Date(int m, int d, int y); // constructor to init date

    void printNumeric() const; // print date numeric
    void printMonthDayYear() const; // print date month day year
    void printDayMonthYear() const; // print date day month year
    bool isValid() const; // check if date is valid

    void setDate(int m, int d, int y); // set the date
private:
    string getMonthName(int month) const; // get month name
    bool isLeapYear(int year) const; // check leap year
    void validateDate(); // validate date
    void normalizeDate(); // adjust date

public:
    Date& operator++(); // prefix increment
    Date operator++(int); // postfix increment
    Date& operator--(); // prefix decrement
    Date operator--(int); // postfix decrement
    int operator-(const Date& other) const; // subtract dates
    friend istream& operator>>(istream& is, Date& date); // input date
    friend ostream& operator<<(ostream& os, const Date& date); // output date
    int dateToDays() const; // convert date to days
};

#endif