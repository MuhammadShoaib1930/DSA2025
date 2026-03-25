#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>
vector<int> runningSum(vector<int>& nums) {
    int sum = 0;
    vector<int> res;
    for(int i : nums){
        sum += i;
        res.push_back(sum);
    }
    return res;
}

int main() {
    return 0;
}
