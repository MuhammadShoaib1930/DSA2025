#include <iostream>
#include <vector>
using namespace std;
class Expression {
    int symbolsValue(char s) {
        int result = 0;
        switch (s) {
            case '{':
            case '}':
                return -3;
            case '[':
            case ']':
                return -2;
            case '(':
            case ')':
                return -1;
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
            default:
                return 0;
        }
    }
    bool isOpenBrackets(char ch) {
        if (ch == '(' || ch == '{' || ch == '[')
            return true;
        else
            return false;
    }
    bool isClosedBrackets(char ch) {
        if (ch == ')' || ch == '}' || ch == ']')
            return true;
        else
            return false;
    }

   public:
    string infixToPostfix(string exp) {
        vector<char> stk;
        string result;

        for (char ch : exp) {
            if (symbolsValue(ch) == 0) {  // operand
                result += ch;
            } else if (isOpenBrackets(ch)) {
                stk.push_back(ch);
            } else if (isClosedBrackets(ch)) {
                while (!stk.empty() && !isOpenBrackets(stk.back())) {
                    result += stk.back();
                    stk.pop_back();
                }
                if (!stk.empty()) stk.pop_back();  // pop open bracket
            } else {                               // operator
                while (!stk.empty() && !isOpenBrackets(stk.back()) &&
                       symbolsValue(stk.back()) >= symbolsValue(ch)) {
                    result += stk.back();
                    stk.pop_back();
                }
                stk.push_back(ch);
            }
        }

        while (!stk.empty()) {
            result += stk.back();
            stk.pop_back();
        }

        return result;
    }
};
