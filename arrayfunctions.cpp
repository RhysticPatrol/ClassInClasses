#include "float.h"
#include <iostream>
using namespace std;

FloatArray::FloatArray(int size) {
    if (size <= 0) {
        cout << "Warning: Size must be positive. Initializing to 1.\n";
        size = 1;
    }
    arrSize = size;
    data = new float[arrSize];

    for (int i = 0; i < arrSize; ++i){
        data[i] = 0;
    }
}

FloatArray::~FloatArray(){
    delete[] data;
}

void FloatArray::store(int index, float value){ //storing number in array
    if (index < 0 || index >= arrSize){
        cout << "Error: Attempted to store at invalid index " << index << ". Allowed range: 0-" << (arrSize - 1) << "\n";
        return;
    }
    data[index] = value;
}

float FloatArray::retrieve(int index){ // retrieving number
    if (index < 0 || index >= arrSize){
        cout << "Error: Attempted to retrieve from invalid index. Returning 0.\n";
        return 0;
    }
    return data[index];
}

float FloatArray::getHighest(){ //finding highest number in array
    if (arrSize == 0) {
        cout << "Error: Array is empty.\n";
        return 0;
    }

    float highest = data[0];
    for (int i = 1; i < arrSize; ++i){
        if (data[i] > highest) {
            highest = data[i];
        }
    }
    return highest;
}

float FloatArray::getLowest(){ //finding lowest number in array
    if (arrSize == 0) {
        cout << "Error: Array is empty.\n";
        return 0;
    }

    float lowest = data[0];
    for (int i = 1; i < arrSize; ++i){
        if (data[i] < lowest) {
            lowest = data[i];
        }
    }
    return lowest;
}

float FloatArray::getAverage(){ //finding the average of numbers in array
    if (arrSize == 0) {
        cout << "Error: Array is empty.\n";
        return 0;
    }

    float sum = 0;
    for (int i = 0; i < arrSize; ++i){
        sum += data[i];
    }
    return sum / arrSize;
}
