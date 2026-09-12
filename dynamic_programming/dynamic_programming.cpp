

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
#include "my_algo.cpp"
using namespace std;
int fibonacciRecursion(int n) {

    if (n < 2)return n;
    return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}
int fibonacciMemoiazation(int n, vector<int> dp) {
    if (n < 2)return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibonacciMemoiazation(n - 1, dp) + fibonacciMemoiazation(n - 2, dp);
}
int fibonacciTabulation(int n) {
    if (n < 2)return n;
    vector<int> dp = vector<int>(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int minCostStairsPart(vector<int> arr, int n) {
    if (n < 0)return 0;
    return arr[n] + min(minCostStairsPart(arr, n - 1), minCostStairsPart(arr, n - 2));
}
int minCostStairsRecursion(vector<int> arr) {
    int n = arr.size() - 1;
    return min(minCostStairsPart(arr, n), minCostStairsPart(arr, n - 1));
}


int minCostMemoiazationPart(vector<int> arr, int n, int dp[]) {
    if (n < 0)return 0;
    if (dp[n] != -1)return dp[n];
    return dp[n] = arr[n] + min(minCostMemoiazationPart(arr, n - 1, dp), minCostMemoiazationPart(arr, n - 2, dp));
}
int minCostStairsMemoiazation(vector<int> arr) {
    int n = arr.size() - 1;
    int dp[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = -1;
    }


    return min(minCostMemoiazationPart(arr, n, dp), minCostMemoiazationPart(arr, n - 1, dp));
}
int minCostStairsTabulation(vector<int> cost) {
    int n = cost.size();
    if (n < 2) return min(cost[0], cost[1]);
    for (int i = 2; i < n; i++)
    {
        cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
    }
    return min(cost[n - 1], cost[n - 2]);
}

int maxStairs(vector<int> arr, int n) {
    if (n < 0)return 0;
    int skip = maxStairs(arr, n - 1);
    int take = arr[n] + maxStairs(arr, n - 2);
    return  max(skip, take);
}
int robbryRecursion(vector<int> arr) {
    return maxStairs(arr, arr.size() - 1);
}


int maxStairs(vector<int> arr, int n, vector<int> dp) {
    if (n < 0)return 0;
    if (dp[n] != -1) {
        return dp[n];
    }
    int skip = maxStairs(arr, n - 1);
    int take = arr[n] + maxStairs(arr, n - 2);
    return dp[n] = max(skip, take);
}
int robbryMemoiazation(vector<int> arr) {
    int n = arr.size();
    vector<int> dp = vector<int>(n, -1);
    return maxStairs(arr, n - 1, dp);
}

int robbryTabulation(vector<int> arr) {
    int n = arr.size();
    if (n < 0)return 0;
    if (n == 1)return arr[0];
    if (n == 2)return max(arr[0], arr[1]);
    arr[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i] + arr[i - 2];
    }
    return max(arr[n - 1], arr[n - 2]);
}
int pairFriendsRecursion(int n) {
    if (n < 1)return 0;
    if (n < 3)return n;
    return pairFriendsRecursion(n - 1) + (n - 1) * pairFriendsRecursion(n - 2);
}

int pairFriendsPart(int n, vector<int> dp) {
    if (n < 1)return 0;
    if (n < 3)return n;
    if (dp[n] != -1)return dp[n];
    return  dp[n] = pairFriendsPart(n - 1, dp) + (n - 1) * pairFriendsPart(n - 2, dp);
}
int pairFriendsMemoization(int n) {
    vector<int> dp = vector<int>(n + 1, -1);
    return pairFriendsPart(n, dp);
}


int pairFriendsTabulation(int n) {
    if (n < 3)return n;
    vector<int> dp = vector<int>(n, -1);
    dp[0] = 1, dp[1] = 2;
    for (int i = 2; i < n; i++)
    {

        dp[i] = dp[i - 1] + (i)*dp[i - 2];
    }

    return dp[n - 1];

}






void removePart(ListNode* head, int val) {
    if (head == NULL) {
        return;
    }

    if (head->next != NULL && head->next->val == val) {
        head->next = head->next->next;
        removePart(head, val);
    }
    else {
        removePart(head->next, val);

    }
}
ListNode* removeElements(ListNode* head, int val) {
    if (head == NULL)return head;
    removePart(head, val);
    if (head->val == val) {
        head = head->next;
    }
    return head;
}
ListNode* reversHelper(ListNode* p, ListNode* c) {
    if (c->next == NULL) {
        c->next = p;
        return c;
    }
    ListNode* n = c->next;
    c->next = p;
    return reversHelper(c, n);
}
ListNode* reverseList(ListNode* head) {
    if (head == NULL)return head;
    if (head->next == NULL) {
        return head;
    }
    ListNode* c = head->next;
    ListNode* p = head;
    p->next = NULL;
    ListNode* h = reversHelper(p, c);
    return h;
}

bool powerPart(int n, long unsigned int p = 1) {
    if (n == p)return true;
    if (n < p)return false;
    return powerPart(n, p * 2);
}
bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    return powerPart(n);
}
bool isPowerOfTwoMath(int n) {
    return (n > 0 && (n & (n - 1) == 0));
}


ListNode* reversNode(ListNode* p, ListNode* c) {
    if (c->next == NULL) {
        c->next = p;
        return c;
    }
    ListNode* n = c->next;
    c->next = p;
    return reversNode(c, n);
}
ListNode* midPointer(ListNode* s, ListNode* f) {
    if (f == NULL) return s;
    if (f->next == NULL) return s->next;
    return midPointer(s->next, f->next->next);
}
bool plandormPart(ListNode* f, ListNode* m) {
    if (f->next == NULL || m->next == NULL)        return (f->val == m->val);
    return (f->val == m->val) ? plandormPart(f->next, m->next) : false;
}
bool isPalindrome(ListNode* head) {
    if (head == NULL)return false;
    if (head->next == NULL)return true;
    return plandormPart(head, reversNode(NULL, midPointer(head, head)));
}

bool isPowerOfThree(int n) {
    if (n < 1)return false;
    if (n == 1)return true;
    return (n % 3 == 0) ? isPowerOfThree(n / 3) : false;
}
bool isPowerOfFour(int n) {
    if (n < 0)return false;
    if (n == 1)return true;
    return (n % 4 == 0) ? isPowerOfFour(n / 4) : false;
}
//Note Recursion
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
//Note Memoiazation

int fibPart(int n, vector<int> dp) {
    if (n <= 1)return n;
    if (dp[n] != -1)return dp[n];
    int s1 = fibPart(n - 1, dp);
    int s2 = fibPart(n - 2, dp);
    dp[n] = s1 + s2;
    return dp[n];

}
int fibm(int n) {
    vector<int> dp = vector<int>(n + 1, -1);
    return fibPart(n, dp);
}
// Note tabulation
int fibt(int n) {
    if (n <= 1)return n;
    vector<int> dp = vector<int>(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

char kthCharacter(int k, string word = "a") {
    int n = word.size();
    if (n >= k) {
        return word[k - 1];
    }
    for (int i = 0; i < n; i++)
    {
        word += char(word[i] + 1);
    }
    return kthCharacter(k, word);
}


void partfindEvenNumber(vector<int>& digit, set<int>& result, int count, int start = 0) {
    if (count == 3) {

        int sum = (digit[0] * 100) + (digit[1] * 10) + digit[2];
        result.insert(sum);
        return;
    }


    for (int i = start; i < digit.size(); i++)
    {
        swap(digit[i], digit[start]);
        partfindEvenNumber(digit, result, count + 1, start + 1);
        swap(digit[i], digit[start]);
    }
}
vector<int> findEvenNumbers(vector<int>& digits) {

    set<int> value;
    partfindEvenNumber(digits, value, 0, 0);
    vector<int> result;
    for (auto&& i : value)
    {
        result.push_back(i);
    }



    return result;
}
void partTotalNumbers(vector<int>& digits, set<int>& result, int start = 0, int count = 0) {
    if (count == 3) {
        if (digits[0] != 0 && (digits[2] & 1) == 0) {
            int value = (digits[0] * 100) + (digits[1] * 10) + digits[2];
            result.insert(value);
        }
        return;
    }

    for (int i = start; i < digits.size(); i++)
    {

        swap(digits[i], digits[start]);
        partTotalNumbers(digits, result, start + 1, count + 1);
        swap(digits[i], digits[start]);
    }

}
int totalNumbers(vector<int>& digits) {
    set<int> result;
    partTotalNumbers(digits, result);
    return result.size();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);








    return 0;
}
