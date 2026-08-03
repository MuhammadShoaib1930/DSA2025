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

string longestStr(int st, int ed, string s, int n)
{
    string result = "";
    while (st >= 0 && ed < n && s[st] == s[ed])
    {

        result = (char)s[st] + result;
        if (st != ed)
        {
            result = result + (char)s[ed];
        }
        st--, ed++;
    }
    return result;
}

string longestPalindrome(string s)
{
    int n = s.size();
    int i = 0;
    string result = "";
    while (i < n)
    {
        string temp = "";
        temp = longestStr(i, i, s, n);
        if (temp.size() > result.size())
            result = temp;
        temp = longestStr(i, i + 1, s, n);
        if (temp.size() > result.size())
            result = temp;
        i++;
    }
    return result;
}
string convert(string s, int numRows)
{
    int n = s.size();
    if (n <= 1)
        return s;
    vector<string> resultList = vector<string>(numRows + 1, "");
    int st = 0;
    bool isTrue = true;
    for (int i = 0; i < s.size(); i++)
    {
        resultList[st] += s[i];

        if (isTrue)
        {
            st++;
            if (st >= numRows - 1)
                isTrue = false;
        }
        else
        {
            st--;
            if (st <= 0)
                isTrue = true;
        }
    }
    string result = "";
    for (int i = 0; i < resultList.size(); i++)
    {
        result += resultList[i];
    }

    return result;
}
int reverse(int x)
{
    long long int inputValue = (x < 0) ? -(long long int)x : x;
    long long int result = 0;
    while (inputValue > 0)
    {
        result = result * 10 + (inputValue % 10);
        inputValue /= 10;
    }
    if (result != (int)result)
    {
        return 0;
    }
    if (x < 0)
    {
        return -(int)result;
    }
    return (int)result;
}

int myAtoi(string s)
{
    int i = 0, sign = 1, n = s.size();
    long res = 0;
    while (i < n && s[i] == ' ')
        i++;
    if (i >= n)
        return 0;
    if (i < n && s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (i < n && s[i] == '+')
    {
        i++;
    }
    while (i < n && s[i] >= '0' && s[i] <= '0')
    {
        res = res * 10 + (s[i] - '0');
        if (res * sign < INT_MIN)
            return INT_MIN;
        if (res * sign > INT_MAX)
            return INT_MAX;
        i++;
    }
    return (int)(sign * res);
}
bool isMatch(string s, string p)
{
    int i = s.size() - 1;
    int j = p.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (s[i] == p[j] || p[j] == '.')
        {
            i--;
            j--;
        }
        else if (p[j] == '*')
        {
            break;
        }
        else
        {
            return false;
        }
    }
    while (i >= 0 && p[j - 1] != '.' && p[j] == '*')
    {
        if (s[i] == p[j - 1] && s[i] == s[i - 1])
        {
            i--;
        }
        else
        {
            while (i >= 0 && p[j] != s[i])
            {
                j--;
            }
            break;
        }
    }
    // remaning the .* condition
    return false;
}

int maxArea(vector<int>& height)
{
    int n = height.size();
    if (n <= 1)
        return 0;
    int i = 0;
    int j = n - 1;
    int maxWater = 0;
    while (i < j)
    {
        maxWater = max(maxWater, min(height[i], height[j]) * (j - i));
        if (height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return maxWater;
}
// Easy(50–100 problems)
// Arrays
// Strings
// Hash Maps
// Two Pointers
// Stack
// Queue
// Medium(100–150 problems)
// Binary Search
// Linked List
// Trees
// Sliding Window
// Greedy
// Basic DP
// Hard
// Regular Expression Matching
// Edit Distance
// Wildcard Matching
// Advanced DP problems
vector<vector<int>> getRow1(int rowIndex)
{
    vector<vector<int>> res;
    for (int j = 0; j < rowIndex; j++)
    {
        vector<int> result = vector<int>(j + 1, 1);
        for (int i = 0; i < j; i++)
        {
            result[i + 1] = (int)((long long)result[i] * (j - i) / (i + 1));
        }
        res.push_back(result);
    }

    return res;
}
vector<int> getRow2(int rowIndex)
{
    vector<int> result = vector<int>(rowIndex + 1, 1);
    for (int i = 0; i < rowIndex; i++)
    {
        result[i + 1] = (int)((long long)result[i] * (rowIndex - i) / (i + 1));
    }
    return result;
}
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    unordered_map<int, int> myValue;
    for (int i = 0; i < nums.size(); i++)
    {
        if (myValue.find(nums[i]) != myValue.end())
        {
            if ((myValue[nums[i]] - i) <= k)
            {
                return true;
            }
        }
        else
        {
            myValue[nums[i]] = i;
        }
    }

    return false;
}
vector<string> summaryRanges(vector<int>& nums)
{

    vector<string> res;
    if (nums.empty())
        return res;
    int st = nums[0];
    int i = 0;
    int n = nums.size();
    while (i < n)
    {
        if (i < n - 1 && nums[i] + 1 == nums[i + 1])
        {
            i++;
        }
        else
        {
            if (st == nums[i])
            {
                res.push_back(to_string(st));
            }
            else
            {

                res.push_back(to_string(st) + "->" + to_string(nums[i]));
            }
            i++;
            if (i < n)
            {
                st = nums[i];
            }
        }
    }

    return res;
}
int missingNumber1(vector<int>& nums)
{
    if (nums.empty())
        return 0;
    int n = nums.size();

    int minValue = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (minValue == nums[j])
            {
                minValue++;
            }
        }
    }

    return minValue;
}
int missingNumber2(vector<int>& nums)
{
    int n = nums.size();
    vector<bool> isPresent = vector<bool>(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        isPresent[nums[i]] = true;
    }
    for (int i = 0; i <= n; i++)
    {
        if (isPresent[i] == false)
        {
            return i;
        }
    }
    return 0;
}
int missingNumber(vector<int>& nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
        if (i < n)
        {
            sum -= nums[i];
        }
    }
    return sum;
}
class NumArray1
{
    vector<int> array;

public:
    NumArray1(vector<int>& nums)
    {
        array = nums;
    }

    int sumRange(int left, int right)
    {
        int sum = 0;
        for (int i = left; i <= right; i++)
        {
            sum += array[i];
        }
        return sum;
    }
};
class NumArray
{
    vector<int> array;

public:
    NumArray(vector<int>& nums)
    {
        int n = nums.size();
        array.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            array.push_back(nums[i] + array[i - 1]);
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return array[right];
        return array[right] - array[left - 1];
    }
};
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    unordered_set<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (!temp.count(nums1[i]))
        {
            temp.insert(nums1[i]);
        }
    }
    set<int> result;
    for (int i = 0; i < m; i++)
    {
        if (temp.count(nums2[i]))
        {
            result.insert(nums2[i]);
        }
    }
    vector<int> res(result.begin(), result.end());
    return res;
}
vector<int> intersect1(vector<int>& nums1, vector<int>& nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums1[i] == nums2[j] && nums1[i] != -1 && nums2[j] != -1)
            {
                result.push_back(nums1[i]);
                nums1[i] = -1;
                nums2[j] = -1;
            }
        }
    }

    return result;
}
vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int maxN = nums1[0];
    for (int i = 0; i < n; i++)
    {
        maxN = max(maxN, nums1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        maxN = max(maxN, nums2[i]);
    }
    maxN++;
    vector<int> nVector = vector<int>(maxN, 0);
    vector<int> mVector = vector<int>(maxN, 0);
    for (int i = 0; i < n; i++)
    {
        nVector[nums1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        mVector[nums2[i]]++;
    }
    vector<int> result;
    int i = 0;
    while (i < mVector.size())
    {
        if (mVector[i] > 0 && nVector[i] > 0)
        {
            result.push_back(i);
            mVector[i]--;
            nVector[i]--;
        }
        else
        {
            i++;
        }
    }

    return result;
}
int thirdMax1(vector<int>& nums)
{

    int n = nums.size();
    set<int> num(nums.begin(), nums.end());
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int var : num)
    {
        minHeap.push(var);
    }
    if (minHeap.size() < 3)
    {
        int maxV = minHeap.top();
        minHeap.pop();
        while (!minHeap.empty())
        {
            maxV = max(maxV, minHeap.top());
            minHeap.pop();
        }
        return maxV;
    }
    while (minHeap.size() > 3)
    {
        minHeap.pop();
    }
    return minHeap.top();
}

int thirdMax(vector<int>& nums)
{
    int n = nums.size();
    long long s1 = LLONG_MIN, s2 = LLONG_MIN, s3 = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == s1 || nums[i] == s2 || nums[i] == s3)
        {
            continue;
        }
        if (s1 < nums[i])
        {
            s3 = s2;
            s2 = s1;
            s1 = nums[i];
        }
        else if (s2 < nums[i])
        {
            s3 = s2;
            s2 = nums[i];
        }
        else if (s3 < nums[i])
        {
            s3 = nums[i];
        }
    }

    return (s3 == LLONG_MIN) ? s1 : s3;
}
vector<int> findDisappearedNumbers1(vector<int>& nums)
{
    int n = nums.size();
    unordered_set<int> setValue;

    for (int i = 0; i < n; i++)
    {
        setValue.insert(nums[i]);
    }
    vector<int> result;
    for (int i = 1; i <= n; i++)
    {
        if (!setValue.count(i))
        {
            result.push_back(i);
        }
    }

    return result;
}
vector<int> findDisappearedNumbers(vector<int>& nums)
{
    int n = nums.size();
    vector<bool> temp = vector<bool>(n + 1, false);
    temp[0] = true;
    for (auto v : nums)
    {
        temp[v] = true;
    }
    vector<int> res;
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] == false)
        {
            res.push_back(i);
        }
    }

    return res;
}
int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0;
    int j = 0;
    int res = 0;
    while (i < s.size() && j < g.size())
    {
        if (s[i] >= g[j])
        {
            res++;
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return res;
}
int islandPerimeter(vector<vector<int>>& grid)
{
    int n = grid.size();
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int m = grid[i].size();
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                if (i == 0)
                {
                    result++;
                }
                else if (grid[i - 1][j] == 0)
                {
                    result++;
                }
                if (i == n - 1)
                {
                    result++;
                }
                else if (grid[i + 1][j] == 0)
                {
                    result++;
                }

                if (j == 0)
                {
                    result++;
                }
                else if (grid[i][j - 1] == 0)
                {
                    result++;
                }
                if (j == m - 1)
                {
                    result++;
                }
                else if (grid[i][j + 1] == 0)
                {
                    result++;
                }
            }
        }
    }

    return result;
}
int findMaxConsecutiveOnes(vector<int>& nums)
{
    int n = nums.size();
    int result = 0;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            temp++;
            result = max(result, temp);
        }
        else
        {
            temp = 0;
        }
    }
    return result;
}
int findPoisonedDuration1(vector<int>& timeSeries, int duration)
{
    int n = timeSeries.size();
    if (n < 2)
        return duration;
    int maxValue = timeSeries[n - 1];

    vector<bool> temp = vector<bool>(maxValue + duration, false);
    for (int i = 0; i < timeSeries.size(); i++)
    {
        for (int j = timeSeries[i]; j < timeSeries[i] + duration; j++)
        {
            temp[j] = true;
        }
    }
    int result = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == true)
        {
            result++;
        }
    }

    return result;
}
int findPoisonedDuration(vector<int>& timeSeries, int duration)
{
    int res = 0;
    for (int i = 0; i < timeSeries.size() - 1; i++)
    {
        res += min(duration, timeSeries[i + 1] - timeSeries[i]);
    }

    return res + duration;
}
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    // Question number 496
    int m = nums2.size();
    vector<int> res = vector<int>(nums1.size(), -1);
    for (int i = 0; i < nums1.size(); i++)
    {
        int j = 0;
        while (j < m && nums1[i] != nums2[j])
        {
            j++;
        }
        for (; j < m; j++)
        {
            if (nums1[i] < nums2[j])
            {
                res[i] = nums2[j];
                break;
            }
        }
    }
    return res;
}
bool isContains(char ch, string latter)
{
    for (int i = 0; i < latter.size(); i++)
    {
        if (towlower(ch) == latter[i])
        {
            return true;
        }
    }
    return false;
}
vector<string> findWords(vector<string>& words)
{
    // Question number 500
    vector<string> latters = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
    vector<string> res;
    for (int i = 0; i < words.size(); i++)
    {
        string str = words[i];
        int index = -1;
        if (isContains(str[0], latters[0]))
        {
            index = 0;
        }
        else if (isContains(str[0], latters[1]))
        {
            index = 1;
        }
        else
        {
            index = 2;
        }
        for (int j = 0; j < str.size(); j++)
        {
            if (!isContains(str[j], latters[index]))
            {
                str = "";
                break;
            }
        }
        if (!str.empty())
        {
            res.push_back(str);
        }
    }
    return res;
}
vector<string> findRelativeRanks1(vector<int>& score)
{
    // Question number 506
    int maxV = 0;
    int n = score.size();
    for (int i = 0; i < n; i++)
    {
        maxV = max(maxV, score[i]);
    }

    vector<bool> temp = vector<bool>(maxV + 1, false);
    for (int v : score)
    {
        temp[v] = true;
    }
    int position = 1;
    vector<string> result = vector<string>(n, "");
    for (int i = temp.size(); i >= 0; i--)
    {
        if (temp[i] == true)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == score[j])
                {
                    if (position == 1)
                    {
                        result[j] = "Gold Medal";
                    }
                    else if (position == 2)
                    {
                        result[j] = "Silver Medal";
                    }
                    else if (position == 3)
                    {

                        result[j] = "Bronze Medal";
                    }
                    else
                    {
                        result[j] = to_string(position);
                    }
                    position++;
                    break;
                }
            }
        }
    }
    return result;
}
static bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.first > b.first;
}
vector<string> findRelativeRanks(vector<int>& score)
{
    // Question number 506
    vector<pair<int, int>> temp;
    for (int i = 0; i < score.size(); i++)
    {
        temp.push_back({ score[i], i });
    }
    sort(temp.begin(), temp.end(), cmp);
    vector<string> result = vector<string>(score.size(), "");
    for (int i = 0; i < temp.size(); i++)
    {

        if (i == 0)
        {
            result[temp[i].second] = "Gold Medal";
        }
        else if (i == 1)
        {
            result[temp[i].second] = "Silver Medal";
        }
        else if (i == 2)
        {

            result[temp[i].second] = "Bronze Medal";
        }
        else
        {
            result[temp[i].second] = to_string(i + 1);
        }
    }

    return result;
}
int arrayPairSum(vector<int>& nums)
{
    //  Question number 561
    int n = nums.size();
    int result = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i += 2)
    {
        result += nums[i];
    }
    return result;
}
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
{
    //  Question number 566
    int m = mat.size();
    int totalElements = 0;
    for (int i = 0; i < m; i++)
    {
        totalElements += mat[i].size();
    }
    if (totalElements != r * c)
    {
        return mat;
    }
    vector<int> data;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            data.push_back(mat[i][j]);
        }
    }
    vector<vector<int>> result;
    int k = 0;
    for (int i = 0; i < r; i++)
    {
        vector<int> temp;
        for (int j = 0; j < c; j++)
        {
            temp.push_back(data[k]);
            k++;
        }
        result.push_back(temp);
    }

    return result;
}
int distributeCandies1(vector<int>& candyType)
{
    //  Question number 575
    int n = candyType.size();
    int result = 0;
    for (int i = 0; i < n && result < n / 2; i++)
    {
        int temp = INT_MIN;
        if (candyType[i] != INT_MIN)
        {
            temp = candyType[i];
            result++;
        }
        for (int j = 0; j < n; j++)
        {
            if (candyType[j] == temp)
            {
                candyType[j] = INT_MIN;
            }
        }
    }
    return result;
}
int distributeCandies(vector<int>& candyType)
{
    //  Question number 575
    int n = candyType.size();
    set<int> data;
    for (int i = 0; i < n; i++)
    {
        data.insert(candyType[i]);
        if (data.size() >= n / 2)
            return n / 2;
    }
    return data.size();
}
int findLHS(vector<int>& nums)
{
    //  Question number 594
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0, j = 0;
    int result = 0;
    while (i < n)
    {
        j = i;
        while (j < n && (nums[i] == nums[j] || nums[i] + 1 == nums[j]))
            j++;
        if (nums[i] != nums[j - 1])
        {
            result = max(result, j - i);
        }
        int temp = nums[i];
        while (i < n && (temp == nums[i]))
            i++;
    }
    return result;
}
int maxCount(int m, int n, vector<vector<int>>& ops)
{
    // Question number 598
    if (ops.empty())
        return m * n;
    int minX = INT_MAX;
    int minY = INT_MAX;
    for (int i = 0; i < ops.size(); i++)
    {
        minX = min(minX, ops[i][0]);
        minY = min(minY, ops[i][1]);
    }

    return minX * minY;
}
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
{
    //  Question number 599
    unordered_map<string, int> list1Map;
    for (int i = 0; i < list1.size(); i++)
    {
        list1Map[list1[i]] = i;
    }
    vector<string> result;
    int privSum = INT_MAX;
    for (int i = 0; i < list2.size(); i++)
    {
        int currSum = list1Map.at(list2[i]) + i;
        if (list1Map.find(list2[i]) != list1Map.end())
        {
            if (privSum == currSum)
            {
                result.push_back(list2[i]);
            }
            else if (privSum > currSum)
            {
                result.clear();
                result.push_back(list2[i]);
                privSum = currSum;
            }
        }
    }
    return result;
}
int maximumProduct(vector<int>& nums)
{
    // Question number 628
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int maxProdect = INT_MIN;
    maxProdect = max(maxProdect, nums[0] * nums[1] * nums[n - 1]);

    maxProdect = max(maxProdect, nums[n - 3] * nums[n - 2] * nums[n - 1]);

    return maxProdect;
}
double max(double a, double b)
{
    return (a < b) ? b : a;
}
double findMaxAverage(vector<int>& nums, int k)
{
    // Question number 643
    int n = nums.size();
    deque<int> dq;
    double maxSum = 0;
    for (int i = 0; i < k; i++)
    {
        maxSum += nums[i];
    }
    double maxAvarage = -2.14748e+09;
    maxAvarage = max(maxSum / k, maxAvarage);
    for (int j = k, i = 0; j < n; j++, i++)
    {
        maxSum = maxSum - nums[i] + nums[j];
        maxAvarage = max(maxSum / k, maxAvarage);
    }
    return maxAvarage;
}
vector<int> findErrorNums(vector<int>& nums)
{
    //  Question number 645
    int n = nums.size();
    vector<bool> temp = vector<bool>(n + 1, false);
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (temp[nums[i]])
        {
            result.push_back(nums[i]);
        }
        temp[nums[i]] = true;
    }
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] == false)
        {
            result.push_back(i);
        }
    }

    return result;
}
vector<vector<int>> imageSmoother(vector<vector<int>>& img)
{
    //  Question number 661
    int n = img.size();
    vector<vector<int>> imgFilter = img;
    for (int i = 0; i < n; i++)
    {
        int m = img[i].size();
        for (int j = 0; j < m; j++)
        {
            int sum = img[i][j];
            int count = 1;
            if (j > 0)
            {
                sum += img[i][j - 1];
                count++;
            }
            if (j < m - 1)
            {
                sum += img[i][j + 1];
                count++;
            }
            if (i < n - 1)
            {
                sum += img[i + 1][j];
                count++;
                if (j > 0)
                {
                    sum += img[i + 1][j - 1];
                    count++;
                }
                if (j < m - 1)
                {
                    sum += img[i + 1][j + 1];
                    count++;
                }
            }
            if (i > 0)
            {
                sum += img[i - 1][j];
                count++;
                if (j > 0)
                {
                    sum += img[i - 1][j - 1];
                    count++;
                }
                if (j < m - 1)
                {
                    sum += img[i - 1][j + 1];
                    count++;
                }
            }

            imgFilter[i][j] = (sum / count);
        }
    }
    return imgFilter;
}
int findLengthOfLCIS(vector<int>& nums)
{
    int n = nums.size();
    int curr = 1;
    int maxSum = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] < nums[i])
        {
            curr++;
            maxSum = max(maxSum, curr);
        }
        else
        {
            curr = 1;
        }
    }
    return maxSum;
}

int calPoints(vector<string>& operations)
{
    //  Question numver 682
    int n = operations.size();
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (operations[i] == "D")
        {
            if (!stk.empty())
            {
                stk.push(stk.top() * 2);
            }
        }
        else if (operations[i] == "C")
        {
            if (!stk.empty())
            {
                stk.pop();
            }
        }
        else if (operations[i] == "+")
        {
            if (!stk.empty())
            {
                int p1 = stk.top();
                stk.pop();
                if (!stk.empty())
                {
                    int p2 = stk.top();
                    stk.push(p1);
                    stk.push(p1 + p2);
                }
            }
        }
        else
        {
            stk.push(string_to_integer(operations[i]));
        }
    }
    int res = 0;
    while (!stk.empty())
    {
        res += stk.top();
        stk.pop();
    }

    return res;
}
int findShortestSubArray(vector<int>& nums)
{
    //  Question number 697
    struct mydata
    {
        int freq = 0;
        int minIndex = INT_MAX;
        int maxIndex = INT_MIN;
    };

    int n = nums.size();
    int maxValue = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxValue = max(maxValue, nums[i]);
    }
    vector<mydata> arr = vector<mydata>(maxValue + 1, mydata());

    for (int i = 0; i < n; i++)
    {
        arr[nums[i]].freq++;
        int minIndex = min(i, arr[nums[i]].minIndex);
        int maxIndex = max(i, arr[nums[i]].maxIndex);
        arr[nums[i]].minIndex = minIndex;
        arr[nums[i]].maxIndex = maxIndex;
    }

    int res = INT_MAX;
    int freq = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].maxIndex == INT_MIN || arr[i].minIndex == INT_MAX)
        {
            continue;
        }
        int currDis = arr[i].maxIndex - arr[i].minIndex + 1;
        int currFreq = arr[i].freq;
        if (freq < currFreq)
        {
            res = currDis;
            freq = currFreq;
        }
        else if (freq == currFreq)
        {
            res = min(res, currDis);
        }
    }
    return res;
}
int search(vector<int>& nums, int target)
{
    // Question number 704
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        else if (target < nums[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
class MyHashSet
{
    // Question number 705
    vector<bool> hashTable;

public:
    MyHashSet()
    {
        hashTable = vector<bool>(1e6, false);
    }

    void add(int key)
    {
        hashTable[key] = true;
    }

    void remove(int key)
    {
        hashTable[key] = false;
    }

    bool contains(int key)
    {
        return hashTable[key];
    }
};
class MyHashMap
{
    vector<int> data = vector<int>(1e6 + 1, -1);

public:
    MyHashMap()
    {
    }

    void put(int key, int value)
    {
        data[key] = value;
    }

    int get(int key)
    {

        return data[key];
    }

    void remove(int key)
    {
        data[key] = -1;
    }
};
bool isOneBitCharacter(vector<int>& bits)
{
    // Question number 717
    int i = 0;
    int n = bits.size();
    bool isSingle = false;
    while (i < n)
    {
        if (i < n - 1 && bits[i] == 1 && (bits[i + 1] == 0 || bits[i + 1] == 1))
        {
            i = i + 2;
            isSingle = false;
        }
        else
        {
            isSingle = true;
            i++;
        }
    }

    return isSingle;
}
int pivotIndex(vector<int>& nums)
{
    //  Question number 724
    int n = nums.size();
    vector<int> prefixSum;
    prefixSum.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        prefixSum.push_back(prefixSum[i - 1] + nums[i - 1]);
    }
    for (int i = 1; i < prefixSum.size(); i++)
    {
        if (prefixSum[i - 1] == (prefixSum[n] - prefixSum[i]))
        {
            return i - 1;
        }
    }

    return -1;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
{
    //  Question number 733
    int n = image.size();
    queue<pair<int, int>> qu;
    unordered_set<pair<int, int>, PairHash> visitied;
    qu.push({ sr, sc });
    int target = image[sr][sc];
    while (!qu.empty())
    {
        pair t = qu.front();
        if (image[t.first][t.second] == target && visitied.find({ t.first, t.second }) == visitied.end())
        {
            image[t.first][t.second] = color;
            if (t.first > 0)
            {
                qu.push({ t.first - 1, t.second });
            }
            if (t.first < n - 1)
            {
                qu.push({ t.first + 1, t.second });
            }
            if (t.second > 0)
            {
                qu.push({ t.first, t.second - 1 });
            }
            if (t.second < image[t.first].size() - 1)
            {
                qu.push({ t.first, t.second + 1 });
            }
        }
        visitied.insert(qu.front());
        qu.pop();
    }
    return image;
}

char nextGreatestLetter(vector<char>& letters, char target)
{
    //  Question number 744
    int n = letters.size();
    if (!(target >= letters[0] && target <= letters[n - 1]))
    {
        return letters[0];
    }
    int i = 0;
    int j = n - 1;
    char ans = letters[0];
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (letters[mid] > target)
        {
            ans = letters[mid];
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return ans;
}
int dominantIndex(vector<int>& nums)
{
    int n = nums.size();
    int index = -1;
    int maxV = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (maxV < nums[i])
        {
            maxV = nums[i];
            index = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != index && nums[i] * 2 > maxV)
        {
            return -1;
        }
    }
    return index;
}
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int k = 0, m = 0, n = matrix.size();
    do
    {
        int i = 0, j = k;
        int temp = matrix[i][j];
        m = matrix[i].size();
        while (i < n && j < m)
        {
            if (temp != matrix[i][j]) {
                return false;
            }
            i++, j++;
        }
        k++;
    } while (k < m);
    k = 0, m = 0;
    while (k < n) {
        int i = k, j = 0;
        int temp = matrix[i][j];
        m = matrix[i].size();
        while (i < n && j < m) {
            if (temp != matrix[i][j]) {
                return false;
            }
            i++, j++;
        }
        k++;
    }
    return true;
}

int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> codes = vector<string>{ ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
    int n = words.size();
    set<string> result;
    for (int i = 0; i < n; i++)
    {
        string wordsConvertedCode = "";
        for (auto j : words[i])
        {
            wordsConvertedCode += codes[j - 'a'];
        }

        result.insert(wordsConvertedCode);
    }
    return result.size();
}

string shortestCompletingWord(string licensePlate, vector<string>& words) {
    vector<int> p(26, 0);
    for (const char& c : licensePlate) {
        int t = charToIndex(c);
        if (t >= 0) {
            p[t]++;
        }
    }
    string res = "";
    int n = 0;
    for (const string& word : words) {
        if (n > 0 && word.size() > n) {
            continue;
        }
        vector<int> f(26, 0);
        int m = 0;
        for (const char& c : word) {
            f[charToIndex(c)]++;
            m++;
        }
        bool ok = true;
        for (int i = 0; i < 26; i++) {
            if (p[i] > f[i]) {
                ok = false;
                break;
            }
        }
        if (ok && (n == 0 || n > m)) {
            res = word;
            n = m;
        }
    }
    return res;
}
 vector<int> numberOfLines(vector<int>& widths, string s) {

    }
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<string> input = { "step","steps","stripe","stepple" };
    string sp = "1s3 PSt";

    cout << shortestCompletingWord(sp, input) << endl;

    input = { "looks","pest","stew","show" };
    sp = "1s3";
    cout << shortestCompletingWord(sp, input);

    return 0;
}
