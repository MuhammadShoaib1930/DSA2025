

#include <type_traits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include<set>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include "my_algo.cpp"
using namespace std;

// Level 1 — Make recursion automatic
    // 1. Factorial of n
    // Input: 5
    // Output: 120
    // Problem: Find n!, the product of all positive integers from 1 to n.
int factorial(int n) {
    if (n == 0)
        return 1;
    return factorial(n - 1) * n;
}
// 2. Sum 1...n
// Problem: Find the sum of all integers from 1 to n.
// Input: 5
// Output: 15
int sum1ToN(int n) {
    if (n == 0)return 0;
    return sum1ToN(n - 1) + n;
}
// 3. Power a^n
// Problem: Calculate a raised to the power n.
// Input: 2, 5
// Output: 32
float partPower(int a, int b) {
    if (b == 0)return 1;
    return partPower(a, b - 1) * a;
}
float power(int a, int b) {
    bool isN = (b < 0) ? true : false;
    return (isN) ? 1 / partPower(a, abs(b)) : partPower(a, b);
}
// 4. Sum of digits
// Problem: Find the sum of all digits in a number.
// Input: 583
// Output: 16
int digitSum(int n) {
    if (n == 0)
        return 0;
    return digitSum(n / 10) + (n % 10);
}


// 5. Count digits
// Problem: Count how many digits are present in a number.
// Input: 58392
// Output: 5

int countDigit(int n) {
    if (n > -10 && n < 10)return 1;
    return countDigit(n / 10) + 1;
}
// 6. Reverse a number
// Problem: Reverse the digits of a given number.
// Input: 12345
// Output: 54321
int ReverseNumber(int n, int res = 0) {
    if (n < 1 || n > -1)return res;
    return ReverseNumber((n / 10), (n % 10) + (res * 10));
}

// 7. Print numbers 1 → n
// Problem: Print all numbers starting from 1 up to n.
// Input: 5
// Output: 1 2 3 4 5
void print1ToN(int n) {
    if (n < 1) {
        return;
    }
    print1ToN(n - 1);
    cout << n << " ";
}

// 8. Print numbers n → 1
// Problem: Print all numbers starting from n down to 1.
// Input: 5
// Output: 5 4 3 2 1
void printNTo1(int n) {
    if (n == 0)return;
    cout << n << " ";
    printNTo1(n - 1);
}
// 9. Find max in an array recursively
// Problem: Find the largest value in the given array.
// Input: [4, 9, 2, 7, 5]
// Output: 9
int maxInArray(vector<int>& arr, int ind = 0, int res = -1) {
    if (ind >= arr.size())return res;
    res = max(res, arr[ind]);
    return maxInArray(arr, ind + 1, res);
}
// 10. Find sum of an array recursively
// Problem: Calculate the sum of all elements in the array.
// Input: [2, 4, 6, 8]
// Output: 20
int sumOfArray(vector<int>& arr, int ind = 0) {
    if (ind >= arr.size())return 0;
    return sumOfArray(arr, ind + 1) + arr[ind];
}

//  Level 2 — Learn "smaller problem" thinking

// 11. Binary Search recursively
// Problem: Search for a target value in a sorted array and return its index. Return -1 if it does not exist.
// Input: arr = [1, 3, 5, 7, 9], target = 7
// Output: 3
int BinarySearch(vector<int>& arr, int target, int st = 0, int ed = -10) {
    if (ed == -10) {
        ed = arr.size();
    }
    if (st > ed) return -1;
    int mid = st + ((ed - st) / 2);
    if (arr[mid] == target) {
        return mid;
    }
    else if (arr[mid] > target) {
        ed = mid - 1;
    }
    else {
        st = mid + 1;
    }
    return BinarySearch(arr, target, st, ed);
}
// 12. Check if an array is sorted
// Problem: Determine whether the array is sorted in ascending order.
// Input: [2, 4, 6, 8, 10]
// Output: true
bool isArraySort(vector<int>& arr, int curr = 1, int past = 0) {
    int n = arr.size();
    if (n < 2)return true;
    if (arr[past] < arr[curr]) {
        return  isArraySort(arr, curr + 1, past + 1);
    }
    else {
        return false;
    }
}

// 13. Find first occurrence of an element
// Problem: Find the index of the first occurrence of the target value.
// Input: arr = [2, 5, 3, 5, 7, 5], target = 5
// Output: 1
int FirstOccurrence(vector<int>& arr, int target, int ind = 0) {
    if (ind >= arr.size())return -1;
    if (arr[ind] == target)return ind;
    return FirstOccurrence(arr, target, ind + 1);
}


// 14. Find last occurrence of an element
// Problem: Find the index of the last occurrence of the target value.
// Input: arr = [2, 5, 3, 5, 7, 5], target = 5
// Output: 5
int lastOccurrence(vector<int>& arr, int target, int ind = 0, int result = -1) {
    if (ind >= arr.size())return result;
    if (arr[ind] == target)
        result = ind;
    return lastOccurrence(arr, target, ind + 1, result);
}

// 15. Count occurrences of an element
// Problem: Count how many times the target value appears in the array.
// Input: arr = [2, 5, 3, 5, 7, 5], target = 5
// Output: 3
int countOccurrences(vector<int>& arr, int target, int ind = 0, int result = 0) {
    if (ind >= arr.size())return result;
    if (arr[ind] == target)
        result = result + 1;
    return countOccurrences(arr, target, ind + 1, result);
}

// 16. Remove a character from a string
// Problem: Remove every occurrence of a specified character from the string.
// Input: str = "banana", ch = 'a'
// Output: "bnn"
string RemoveCharacterString(string& str, char ch, int ind = 0, string result = "") {
    if (ind >= str.size())return result;
    if (str[ind] != ch)
        result += str[ind];
    return RemoveCharacterString(str, ch, ind + 1, result);
}

// 17. Reverse a string recursively
// Problem: Reverse all characters in the given string.
// Input: "hello"
// Output: "olleh"
string ReverseString(string& str, int ind = 0, string res = "") {
    if (ind >= str.size())return res;
    res = str[ind] + res;
    return ReverseString(str, ind + 1, res);
}

// 18. Check palindrome recursively
// Problem: Determine whether a string reads the same forward and backward.
// Input: "madam"
// Output: true
bool palindromePart(string str, int st, int ed) {
    if (ed <= st)return true;
    if (str[st] == str[ed]) {
        return palindromePart(str, st + 1, ed - 1);
    }
    return false;
}
bool isPalindromeString(string str) {
    return palindromePart(str, 0, str.size() - 1);
}
// 19. GCD using recursion
// Problem: Find the greatest common divisor of two positive integers.
// Input: 48, 18
// Output: 6
int GCDs(int a, int b) {
    if (a == 0)return b;
    if (b == 0)return a;
    if (a > b) {
        swap(a, b);
    }
    return GCDs(a, b - a);
}

int GCDd(int a, int b) {
    if (b == 0)return a;
    return GCDd(b, a % b);
}
// 20. Fibonacci
// Problem: Find the Fibonacci number at position n, where F(0)=0 and F(1)=1.
// Input: 7
// Output: 13
int fibonacci(int n) {
    if (n == 0)return 0;
    if (n == 1)return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

//      Level 3 — Choose / Don't Choose Recursion

// 21. Generate all subsequences of a string
// Problem: Generate every possible subsequence of the given string, including the empty string.
// Input: "abc"
// Output: ["", "a", "b", "c", "ab", "ac", "bc", "abc"]
void GenerateSubseuences(string& str, vector<string>& result, int ind = 0, string re = "") {
    if (ind >= str.size()) {
        result.push_back(re);
        return;
    }
    re += str[ind];
    GenerateSubseuences(str, result, ind + 1, re);
    re.pop_back();
    GenerateSubseuences(str, result, ind + 1, re);
}

// 22. Generate all subsets of an array
// Problem: Generate every possible subset of the given array, including the empty subset.
// Input: [1, 2, 3]
// Output: [[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]]
void GenerateAllSubsetsArray(vector<int>& arr, vector<vector<int>>& result, vector<int> re = {}, int ind = 0) {
    if (ind >= arr.size()) {
        result.push_back(re);
        return;
    }
    re.push_back(arr[ind]);
    GenerateAllSubsetsArray(arr, result, re, ind + 1);
    re.pop_back();
    GenerateAllSubsetsArray(arr, result, re, ind + 1);
}

// 23. Generate all binary strings of length n
// Problem: Generate all binary strings containing exactly n characters.
// Input: 3
// Output: ["000", "001", "010", "011", "100", "101", "110", "111"]
void BinaryStrings(int n, vector<string>& result, string re = "", int id = 0) {
    if (re.size() >= n) {
        result.push_back(re);
        return;
    }
    re += "0";
    BinaryStrings(n, result, re);
    re.pop_back();
    re += "1";
    BinaryStrings(n, result, re);
    re.pop_back();

}

// 24. Generate all combinations
// Problem: Given an array and a number r, generate all combinations containing exactly r elements.
// Input: arr = [1,2,3,4], r = 2
// Output: [[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]

void Combinations(vector<int>& arr, int r, vector<vector<int>>& result, vector<int> res = {}, int ind = 0) {
    if (res.size() >= r) {
        result.push_back(res);
        return;
    }
    if (ind >= arr.size()) {
        return;
    }
    res.push_back(arr[ind]);
    Combinations(arr, r, result, res, ind + 1);
    res.pop_back();
    Combinations(arr, r, result, res, ind + 1);

}

// 25. Generate permutations
// Problem: Generate every possible ordering of the elements in the array.
// Input: [1, 2, 3]
// Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
void Permutations(vector<int>& arr, vector<vector<int>>& result, int ind = 0) {
    if (ind >= arr.size()) {
        result.push_back(arr);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        swap(arr[i], arr[ind]);
        Permutations(arr, result, ind + 1);
        swap(arr[i], arr[ind]);
    }

}

// 26. Letter combinations of a phone number
// Problem: Each digit from 2 to 9 represents letters on a phone keypad. Generate all possible letter combinations.
// Input: "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
string latters(char ch) {
    switch (ch)
    {
    case '2':
        return "abc";
    case '3':
        return "def";
    case '4':
        return "ghi";
    case '5':
        return "hkl";
    case '6':
        return "mno";
    case '7':
        return "pqrs";
    case '8':
        return "tuv";
    case '9':
        return "wxyz";
    default:
        return "";
    }
}
void combinationsPhoneNumber(string& str, vector<string>& result, string res = "", int ind = 0) {
    if (ind >= str.size()) {
        result.push_back(res);
        return;
    }
    string s = latters(str[ind]);
    for (int i = 0; i < s.size(); i++)
    {
        res += s[i];
        combinationsPhoneNumber(str, result, res, ind + 1);
        res.pop_back();
    }
}

// 27. Subset Sum
// Problem: Generate the sums of all possible subsets of the given array.
// Input: [1, 2, 3]
// Output: [0, 1, 2, 3, 3, 4, 5, 6]
void SubsetSum(vector<int>& arr, vector<int>& result, int res = 0, int ind = 0) {
    if (ind >= arr.size()) {
        result.push_back(res);
        return;
    }
    res += arr[ind];
    SubsetSum(arr, result, res, ind + 1);
    res -= arr[ind];
    SubsetSum(arr, result, res, ind + 1);
}

// Level 4 — Recurrence-thinking problems
// 28. Elimination Game
// Problem: Start with numbers 1 to n. Repeatedly eliminate every second number from alternating directions. Find the last remaining number.
// Input: n = 9
// Output: 6
int Elimination(int n, int head = 1, int step = 1, bool left = true)
{
    if (n == 1)
        return head;
    if (left || (n % 2 == 1))
        head += step;

    step *= 2;
    n /= 2;

    return Elimination(n, head, step, !left);
}


// 29. Josephus Problem
// Problem: n people stand in a circle. Starting from the first person, eliminate every k-th person until one remains.
// Input: n = 5, k = 2
// Output: 3

int JosephusPart(int n, int k) {
    if (n <= 1) return 0;
    return (JosephusPart(n - 1, k) + k) % n;
}
int Josephus(int n, int k) {
    return JosephusPart(n, k) + 1;
}

// 30. Tower of Hanoi
// Problem: Move all disks from one tower to another while following the Tower of Hanoi rules.
// Input: n = 3
// Output: 7 moves
int towerOfHanoi(int n) {
    if (n <= 0)return 0;
    int sum = towerOfHanoi(n - 1);
    sum++;
    sum += towerOfHanoi(n - 1);
    return sum;
}
int towerOfHanoiMath(int n) {
    return pow(2, n) - 1;
}

// 31. K-th symbol in grammar
// Problem: A binary grammar generates rows recursively. Find the symbol at position k in row n.
// Input: n = 4, k = 5
// Output: 1

bool K_thSymbolInGrammer(int n, int k) {
    if (n <= 1)return false;
    int half = pow(2, n - 2);
    if (k > half)
        return !K_thSymbolInGrammer(n - 1, k - half);
    return K_thSymbolInGrammer(n - 1, k);
}

// 32. K-th character in string
// Problem: A string is repeatedly transformed according to a recursive rule. Find the character at position k.
// Input: n = 3, k = 5
// Output: b

char kthCharacter(int n, int k) {
    if (n == 1)return 'a';
    int half = pow(2, n - 2);
    if (k > half) {
        int s = ((kthCharacter(n - 1, k - half) - 'a') + 1) % 26;
        return toascii(s + 'a');
    }
    return kthCharacter(n - 1, k);
}
// 33. Recursive binary-number problems
// Problem: Generate or analyze binary numbers recursively according to the given length or position.
// Input: n = 3
// Output: 000, 001, 010, 011, 100, 101, 110, 111
void binary_number(int n, vector<string>& result, string res = "") {
    if (res.size() == n) {
        result.push_back(res);
        return;
    }
    if (res.size() > n) {
        return;
    }
    res += "0";
    binary_number(n, result, res);
    res.pop_back();
    res += "1";
    binary_number(n, result, res);
}
// 34. Divide/reduce problems
// Problem: Solve a problem by repeatedly reducing the input into a smaller problem until reaching a base case.
// Input: n = 16
// Output: 4

//       Level 5 — Recursion → DP

// 35. Climbing Stairs
// Problem: You can climb either 1 or 2 stairs at a time. Find how many different ways can reach the top.
// Input: n = 5
// Output: 8
int ClimbingStairs(int n) {
    if (n <= 2)return n;
    return ClimbingStairs(n - 1) + ClimbingStairs(n - 2);
}
// 36. Frog Jump
// Problem: A frog starts at the first stone and can jump to the next stone or skip one stone. Find the minimum cost to reach the last stone.
// Input: heights = [10, 30, 20, 40]
// Output: 30

int FrogJump(vector<int>& arr, int n = 0) {
    if (n >= arr.size())return 0;
    int take = FrogJump(arr, n + 1);
    int skip = FrogJump(arr, n + 2);
    return min(skip, take) + arr[n];
}
// 37. House Robber
// Problem: Rob houses to maximize money, but you cannot rob two adjacent houses.
// Input: [2, 7, 9, 3, 1]
// Output: 12


int HouseRobber(vector<int>& arr, int n = 0) {
    if (n >= arr.size())return 0;
    int skip = HouseRobber(arr, n + 1);
    int take = HouseRobber(arr, n + 2) + arr[n];
    return max(skip, take);
}
// 38. 0/1 Knapsack
// Problem: Choose items with given weights and values without exceeding the maximum capacity. Each item can be chosen at most once.
// Input: weights=[2,3,4], values=[4,5,7], capacity=5
// Output: 9
int knapsack(vector<int>& weights, vector<int>& values, int capacity, int ind = 0) {
    if (ind >= weights.size())return INT_MIN;
    if (capacity == 0)return 0;
    if (capacity < 0)return INT_MIN;
    int skip = knapsack(weights, values, capacity, ind + 1);
    int take = INT_MIN;
    if (capacity >= weights[ind]) {
        take = knapsack(weights, values, capacity - weights[ind], ind + 1) + values[ind];
    }
    return max(skip, take);
}

// 39. Coin Change
// Problem: Find the minimum number of coins needed to make the given amount.
// Input: coins=[1,2,5], amount=11
// Output: 3
// NOTE again do it
int CoinChange(vector<int>& arr, int amount) {
    if (amount == 0)return 0;
    int ans = INT_MAX;
    if (amount < 0)return INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int subAns = CoinChange(arr, amount - arr[i]);
        if (subAns != INT_MAX)
            ans = min(ans, subAns) + 1;
    }
    return ans;
}

// 40. Unique Paths
// Problem: A robot moves only right or down in a grid. Find the number of different paths from the top-left to the bottom-right.
// Input: m = 3, n = 3
// Output: 6
int UniquePaths(int n, int m) {
    if (n == 1 || m == 1)return 1;
    int moveR = UniquePaths(n, m - 1);
    int moveD = UniquePaths(n - 1, m);
    return moveR + moveD;

}
// 41. Longest Common Subsequence
// Problem: Find the length of the longest subsequence that appears in both strings in the same order.
// Input: text1="abcde", text2="ace"
// Output: 3

int LCS(string& str1, string& str2, int n1 = 0, int n2 = 0) {
    if (n1 >= str1.size() || n2 >= str2.size())return 0;
    if (str1[n1] == str2[n2])
        return LCS(str1, str2, n1 + 1, n2 + 1) + 1;
    int skip1 = LCS(str1, str2, n1 + 1, n2);
    int skip2 = LCS(str1, str2, n1, n2 + 1);
    return max(skip1, skip2);
}

// 42. Longest Increasing Subsequence
// Problem: Find the length of the longest subsequence whose values are strictly increasing.
// Input: [10,9,2,5,3,7,101,18]
// Output : 4


int LIS(vector<int>& arr, int ind = 0, int prevous = 0) {
    if (ind >= arr.size())return 0;
    int skip = LIS(arr, ind + 1, prevous);
    int take = 0;
    if (arr[ind] > prevous) {
        take = LIS(arr, ind + 1, arr[ind]) + 1;
    }
    return max(skip, take);
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    return 0;
}
