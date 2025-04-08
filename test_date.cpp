#include <iostream>
#include "date.h"

using namespace std;

int main() {
    // 1. default constructor and first date format (numeric):
    Date date1(1,1,2000); // no default constructor, so create a known valid date.
    cout << "Test 1: ";
    date1.printNumeric();
    cout << "\n";

    // 2. parameterized constructor and second date format (month day, year):
    Date date2(5, 20, 2023);
    cout << "Test 2: ";
    date2.printMonthDayYear();
    cout << "\n";

    // 3. setDate() and third date format (day month year):
    date1.setDate(8, 15, 2022);
    cout << "Test 3: ";
    date1.printDayMonthYear();
    cout << "\n";

    // 4. invalid month and day (13/45/2018):
    date1.setDate(13, 45, 2018);
    if (date1.isValid()) {
        cout << "Test 4 failed: invalid date accepted." << "\n";
    } else {
        cout << "Test 4: invalid date correctly rejected." << "\n";
    }

    // 5. invalid day for month (4/31/2000):
    date1.setDate(4, 31, 2000);
    if (date1.isValid()) {
        cout << "Test 5 failed: invalid date accepted." << "\n";
    } else {
        cout << "Test 5: invalid date correctly rejected." << "\n";
    }

    // 6. invalid day for leap year (2/29/2009):
    date1.setDate(2, 29, 2009);
    if (date1.isValid()) {
        cout << "Test 6 failed: invalid date accepted." << "\n";
    } else {
        cout << "Test 6: invalid date correctly rejected." << "\n";
    }

    // 7. date subtraction (positive result):
    date1.setDate(4, 18, 2014); // date 2 is the larger date, and the result is negative.
    date2.setDate(4, 10, 2014);
    if ((date2 - date1) != -8) {
        cout << "Test 7 failed: incorrect subtraction result." << "\n";
    } else {
        cout << "Test 7: subtraction correct." << "\n";
    }

    // 8. date subtraction (negative result):
    date1.setDate(2, 2, 2006);
    date2.setDate(11, 10, 2003);
    if ((date1 - date2) != 815) {
        cout << "Test 8 failed: incorrect subtraction result." << "\n";
    } else {
        cout << "Test 8: subtraction correct." << "\n";
    }

    // 9. pre-decrement operator (leap year):
    date1.setDate(2, 29, 2008);
    --date1;
    cout << "Test 9: ";
    date1.printNumeric();
    cout << "\n";

    // 10. pre-increment operator (leap year):
    ++date1;
    cout << "Test 10: ";
    date1.printNumeric();
    cout << "\n";

    // 11. post-decrement and post-increment operators (leap year):
    date1.setDate(2, 29, 2008);
    date1--;
    cout << "Test 11a: ";
    date1.printNumeric();
    cout << "\n";
    date1++;
    cout << "Test 11b: ";
    date1.printNumeric();
    cout << "\n";

    // 12. post-increment operator (year rollover):
    date1.setDate(12, 31, 2024);
    date1++;
    cout << "Test 12: ";
    date1.printNumeric();
    cout << "\n";

    // 13. post-decrement operator (year rollover):
    date1--;
    cout << "Test 13: ";
    date1.printNumeric();
    cout << "\n";

    // 14. pre-increment and pre-decrement operators (year rollover):
    date1.setDate(12, 31, 2024);
    ++date1;
    cout << "Test 14a: ";
    date1.printNumeric();
    cout << "\n";
    --date1;
    cout << "Test 14b: ";
    date1.printNumeric();
    cout << "\n";

    // 15. input stream operator (>>):
    Date inputDate(1, 1, 2025);
    cout << "Test 15: enter 10/25/2023" << "\n";
    cin >> inputDate;
    cout << "Test 15: ";
    inputDate.printNumeric();
    cout << "\n";

    // 16. output stream operator (<<):
    cout << "Test 16: ";
    cout << inputDate << "\n";

    cout << "tests completed." << "\n";
    return 0;
}