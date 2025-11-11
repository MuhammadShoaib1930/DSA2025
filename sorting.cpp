

#include <iostream>
#include <vector>
using namespace std;
class Sorting {
    void margePart(vector<int>& arr, int s = 0, int m = 0, int e = 0) {
        int i = s, j = m + 1;
        vector<int> arrD;
        while (i <= m && j <= e)
            if (arr[i] < arr[j])
                arrD.push_back(arr[i++]);
            else
                arrD.push_back(arr[j++]);
        while (i <= m) arrD.push_back(arr[i++]);
        while (j <= e) arrD.push_back(arr[j++]);
        for (int i = 0; i < arrD.size(); i++) arr[i + s] = arrD[i];
    }

   public:
    void buble(vector<int>& arr) {
        for (int j = 0; j < arr.size(); j++) {
            bool isSwaped = false;
            for (int i = 0; i < arr.size() - 1 - j; i++) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    isSwaped = true;
                }
            }
            if (isSwaped) return;
        }
    }
    void insertion(vector<int>& arr) {
        for (int j = 1; j < arr.size(); j++) {
            int key = arr[j];
            int i = j - 1;
            while (i >= 0 && arr[i] > key) {
                arr[i + 1] = arr[i];
                i--;
            }
            arr[i + 1] = key;
        }
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

    void marge(vector<int>& arr, int s = 0, int e = -1) {
        if (e == -1) e = arr.size() - 1;
        if (s >= e) return;
        int mid = ((e - s) / 2) + s;
        marge(arr, s, mid);
        marge(arr, mid + 1, e);
        margePart(arr, s, mid, e);
    }
    void shell(vector<int>& arr) {
        int n = arr.size();
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; i >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    int quickPartition(vector<int>& arr, int s , int n ) {
        int mid = s + (n - s) / 2;
        int i = 0, j = n;
        while (i<=j)
        {
            while (arr[i] < arr[mid]) i++;
            while (arr[mid] < arr[j]) j--;
            if(i<=j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        return i;
    }
    void quick(vector<int>& arr, int s = 0, int n = -1) {
        if (n == -1) n = arr.size() - 1;
        if (s >= n) return;
        int pavoit = quickPartition(arr, s, n);
        quick(arr, s, pavoit-1);
        quick(arr, pavoit, n);

    }
};
