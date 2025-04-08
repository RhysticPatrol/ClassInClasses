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

    Date myDate(month, day, year); // create a Date object

    if (myDate.isValid()) { 
        cout << "Numeric: ";
        myDate.printNumeric();
        cout << "\n";

        cout << "Month Day Year: ";
        myDate.printMonthDayYear();
        cout << "\n";

        cout << "Day Month Year: ";
        myDate.printDayMonthYear();
        cout << "\n";

        //demonstrate more functionality
        cout << "Original Date: " << myDate << "\n";

        cout << "Testing ++ operator (prefix): " << ++myDate << "\n";
        cout << "Testing ++ operator (postfix): " << myDate++ << "\n";
        cout << "After postfix: " << myDate << "\n";

        cout << "Testing -- operator (prefix): " << --myDate << "\n";
        cout << "Testing -- operator (postfix): " << myDate-- << "\n";
        cout << "After postfix: " << myDate << "\n";

        Date anotherDate(1, 1, year);
        cout << "Days between " << myDate << " and " << anotherDate << ": " << (myDate - anotherDate) << "\n";

        Date inputDate(1,1,2025);
        cout << "Enter a date: ";
        cin >> inputDate;
        cout << "You entered: " << inputDate << "\n";


    } else {
        cout << "The data you have entered is incorrect\n";
    }

    return 0;
}
