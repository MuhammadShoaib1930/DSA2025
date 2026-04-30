
/*
Given an integer array nums, return true if any value appears at least twice in
the array, and return false if every element is distinct.



Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true



Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
    set<int> dataSet;

    for (int i = 0; i <nums.size(); i++)
    {
        if(dataSet.count(nums[i])){
            return true;
        }else{
            dataSet.insert(nums[i]);
        }
    }

    return false;
}
bool containsDuplicate2(vector<int>& nums) {
    return nums.size() > set<int>(nums.begin(), nums.end()).size();
}
// best
bool containsDuplicate1(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int i = 1; i <nums.size(); i++)
    {
        if(nums[i-1]==nums[i]){
            return true;
        }
    }

    return false;
}
