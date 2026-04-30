// 20. Valid Parentheses
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid. An input string is valid if: Open
brackets must be closed by the same type of brackets. Open brackets must be
closed in the correct order. Every close bracket has a corresponding open
bracket of the same type. Example 1: Input: s = "()" Output: true Example 2:
Input: s = "()[]{}"
Output: true
Example 3:
Input: s = "(]"
Output: false
Example 4:
Input: s = "([])"
Output: true
Example 5:
Input: s = "([)]"
Output: false
Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool isValid(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stk.push(s[i]);
        } else if (!stk.empty()) {
            if (s[i] == ')' && stk.top() == '(' ||
                s[i] == ']' && stk.top() == '[' ||
                s[i] == '}' && stk.top() == '{') {
                stk.pop();
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    if (stk.empty()) {
        return true;

    } else {
        return false;
    }
}
