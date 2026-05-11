/*
Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/
#include <iostream>
#include <string>
using namespace std;

bool isPalandrom(string s) {
    int i = 0, j = s.size() - 1;
    while (i <= j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
string longestPalindrome(string s) {
    string result = "";
    if (s.size() < 2) return s;
    int i = 0;
    int j = s.size() - 1;
    while (i <= j) {
        if (s[i] == s[j]) {
            string max = s.substr(i, j - i + 1);
            result = (max.size() < result.size()) ? result : max;
        }else if(s[i] == s[j-1]){
            j--;
        }else if(s[i+1]==s[j]){
            i++;
        }else{
            j--, i++;
        }
    }

    return result;
}
