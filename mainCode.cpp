#include <iostream>
#include <vector>
#include <iomanip>
#include "myArray.cpp"
#include <map>
using namespace std;
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    MyArray<int, 5> ar;
    for (int i = 0; i < 10; i++)
    {
        ar.insertByIndex(i);
    }
    for (int i = 10; i < 100; i += 10)
    {
        ar.insertByIndex(i);
    }
    ar.travers();

    return 0;
}
