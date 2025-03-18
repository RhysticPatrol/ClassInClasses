#ifndef FLOAT_H
#define FLOAT_H

#include <iostream>
#include <limits>


class FloatArray {
private:
    float* data;
    int arrSize;

public:
    FloatArray(int size);
    ~FloatArray();

    void store(int index, float value);
    float retrieve(int index);
    float getHighest();
    float getLowest();
    float getAverage();
};

#endif
