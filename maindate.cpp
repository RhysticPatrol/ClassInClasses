#include <iostream>
#include "date.h"

using namespace std;

int main() {
    int month, day, year;

    cout << "Enter the month in numeric value: ";
    cin >> month;
    cout << "Enter the day in numeric value: ";
    cin >> day;
    cout << "Enter the year in numeric value: ";
    cin >> year;

    Date myDate(month, day, year); // Create a Date object
    if (myDate.isvalidDate(month, day, year)) {
        myDate.printNumeric();
        cout << "\n";
        myDate.printMonthDayYear();
        cout << "\n";
        myDate.printDayMonthYear();
        cout << "\n";
    } else {
        cout << "The data you have entered is incorrect" << "\n";
    }
    return 0;
}