



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

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> num = { 2,6,2,1};
    cout << repeatedNTimes(num);
    return 0;
}
// g++ mainCode.cpp -o mainCode && .\mainCode
