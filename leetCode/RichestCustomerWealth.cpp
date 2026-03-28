#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>
int maximumWealth(vector<vector<int>>& accounts) {
    int sum = 0;
    for (int i = 0; i < accounts.size(); i++) {
        int currSum = 0;
        for (int j = 0; j < accounts[i].size(); j++) {
            currSum += accounts[i][j];
        }
        sum = max(sum, currSum);
    }
    return sum;
}

int main() {
    vector<vector<int>> arr;
    arr = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
    cout << maximumWealth(arr);
    return 0;
}
