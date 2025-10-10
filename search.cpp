#include <iostream>
using namespace std;
template <typename T>
class Search
{

public:
    int linear(T *array, T value, int n)
    {
        int comparison = 0;
        for (int i = 0; i < n; i++)
        {
            comparison++;
            if (value == array[i])
            {
                cout << " comparison = " << comparison << endl;
                return i;
            }
        }
        cout << " comparison = " << comparison << endl;
        return -1;
    }
    int binary(T *array, T value, int n)
    {
        int start = 0, mid = 0, end = n;
        while (start <= end)
        {
            mid = ((end - start) / 2) + start;
            if (array[mid] < value)
                start = mid + 1;
            else if (array[mid] > value)
                end = mid - 1;
            else
                return mid;
        }
        return -1;
    }
    int interpolation(T *array, T value, int n)
    {
        int start = 0, end = n - 1;

        while (start <= end && value >= array[start] && value <= array[end])
        {
            if (array[start] == array[end])
            {
                if (array[start] == value)
                    return start;
                else
                    return -1;
            }

            int mid = start + ((value - array[start]) * (end - start)) / (array[end] - array[start]);

            if (array[mid] == value)
                return mid;
            else if (array[mid] < value)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return -1;
    }
};