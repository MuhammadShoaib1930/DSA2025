

#include <iostream>
#include <vector>
using namespace std;
class Sorting {
   public:
    vector<int> buble(vector<int> arr) {
        bool isSwaped = false;
        for (int j = 0; j < arr.size(); j++) {
            for (int i = 0; i < arr.size() - 1 - j; i++) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    isSwaped = true;
                }
                isSwaped = false;
                if (isSwaped) return arr;
            }
        }
        return arr;
    }
    vector<int> insertion(vector<int> arr) {
        for (int j = 0; j < arr.size(); j++) {
            int i = j + 1;
            while (i < arr.size() && arr[j] < arr[i]) {
                i++;
            }
            while (i >= 0 && arr[i - 1] > arr[i]) {
                int temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                i--;
            }
        }

        return arr;
    }
    vector<int> selection(vector<int> arr) {
        for (int j = 0; j < arr.size()-1; j++) {
            int min = j;
            for (int i = j + 1; i < arr.size() ; i++) {
                if (arr[min] > arr[i]) {
                    min = i;
                }
            }
            int temp = arr[min];
            arr[min] = arr[j];
            arr[j] = temp;
        }

        return arr;
    }
    vector<int> marge(vector<int> arr) { return arr; }
    vector<int> shell(vector<int> arr) { return arr; }
    vector<int> quick(vector<int> arr) { return arr; }
};
