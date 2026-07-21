#include <iostream>
#include <vector>
#include<unordered_map>
#include "graph.cpp"
using namespace std;

string longestStr(int st, int ed, string s, int n) {
    string result = "";
    while (st >= 0 && ed < n && s[st] == s[ed])
    {

        result = (char)s[st] + result;
        if (st != ed) {
            result = result + (char)s[ed];
        }
        st--, ed++;
    }
    return result;
}

string longestPalindrome(string s) {
    int n = s.size();
    int i = 0;
    string result = "";
    while (i < n)
    {
        string temp = "";
        temp = longestStr(i, i, s, n);
        if (temp.size() > result.size())result = temp;
        temp = longestStr(i, i + 1, s, n);
        if (temp.size() > result.size())result = temp;
        i++;
    }
    return result;
}
int fib(int n, vector<int>& db) {
    if (n <= 1)return n;
    if (db[n] != -1) return db[n];
    db[n] = fib(n - 1, db) + fib(n - 2, db);
    return db[n];
}
int sumR(int n) {
    if (n <= 1)return n;
    cout << n << " ";
    return sumR(n - 1) + n;
}
int sumA(int n) {
    if (n <= 1)return n;
    int s = sumA(n - 1) + n;
    cout << n << " ";
    return s;
}
string convert(string s, int numRows) {
    int n = s.size();
    if (n <= 1) return s;
    vector<string> resultList = vector<string>(numRows + 1, "");
    int st = 0;
    bool isTrue = true;
    for (int i = 0; i < s.size(); i++)
    {
        resultList[st] += s[i];

        if (isTrue) {
            st++;
            if (st >= numRows - 1) isTrue = false;
        }
        else {
            st--;
            if (st <= 0) isTrue = true;
        }
    }
    string result = "";
    for (int i = 0; i < resultList.size(); i++)
    {
        result += resultList[i];
    }


    return result;
}
int reverse(int x) {
    long long int inputValue = (x < 0) ? -(long long int)x : x;
    long long int result = 0;
    while (inputValue > 0)
    {
        result = result * 10 + (inputValue % 10);
        inputValue /= 10;
    }
    if (result != (int)result) {
        return 0;
    }
    if (x < 0) {
        return -(int)result;
    }
    return   (int)result;
}

int myAtoi(string s) {
    int i = 0, sign = 1, n = s.size();
    long res = 0;
    while (i < n && s[i] == ' ')i++;
    if (i >= n)return 0;
    if (i < n && s[i] == '-') {
        sign = -1; i++;
    }
    else if (i < n && s[i] == '+') {
        i++;
    }
    while (i < n && s[i] >= '0' && s[i] <= '0')
    {
        res = res * 10 + (s[i] - '0');
        if (res * sign < INT_MIN) return INT_MIN;
        if (res * sign > INT_MAX)return INT_MAX;
        i++;
    }
    return (int)(sign * res);

}
bool isMatch(string s, string p) {
    int i = s.size() - 1;
    int j = p.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (s[i] == p[j] || p[j] == '.') {
            i--;j--;
        }
        else if (p[j] == '*') {
            break;
        }
        else {
            return false;
        }
    }
    while (i >= 0 && p[j - 1] != '.' && p[j] == '*')
    {
        if (s[i] == p[j - 1] && s[i] == s[i - 1]) {
            i--;
        }
        else {
            while (i >= 0 && p[j] != s[i])
            {
                j--;
            }
            break;
        }
    }
    //remaning the .* condition
    return false;

}

int maxArea(vector<int>& height) {
    int n = height.size();
    if (n <= 1)return 0;
    int i = 0;int  j = n - 1;
    int maxWater = 0;
    while (i < j)
    {
        maxWater = max(maxWater, min(height[i], height[j]) * (j - i));
        if (height[i] < height[j]) {
            i++;
        }
        else {
            j--;
        }
    }



    return maxWater;
}
// Easy(50–100 problems)
// Arrays
// Strings
// Hash Maps
// Two Pointers
// Stack
// Queue
// Medium(100–150 problems)
// Binary Search
// Linked List
// Trees
// Sliding Window
// Greedy
// Basic DP
// Hard
// Regular Expression Matching
// Edit Distance
// Wildcard Matching
// Advanced DP problems
vector<vector<int>> getRow1(int rowIndex) {
    vector<vector<int>> res;
    for (int j = 0; j < rowIndex; j++)
    {
        vector<int> result = vector<int>(j + 1, 1);
        for (int i = 0; i < j; i++)
        {
            result[i + 1] = (int)((long long)result[i] * (j - i) / (i + 1));
        }
        res.push_back(result);
    }

    return res;
}
vector<int> getRow2(int rowIndex) {
    vector<int> result = vector<int>(rowIndex + 1, 1);
    for (int i = 0; i < rowIndex; i++)
    {
        result[i + 1] = (int)((long long)result[i] * (rowIndex - i) / (i + 1));
    }
    return result;
}
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> myValue;
    for (int i = 0; i < nums.size(); i++)
    {
        if (myValue.find(nums[i]) != myValue.end()) {
            if ((myValue[nums[i]] - i) <= k) {
                return true;
            }
        }
        else {
            myValue[nums[i]] = i;
        }
    }

    return false;
}
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int start = nums[0];int end = nums[0];
    int count = 0;
    for (int i = 1; i < res.size(); i++)
    {
        count++;
        if (start + count == nums[i]) {
            end = nums[i];
        }
        else {

            res.push_back(to_string(start) + "->" + to_string(end));
            start = nums[i];
            end = nums[i];
            count = 0;
        }
    }


    return res;
}
void subString(string s, vector<string> dp, int index = 0, string result = "", ) {
    if (index > s.size()) {
        cout << result << " ";
        return;
    }

    if (dp[index].empty()) {
        dp[index] = result + s[index];
        subString(s, dp, index + 1, result + s[index]);
        subString(s, dp, index + 1, result);

    }
}
int main() {
    vector<string> dp = vector<string>(4, "");
    subString("abc", dp);
    // vector<int> input = { 1,2,3,5,6,8,9 };
    // vector<string> s = summaryRanges(input);
    // for (int j = 0; j < s.size(); j++)
    // {
    //     cout << s[j] << " ";
    // }


    // cout <<"123 "<< myAtoi("123")<<endl;
    // cout <<"-123 "<< myAtoi("-123")<<endl;
    // cout <<"0 "<< myAtoi("0")<<endl;
    // cout <<"00-1 "<< myAtoi("00-1")<<endl;
    // cout <<"0-123 "<< myAtoi("0-123")<<endl;
    // cout << isMatch("aaaaa", ".*aaaaaaaa") << endl;
    // cout <<"0a123 "<< myAtoi("0a123")<<endl;
    // cout <<"0-1-23 "<< myAtoi("0-1-23")<<endl;
    // vector<int> db = vector<int>(7, -1);
    // int f = fib(6, db);
    // cout << endl << f <-< endl;
    return 0;
}
// 1 hours completed video
