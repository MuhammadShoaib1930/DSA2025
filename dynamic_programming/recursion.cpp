

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
int pd(int n) {
    if (n == 0)return 1;
    return pd(n - 1) + 1;
}
int countDigit(int n) {
    return (n < 0) ? pd(abs(n)) : pd(n);
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
void print1ToN(int n, int s = 1) {
    if (s > n) return;
    cout << s << " ";
    print1ToN(n - 1);
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
bool isPalindromeString(string& str, int st = 0, int ed = -10) {
    if (ed == -10) {
        ed = str.size() - 1;
    }
    if (ed >= st)return true;
    if (str[st] == str[ed]) {
        return isPalindromeString(str, st + 1, ed - 1);
    }
    else {
        return false;
    }

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

void Combinations(vector<int>& arr, int r, vector<vector<int>>& result, vector<int> res = {}, int ind=0) {
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
        Permutations(arr, result, ind+1);
        swap(arr[i], arr[ind]);
    }

}

// 26. Letter combinations of a phone number
// Problem: Each digit from 2 to 9 represents letters on a phone keypad. Generate all possible letter combinations.
// Input: "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 

// 27. Subset Sum
// Problem: Generate the sums of all possible subsets of the given array.
// Input: [1, 2, 3]
// Output: [0, 1, 2, 3, 3, 4, 5, 6]

// Level 4 — Recurrence-thinking problems
// 28. Elimination Game
// Problem: Start with numbers 1 to n. Repeatedly eliminate every second number from alternating directions. Find the last remaining number.
// Input: n = 9
// Output: 6

// 29. Josephus Problem
// Problem: n people stand in a circle. Starting from the first person, eliminate every k-th person until one remains.
// Input: n = 5, k = 2
// Output: 3

// 30. Tower of Hanoi
// Problem: Move all disks from one tower to another while following the Tower of Hanoi rules.
// Input: n = 3
// Output: 7 moves

// 31. K-th symbol in grammar
// Problem: A binary grammar generates rows recursively. Find the symbol at position k in row n.
// Input: n = 4, k = 5
// Output: 1

// 32. K-th character in string
// Problem: A string is repeatedly transformed according to a recursive rule. Find the character at position k.
// Input: n = 3, k = 5
// Output: b

// 33. Recursive binary-number problems
// Problem: Generate or analyze binary numbers recursively according to the given length or position.
// Input: n = 3
// Output: 000, 001, 010, 011, 100, 101, 110, 111

// 34. Divide/reduce problems
// Problem: Solve a problem by repeatedly reducing the input into a smaller problem until reaching a base case.
// Input: n = 16
// Output: 4

//       Level 5 — Recursion → DP

// 35. Climbing Stairs
// Problem: You can climb either 1 or 2 stairs at a time. Find how many different ways can reach the top.
// Input: n = 5
// Output: 8

// 36. Frog Jump
// Problem: A frog starts at the first stone and can jump to the next stone or skip one stone. Find the minimum cost to reach the last stone.
// Input: heights = [10, 30, 20, 40]
// Output: 30

// 37. House Robber
// Problem: Rob houses to maximize money, but you cannot rob two adjacent houses.
// Input: [2, 7, 9, 3, 1]
// Output: 12

// 38. 0/1 Knapsack
// Problem: Choose items with given weights and values without exceeding the maximum capacity. Each item can be chosen at most once.
// Input: weights=[2,3,4], values=[4,5,7], capacity=5
// Output: 9

// 39. Coin Change
// Problem: Find the minimum number of coins needed to make the given amount.
// Input: coins=[1,2,5], amount=11
// Output: 3

// 40. Unique Paths
// Problem: A robot moves only right or down in a grid. Find the number of different paths from the top-left to the bottom-right.
// Input: m = 3, n = 3
// Output: 6

// 41. Longest Common Subsequence
// Problem: Find the length of the longest subsequence that appears in both strings in the same order.
// Input: text1="abcde", text2="ace"
// Output: 3

// 42. Longest Increasing Subsequence
// Problem: Find the length of the longest subsequence whose values are strictly increasing.
// Input: [10,9,2,5,3,7,101,18]
// Output : 4

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> arr = { 1,2,3 };
    vector<vector<int>> result;
    Permutations(arr, result);
    for (auto&& i : result)
    {
        for (auto&& j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }



    return 0;
}
