/*
Add Binary
Given two binary strings a and b, return their sum as a binary string.



Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;

string addBinary(string a, string b) {
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    string str = "";
    while (i >= 0 && j >= 0) {
        if (carry == 0 && (a[i] == '1' && b[j] == '1')) {
            carry = 1;
            str += '0';
        } else if (carry == 1 && (a[i] == '0' && b[j] == '0')) {
            carry = 0;
            str += '1';
        } else if (carry == 0 && (a[i] == '1' || b[j] == '1')) {
            str += '1';
        } else if (carry == 1 && (a[i] == '1' || b[j] == '1')) {
            str += '1';
        } else if (carry == 1 && (a[i] == '1' && b[j] == '1')) {
            str += '1';
        }
        i--;
        j--;
    }
    while (i >= 0) {
        if (carry == 1 && a[i] == '1') {
            str += '0';
        } else if (carry == 1 && a[i] == '0') {
            carry = 0;
            str += '1';
        } else if (carry == 0 && a[i] == '1') {
            str += '1';
        } else {

            str += '0';
        }
        i--;
    }
    while (j >= 0) {
        if (carry == 1 && b[j] == '1') {
            str += '0';
        } else if (carry == 1 && b[j] == '0') {
            carry = 0;
            str += '1';
        } else if (carry == 0 && b[j] == '1') {
            str += '1';
        } else {
            str += '0';
        }
        j--;
    }
    i = 0;
    j = str.size() - 1;
    while (i<j)
    {
        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i++;
        j--;
    }
    return str;
}
