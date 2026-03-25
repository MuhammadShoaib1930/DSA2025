#include <iostream>
#include <vector>
using namespace std;

void pattern(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (j <= i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        for (int j = 0; j < n - 1; j++) {
            if (j < n - 2 - i) {
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (j < n - 1 - i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        for (int j = 0; j < n - 1; j++) {
            if (j < i) {
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }
}
// void pattern2(int n) {
// int k = n;
// for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j <= i; j++) {
//             cout << "*";
//         }
//         for (int j = 0; j <= k; j++) {
//             cout << " ";
//         }
//         for (int j = 0; j <= i; j++) {
//             cout << "*";
//         }
//         k = k - 2;
//         cout << endl;
//     }
//     k = 0;
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n-1-i; j++) {
//             cout << "*";
//         }
//         for (int j = 0; j < k; j++) {
//             cout << " ";
//         }
//         for (int j = 0; j < n-1-i; j++) {
//             cout << "*";
//         }
//         k = k + 2;
//         cout << endl;
//     }
// }
vector<int> twoSum1(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (target == nums[i] + nums[j]) {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;
}

int main() {
    return 0;
}
