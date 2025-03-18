#include "date.h"
#include <iostream>
#include <iomanip>

using namespace std;

Date::Date(int m, int d, int y) : month(m), day(d), year(y) { //alligning variables and adjusting feb.
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysinMonth[2] = 29;
        } else {
            daysinMonth[2] = 28;
        }
    }
}

void Date::printNumeric() { //print date in 12/25/0000 format
    cout << setw(2) << month << "/"
         << setw(2) << day << "/"
         << year;
}

void Date::printMonthDayYear() { //print in December 25, 0000 format
    cout << getmonthName(month) << " " << day << ", " << year;
}

void Date::printDayMonthYear() { //print in 25 December 0000 format
    cout << day << " " << getmonthName(month) << " " << year;
}

bool Date::isvalidDate(int month, int day, int year) { //validating the day
    cout << "Checking date: ";

    if (month < 1 || month > 12) {
        cout << "Invalid month." << "\n";
        return false;
    }

    if (day < 1 || day > daysinMonth[month]) {
        cout << "Invalid day." << "\n";
        return false;
    }

    if (month == 2 && day == 29) {
        if (!((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            cout << "Invalid leap year day." << "\n";
            return false;
        }
    }

    cout << "Date is valid." << "\n";
    return true;
}
string Date::getmonthName(int month) { //finding name of month based on array
    string monthNames[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return monthNames[month];
}