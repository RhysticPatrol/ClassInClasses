#include "date.h"
#include <iostream>
#include <iomanip>
using namespace std;

// this is an array that stores how many days are in each month
// we start with 0 because we'll use month numbers 1-12, not 0-11
const int Date::daysinMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// this is the constructor
Date::Date(int m, int d, int y) : month(m), day(d), year(y), valid(true) {
    // check if the date is okay right away
    validateDate();
}

// this function checks if the date is valid
void Date::validateDate() {
    // check if the month is between 1 and 12
    if (month < 1 || month > 12) {
        valid = false; // if not, the date is invalid
        cout << "invalid month." << "\n";
        return; // stop checking
    }

    // get the maximum number of days for this month
    int maxDay = daysinMonth[month];

    // if it's february, we need to check if it's a leap year
    if (month == 2 && isLeapYear(year)) {
        maxDay = 29; // leap year february has 29 days
    }

    // check if the day is within the valid range for the month
    if (day < 1 || day > maxDay) {
        valid = false; // if not, the date is invalid
        cout << "invalid day." << "\n";
        return; // stop checking
    }

    // special check for february 29th in a non-leap year
    if (month == 2 && day == 29 && !isLeapYear(year)) {
        valid = false;
        cout << "invalid day for non-leap year" << "\n";
        return;
    }

    // if we made it here, the date is valid
    valid = true;
}

// this function checks if a year is a leap year
bool Date::isLeapYear(int year) const {
    // leap year rules: divisible by 4, but not by 100 unless it's also divisible by 400
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// this function prints the date in mm/dd/yyyy format
void Date::printNumeric() const {
    if (valid) {
        cout << setw(2) << setfill('0') << month << "/"
             << setw(2) << setfill('0') << day << "/"
             << setw(4) << year;
    } else {
        cout << "invalid date";
    }
}

// this function prints the date in month day, year format
void Date::printMonthDayYear() const {
    if (valid) {
        cout << getMonthName(month) << " " << day << ", " << year;
    } else {
        cout << "invalid date";
    }
}

// this function prints the date in day month year format
void Date::printDayMonthYear() const {
    if (valid) {
        cout << day << " " << getMonthName(month) << " " << year;
    } else {
        cout << "invalid date";
    }
}

// this function gets the name of the month from its number
string Date::getMonthName(int month) const {
    string monthNames[] = {
        "", "january", "february", "march", "april", "may", "june",
        "july", "august", "september", "october", "november", "december"
    };

    if (month < 1 || month > 12) {
        cout << "invalid month number.";
        return "";
    }

    return monthNames[month];
}

// this function increments the date by one day (prefix ++)
Date& Date::operator++() {
    if (valid) {
        day++;
        normalizeDate(); // adjust if we went to the next month or year
    }
    return *this;
}

// this function increments the date by one day (postfix ++)
Date Date::operator++(int) {
    Date temp = *this; // save the current date
    if (valid) {
        day++;
        normalizeDate();
    }
    return temp; // return the original date
}

// this function decrements the date by one day (prefix --)
Date& Date::operator--() {
    if (valid) {
        day--;
        normalizeDate();
    }
    return *this;
}

// this function decrements the date by one day (postfix --)
Date Date::operator--(int) {
    Date temp = *this;
    if (valid) {
        day--;
        normalizeDate();
    }
    return temp;
}

// this function calculates the difference between two dates in days
int Date::operator-(const Date& other) const {
    if (valid && other.valid) {
        int days1 = dateToDays();
        int days2 = other.dateToDays();
        return days1 - days2;
    } else {
        return 0; // return 0 if either date is invalid
    }
}

// this function lets us print a Date object using cout
ostream& operator<<(ostream& os, const Date& date) {
    if (date.valid) {
        os << date.getMonthName(date.month) << " " << date.day << ", " << date.year;
    } else {
        os << "invalid date";
    }
    return os;
}

// this function lets us read a Date object using cin
istream& operator>>(istream& is, Date& date) {
    int m, d, y;
    char slash1, slash2;

    cout << "enter date in mm/dd/yyyy format: ";
    if (is >> m >> slash1 >> d >> slash2 >> y && slash1 == '/' && slash2 == '/') {
        date.month = m;
        date.day = d;
        date.year = y;
        date.validateDate();
    } else {
        date.valid = false;
        cout << "invalid date format. please use mm/dd/yyyy." << "\n";
    }
    return is;
}

// this function converts a date to the number of days since a certain point
int Date::dateToDays() const {
    int m = (month + 9) % 12;
    int y = year - m / 10;
    return y * 365 + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (day - 1);
}

// this function adjusts the date if we went to the next or previous month/year
void Date::normalizeDate() {
    int maxDay = daysinMonth[month];
    if (isLeapYear(year) && month == 2) {
        maxDay = 29;
    }

    if (day > maxDay) {
        day = day - maxDay;
        month = month + 1;
        if (month > 12) {
            month = 1;
            year = year + 1;
        }
    } else if (day < 1) {
        month = month - 1;
        if (month < 1) {
            month = 12;
            year = year - 1;
        }
        maxDay = daysinMonth[month];
        if (isLeapYear(year) && month == 2)
            maxDay = 29;
        day = day + maxDay;
    }
    validateDate();
}

// this function checks if the date is valid
bool Date::isValid() const {
    return valid;
}

// this function sets the date to new values
void Date::setDate(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
    validateDate();
}