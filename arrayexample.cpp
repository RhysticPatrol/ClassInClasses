#include <iostream>
#include <limits> 
#include "float.h"
using namespace std;

int main() {
    FloatArray myArray(5);

    //storing numbers in array
    myArray.store(0, 3.14f); 
    myArray.store(1, 2.71f);
    myArray.store(2, 5.0f);
    myArray.store(3, 1.0f);
    myArray.store(4, 9.9f);

    cout << "Element at index 2: " << myArray.retrieve(2) << "\n"; //retrieve function at 2
    cout << "Highest value: " << myArray.getHighest() << "\n"; // finding highest number
    cout << "Lowest value: " << myArray.getLowest() << "\n"; // finding lowest number
    cout << "Average value: " << myArray.getAverage() << "\n"; // getting the average

    return 0;
}