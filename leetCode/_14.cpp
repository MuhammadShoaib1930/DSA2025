

/*
Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You
may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:

n == nums.length
1 <= n <= 5 * 104
-10^9 <= nums[i] <= 10^9
The input is generated such that a majority element will exist in the array.


Follow-up: Could you solve the problem in linear time and in O(1) space?
*/
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;
int majorityElement1(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MIN;
    int maxFreq = INT_MIN;
    for (int i = 0; i < n; i++) {
        int value = nums[i];
        int freq = 0;
        for (int j = i + 1; j < n; j++) {
            if (value == nums[j]) {
                freq++;
            }
        }
        if (freq > maxFreq) {
            maxFreq = freq;
            ans = value;
        }
    }

    return ans;
}
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int ans = nums[0];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (ans == nums[i]) count++;
        if (ans != nums[i]) count--;
        if(count == 0){
            ans = nums[i];
            count++;
        }
    }
    return ans;
}
