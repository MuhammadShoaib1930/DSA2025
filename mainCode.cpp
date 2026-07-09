#include <iostream>
#include <vector>

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
    if (s.empty())return 0;
    if (!(s[0] >= '0' && s[0] <= '9') && !(s[0] == ' ' || s[0] == '+' || s[0] == '-')) {
        return 0;
    }
    int i = 0;
    while (i < s.size() && s[i] == ' ')
    {
        i++;
    }
    int result = INT_MIN;
    bool isNagative = false;
    while (i < s.size())
    {

        if (s[i] == '-' || s[i] == '+') {
            if (isNagative || result > -1) return  (isNagative) ? -result : result;
            if (s[i] == '-') {
                isNagative = true;

            }
            else {
                isNagative = false;
            }

        }
        else if (s[i] >= '0' && s[i] <= '9') {
            if (result == INT_MIN) {
                result = 0;
            }
            result = result * 10 + (s[i] - '0');
        }
        else {
            return (isNagative) ? -result : result;
        }
        i++;
    }
    return (isNagative) ? -result : result;


}
int main() {
    // cout <<"123 "<< myAtoi("123")<<endl;
    // cout <<"-123 "<< myAtoi("-123")<<endl;
    // cout <<"0 "<< myAtoi("0")<<endl;
    // cout <<"00-1 "<< myAtoi("00-1")<<endl;
    // cout <<"0-123 "<< myAtoi("0-123")<<endl;
    cout << "42 " << myAtoi("42") << endl;
    // cout <<"0a123 "<< myAtoi("0a123")<<endl;
    // cout <<"0-1-23 "<< myAtoi("0-1-23")<<endl;
    // vector<int> db = vector<int>(7, -1);
    // int f = fib(6, db);
    // cout << endl << f <-< endl;
    return 0;
}
// 1 hours completed video
