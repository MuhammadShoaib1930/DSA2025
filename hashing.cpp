#include <iostream>
#include <vector>
using namespace std;
class HashMethods
{
public:
    int divisionHashFunction(int key, int size)
    {
        return (key % size);
    }
    int mutiplicationHashFunction(int key, int size, float a = 0.29483)
    {
        float index = (key * a);
        index = index - (int)index;
        return (index * digitsFind(size));
    }
    int midSqureHashFunction(int value, int size)
    {
        value *= value;
        int index = 0, zeros = 1;
        if (value < 10)
            return value;

        value /= 10;
        if (value < 10)
            return value;
        while (value > 0 && index < size / 10)
        {
            index = ((value % 10) * zeros) + index;
            value /= 10;
            zeros *= 10;
        }
        return index;
    }
    int digitsFind(int value)
    {
        int digits = 1;
        value = value / 10;
        while (value > 0)
        {
            digits *= 10;
            value = value / 10;
        }
        return digits;
    }
};
class Hash : private HashMethods
{

public:
};