#include <iostream>
#include <vector>
using namespace std;
template <typename T,int maxSize>
class MyArray
{
    T *array;
    int n;
public:
    MyArray(): n(0)
    {
        n = 0;
        array = new T[maxSize];
    }
    void insertByValue(T newValue, T value = INT_MAX)
    {
        if (isFull())
            return;
        int index = search(value);
        insertByIndex(newValue, index);
    }
    void insertByIndex(T newValue, int index = -1)
    {
        if (n == maxSize)
            return;
        if (index <= maxSize && index == -1)
        {
            array[n] = newValue;
            n++;
            return;
        }
        for (int i = n; i > index; i--)
        {
            array[i] = array[i - 1];
        }
        array[index] = newValue;
        n++;
    }
    void travers(int n = -1)
    {
        int m;
        m = (n == -1) ? this->n : n;
        for (int i = 0; i < m; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    bool isFull()
    {
        return (n == maxSize);
    }
    int search(int value)
    {
        for (int i = 0; i < n; i++)
        {
            if (value == array[i])
                return i;
        }
        return -1;
    }
    bool isEmpty()
    {
        return (n == 0);
    }
    int arrayMaxSize()
    {
        return maxSize;
    }
    int arraySize()
    {
        return n;
    }
    void update(int newValue, int oldValue)
    {
        int index = search(oldValue);
        array[index] = newValue;
    }
    void deleteByValue(int value)
    {
        if (arraySize() < 0)
            return;
        int index = search(value);
        for (int i = index; i < n; i++)
        {
            array[i] = array[i + 1];
        }
        n--;
    }
    void deleteByIndex(int index)
    {
        if (arraySize() < 0 && n <= index)
            return;
        for (int i = index; i < n; i++)
        {
            array[i] = array[i + 1];
        }
        n--;
    }
};
