#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>
vector<int> towSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> smap;
    for (int i = 0; i < nums.size(); i++) {
        int find = target - nums[i];
        if (smap.find(find) != smap.end()) {
            res.push_back(smap.at(find));
            res.push_back(i);
            return res;
        }
        smap[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> input = {3, 2, 4};
    vector<int> res = towSum(input, 6);
    cout << res[0] << " " << res[1];
    return 0;
}
