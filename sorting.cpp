

#include <iostream>
#include <vector>
using namespace std;
class Sorting {
    void margePart(vector<int>& arr, int s = 0, int m = 0, int e = 0) {
        int i = s, j = m+1;
        vector<int> arrD;
        while (i<=m && j<=e)
            if(arr[i]<arr[j])
                arrD.push_back(arr[i++]);
            else
                arrD.push_back(arr[j++]);
        while (i<=m)
            arrD.push_back(arr[i++]);
        while (j<=e)
            arrD.push_back(arr[j++]);
        for (int i = 0; i < arrD.size(); i++)
            arr[i+s] = arrD[i];
    }

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
    void selection(vector<int>& arr) {
        for (int j = 0; j < arr.size() - 1; j++) {
            int min = j;
            for (int i = j + 1; i < arr.size(); i++) {
                if (arr[min] > arr[i]) {
                    min = i;
                }
            }
            int temp = arr[min];
            arr[min] = arr[j];
            arr[j] = temp;
        }
    }

    void marge(vector<int>& arr, int s = 0, int e = 0) {
        if (s >= e) return;
        int mid = ((e - s) / 2) + s;
        marge(arr, s, mid);
        marge(arr, mid + 1, e);
        margePart(arr, s, mid, e);
    }
    vector<int> shell(vector<int> arr) { return arr; }
    vector<int> quick(vector<int> arr) { return arr; }
};
