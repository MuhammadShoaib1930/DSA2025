

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

// 2. Sum 1...n
int sum(int n) {
    if (n == 0)return 0;
    if (n < 0) {
        return sum(n + 1) + n;

    }
    else {

        return sum(n - 1) + n;
    }
}
// 3. Power a^n
int partPower(int a, int b) {
    if (b == 0)return 1;
    return partPower(a, b - 1) * a;

}
float power(int a, int n) {
    int b = (a < 0) ? -1 : 1;
    int result = partPower(abs(a), abs(n)) * b;
    return (n < 0) ? (1 / (float)result) : result;
}
// 4. Sum of digits
int sumOfDigits(int n) {
    if (n == 0)return 0;
    return sumOfDigits(n / 10) + (n % 10);
}
// 5. Count digits
int countDigits(int n) {
    if (n == 0) { return 0; }
    return countDigits(n / 10) + 1;
}
// 6. Reverse a number
int reversANumber(int n, int result = 0) {
    if (n < 10 && n>-10)return n + result;
    result += (n % 10);
    return reversANumber(n / 10, result * 10);
}
// 7. Print numbers 1 → n
void printNumber1ToN(int n, int i = 1) {
    if (i > n)return;
    cout << i << " ";
    printNumber1ToN(n, i + 1);
}
// 8. Print numbers n → 1
void printNumberNTo1(int n) {
    if (n == 0)return;
    cout << n << " ";
    printNumberNTo1(n - 1);
}
// 9. Find max in an array recursively
int FindMaxValueInArray(vector<int>& arr, int i = 0, int v = INT_MIN) {
    if (i >= arr.size())return v;
    v = max(v, arr[i]);
    return FindMaxValueInArray(arr, i + 1, v);
    return 0;
}
// 10. Find sum of an array recursively
int FindSumOfArray(vector<int>& arr, int i = 0) {
    if (i >= arr.size())return 0;
    return FindSumOfArray(arr, i + 1) + arr[i];
}

// 12. Check if an array is sorted
bool partIsSortArray(vector<int>& arr, int i, bool isAsd) {
    if (i >= arr.size() - 1) {
        return true;
    }
    if (isAsd) {
        return (arr[i] < arr[i + 1]) ? partIsSortArray(arr, i + 1, isAsd) : false;
    }
    else {
        return (arr[i] > arr[i + 1]) ? partIsSortArray(arr, i + 1, isAsd) : false;
    }
}
bool CheckIfArrayIsSorted(vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return true;
    return partIsSortArray(arr, 0, (arr[0] < arr[1]));
}
// 14. Find last occurrence of an element

int FindLastOccurrenceOfElement(vector<int>& arr, int target, int result = -1, int i = 0) {
    if (i >= arr.size()) return result;
    result = (arr[i] == target) ? i : result;

    return FindLastOccurrenceOfElement(arr, target, result, i + 1);
}

// 15. Count occurrences of an element
int CountOccurrencesOfElement(vector<int>& arr, int target, int i = 0, int result = 0) {
    if (i >= arr.size())return result;
    result = (arr[i] == target) ? result + 1 : result;

    return CountOccurrencesOfElement(arr, target, i + 1, result);
}
// 16. Remove a character from a string
string RemoveACharacterFromAString(string str, char ch, string result = "", int i = 0) {
    if (i >= str.size())return result;
    result = (ch != str[i]) ? result + str[i] : result;
    return RemoveACharacterFromAString(str, ch, result, i + 1);
}
// 17. Reverse a string recursively
string ReverseAString(string& str, string result = "", int i = 0) {
    if (i >= str.size())return result;
    result = str[i] + result;
    return ReverseAString(str, result, i + 1);

}
// 19. GCD using recursion
// GCD(a, b) = GCD(b, a % b)
int GCD(int a, int b) {
    if (a == 0)return b;
    if (b == 0)return a;
    if (a > b) {
        a = a - b;
        swap(a, b);
    }
    else {
        b = b - a;
    }
    return GCD(a, b);
}




// 21. Generate all subsequences of a string
// abc
// "", "a", "b", "c",
// "ab", "ac", "bc", "abc"
void GenerateAllSubsequencesOfAString(string& str, vector<string>& result, int s = 0, string re = "") {
    if (s >= str.size()) {
        result.push_back(re);
        return;
    };
    ;
    re += str[s];
    GenerateAllSubsequencesOfAString(str, result, s + 1, re);
    re.erase(re.end() - 1);
    GenerateAllSubsequencesOfAString(str, result, s + 1, re);

}
// 22. Generate all subsets of an array
void GenerateAllSubsetsOfAnArray(vector<string> arr, vector<string>& result, int s = 0) {
    if (s >= arr.size()) {
        string res = "";
        for (auto&& i : arr)
        {
            res += i;
        }
        result.push_back(res);
        return;
    }
    for (int i = s; i < arr.size(); i++)
    {

        swap(arr[i], arr[s]);
        GenerateAllSubsetsOfAnArray(arr, result, s + 1);
        swap(arr[i], arr[s]);
    }

}

// 23. Generate all binary strings of length n
void GenerateAllBinaryStringsOfLengthN(int n, vector<string>& result, int s = 0, string res = "") {
    if (res.size() == n) {
        result.push_back(res);
        return;
    }
    res += "0";
    GenerateAllBinaryStringsOfLengthN(n, result, s + 1, res);
    res.erase(res.end() - 1);
    res += "1";
    GenerateAllBinaryStringsOfLengthN(n, result, s + 1, res);

}
// 24. Generate all combinations
void GenerateAllCombinations(vector<int>& arr, int r, vector<vector<int>>& result, int s = 0) {
    if (s >= r) {
        vector<int> res;
        for (int i = 0; i < r; i++)
        {
            res.push_back(arr[i]);
            /* code */
        }
        result.push_back(res);

        return;
    }
    for (int i = s; i < arr.size(); i++)
    {
        swap(arr[i], arr[s]);
        GenerateAllCombinations(arr, r, result, s + 1);
        swap(arr[i], arr[s]);
    }


}
// 25. Generate permutations
void GeneratePermutaions(vector<int>& arr, vector<vector<int>>& result, int s = 0) {
    if (s >= arr.size()) {
        result.push_back(arr);
        return;
    }
    for (int i = s; i < arr.size(); i++)
    {
        swap(arr[i], arr[s]);
        GeneratePermutaions(arr, result, s + 1);
        swap(arr[i], arr[s]);
    }

}

// 27. Subset Sum
void subsetSum(vector<int>& arr, vector<int>& result, int res = 0, int s = 0) {
    if (s >= arr.size()) {
        result.push_back(res);
        return;
    }
    res += arr[s];
    subsetSum(arr, result, res, s + 1);
    res -= arr[s];
    subsetSum(arr, result, res, s + 1);

}
// 20. Fibonacci
int Fibonacci(int n) {
    if (n == 0)return 0;
    if (n == 1)return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
// 11. Binary Search recursively
int BinarySearch(vector<int>& arr, int target, int st = 0, int ed = -10) {
    if (ed == -10) {
        ed = arr.size() - 1;
    }
    if (st > ed) {
        return -1;
    }
    int mid = st + (ed - st) / 2;
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
// 13. Find first occurrence of an element
int FindFirstOccurraenceOfAnElement(vector<int>& arr, int target, int s = 0) {
    if (s >= arr.size()) {
        return -1;
    }
    if (arr[s] == target) {
        return s;
    }
    else {
        return FindFirstOccurraenceOfAnElement(arr, target, s + 1);
    }
}
// 18. Check palindrome recursively
bool CheckPalindrome(string& str, int st=0, int ed=-10 ) {
    if (ed == -10) {
        ed = str.size()-1;
    }
    if (st >= ed) {
        return true;
    }
    if (str[st] != str[ed]) {
        return false;
    }

    return CheckPalindrome(str, st+1, ed-1);
}
// 1. Factorial of n
int Factorial(int n) {
    if (n == 0) return 0;
    if (n == 1)return 1;
    return Factorial(n - 1) * n;
}
// 26. Letter combinations of a phone number

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> arr = { 1,2,3,4,1,2,3,5 };
    string str = "aaabbaaa";
    cout << Factorial(0) << endl;
    cout << Factorial(1) << endl;
    cout << Factorial(2) << endl;
    cout << Factorial(3) << endl;
    cout << Factorial(4) << endl;
    cout << Factorial(5) << endl;




    return 0;
}
