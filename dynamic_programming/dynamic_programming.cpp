


#include <iostream>
#include <vector>
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
    vector<int> dp = vector<int>(n , -1);
    dp[0] = 1, dp[1] = 2;
    for (int i = 2; i < n; i++)
    {

        dp[i] = dp[i - 1] + (i)*dp[i - 2];
    }

    return dp[n-1];

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    cout << pairFriendsTabulation(0) << endl;
    cout << pairFriendsTabulation(1) << endl;
    cout << pairFriendsTabulation(2) << endl;
    cout << pairFriendsTabulation(3) << endl;
    cout << pairFriendsTabulation(4) << endl;
    cout << pairFriendsTabulation(5) << endl;

    return 0;
}
