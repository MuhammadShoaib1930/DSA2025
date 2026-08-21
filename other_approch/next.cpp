



#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <stack>
#include "my_algo.cpp"
#include <list>
#include<cmath>
using namespace std;







// int surfaceArea(vector<vector<int>>& grid) {
//     int n = grid.size();
//     int total = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (grid[i][j] != 0)
//                 total += grid[i][j];
//         }

//     }
//     total *= 6;
//     int hight = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (grid[i][j] != 0)
//                 hight += grid[i][j] - 1;
//         }

//     }
//     hight *= 2;
//     int rowAndColumn = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int temp = grid[i][0];
//         int temp2 = grid[0][i];
//         for (int j = 0; j < n; j++)
//         {
//             if (grid[i][j] != 0) {

//                 temp = min(temp, grid[i][j]);
//                 temp2 = min(temp2, grid[j][i]);
//             }

//         }
//         rowAndColumn += temp + temp2;

//     }
//     rowAndColumn *= 2;
//     total = total - (hight + rowAndColumn);
//     return total;

// }
bool validMountainArray(vector<int>& arr) {
    int n = arr.size();
    if (n < 3)return false;
    int m1 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])return false;
        if (arr[i] > arr[i + 1]) {
            m1 = i; break;
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] == arr[i - 1])return false;
        if (arr[i] > arr[i - 1]) {
            return (m1 != 0) ? (m1 == i) : false;
            break;
        }
    }

    return  false;

}
vector<int> diStringMatch(string s) {
    int n = s.size();
    vector<int> res;

    int i = 0; int j = n;
    for (char& t : s) {
        if (t == 'I') {
            res.push_back(i);
            i++;
        }
        else {
            res.push_back(j);
            j--;
        }
    }
    for (; i <= j; i++)
    {
        res.push_back(i);
    }

    return res;

}
int minDeletionSize(vector<string>& strs) {
    int n = strs.size();
    int m = strs[0].size();
    int count = 0;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (strs[i][j] > strs[i + 1][j]) {
                count++;
                break;
            }
        }

    }

    return count;
}
bool isSorted(string s1, string s2, unordered_map<char, int> alph) {
    int n1 = s1.size();
    int n2 = s2.size();
    int i = 0;
    int j = 0;
    while (i < n1 || j < n2)
    {
        int w1 = alph[s1[i]];
        int w2 = alph[s2[j]];
        if (w1 > w2) {
            return false;
        }
        else if (w1 == w2) {
            if (i < n1 && j >= n2) {
                i++;
            }
            else if (i >= n1 && j < n2) {
                j++;
            }
            else {
                i++, j++;
            }
        }
        else { return true; }
    }
    return (n1 < n2);
}

bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> alph;
    for (int i = 0; i < order.size(); i++)
    {
        alph[order[i]] = i;
    }

    for (int i = 0; i < words.size() - 1; i++)
    {
        if (!isSorted(words[i], words[i + 1], alph)) {
            return false;
        }

    }
    return true;

}




int repeatedNTimes(vector<int>& nums) {
    int maxV = 0;
    for (auto&& i : nums)
    {
        maxV = max(maxV, i);
    }
    vector<int> freq(maxV + 1, 0);
    for (auto&& i : nums)
    {
        freq[i]++;
    }
    int maxF = freq[0];
    int res = 0;
    for (int i = 1; i <= maxV; i++) {
        if (maxF < freq[i]) {
            res = i;
            maxF = freq[i];
        }
    }
    return res;
}
int largestPerimeter(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = n - 3; i >= 0; i--) {
        if (nums[i] + nums[i + 1] > nums[i + 2]) {
            return nums[i] + nums[i + 1] + nums[i + 2];
        }
    }

    return 0;
}

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();

    vector<int> res;
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        int a = nums[i] * nums[i];
        int b = nums[j] * nums[j];
        if (a > b) {
            res.push_back(a);
            i++;
        }
        else {

            res.push_back(b);
            j--;
        }

    }
    i = 0, j = n - 1;
    while (i < j) {
        res[i] = res[i] ^ res[j];
        res[j] = res[i] ^ res[j];
        res[i] = res[i] ^ res[j];
        i++;j--;
    }
    return res;
}
vector<int> addToArrayForm(vector<int>& num, int k) {
    int n = num.size();
    int rem = k;
    vector<int> res;
    for (int i = n - 1; i >= 0; i--)
    {
        int l = rem % 10;
        rem = rem / 10;
        int sum = l + num[i];
        res.push_back(sum % 10);
        rem = rem + (sum / 10);
    }
    while (rem > 0) {

        res.push_back(rem % 10);
        rem /= 10;
    }

    int i = 0;int j = res.size() - 1;
    while (i < j)
    {
        res[i] = res[i] ^ res[j];
        res[j] = res[i] ^ res[j];
        res[i] = res[i] ^ res[j];
        i++, j--;
    }
    return res;

}
int findJudge(int n, vector<vector<int>>& trust) {
    int m = trust.size();
    if (m < 1)
    {
        if (n == 1) {
            return 1;
        }
        else {
            return -1;
        }
    }
    vector<bool> p1(n + 1, false);
    vector<int> pf2(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        p1[trust[i][0]] = true;
        pf2[trust[i][1]]++;
    }
    int res = -1;
    for (int i = 0; i <= n; i++) {
        if (p1[i] == false) {
            if (pf2[i] == n - 1) {
                res = i;
            }
        }
    }
    return res;

}
int numRookCaptures(vector<vector<char>>& board) {
    // R B  p .;
    int row = -1;
    int col = -1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 'R') {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1 && col != -1)break;
    }

    int res = 0;
    int i = row - 1;
    while (i != -1)
    {
        if (board[i][col] == 'B') {
            break;
        }
        else if (board[i][col] == 'p') {
            res++;
            break;
        }
        else {
            i--;
        }
    }
    i = row + 1;
    while (i < 8)
    {
        if (board[i][col] == 'B') {
            break;
        }
        else if (board[i][col] == 'p') {
            res++;
            break;
        }
        else {
            i++;
        }
    }
    i = col - 1;
    while (i > -1)
    {
        if (board[row][i] == 'B') {
            break;
        }
        else if (board[row][i] == 'p') {
            res++;
            break;
        }
        else {
            i--;
        }
    }
    i = col + 1;
    while (i < 8)
    {
        if (board[row][i] == 'B') {
            break;
        }
        else if (board[row][i] == 'p') {
            res++;
            break;
        }
        else {
            i++;
        }
    }





    return res;


}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<char>> num = { {'.','.','.','.','.','.','.','.'},
                                 {'.','.','.','p','.','.','.','.'},
                                 {'.','.','.','R','.','.','.','p'},
                                 {'.','.','.','.','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.'},
                                 {'.','.','.','p','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.' } };
    cout << numRookCaptures(num) << endl;
    num = { {'.','.','.','.','.','.','.','.'},
            {'.','p','p','p','p','p','.','.'},
            {'.','p','p','B','p','p','.','.'},
            {'.','p','B','R','B','p','.','.'},
            {'.','p','p','B','p','p','.','.'},
            {'.','p','p','p','p','p','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'} };
    cout << numRookCaptures(num) << endl;

    num = { {'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'p','p','.','R','.','p','B','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','B','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','.','.','.','.','.'} };
    cout << numRookCaptures(num) << endl;
    num = { {'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','R','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'} };
    cout << numRookCaptures(num) << endl;
    return 0;
}
// g++ mainCode.cpp -o mainCode && .\mainCode
