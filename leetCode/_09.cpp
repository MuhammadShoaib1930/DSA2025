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
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string res = "";
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        res += (sum % 2) + '0';
        carry = sum / 2;
    }
    i = 0, j = res.size() - 1;
    while (i < j) {
        char ch = res[i];
        res[i] = res[j];
        res[j] = ch;
        i++, j--;
    }

    return res;
}
