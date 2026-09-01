#include <iostream>
#include <vector>

using namespace std;
int charToIndex(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a';

    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    return -1;
}
void printVectror(vector<int > arr) {
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
double maxDouble(double a, double b) {
    return (a > b) ? a : b;
}
void print2dVector(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++)
    {
        printVectror(matrix[i]);
    }
    cout << endl;
}
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

vector<int> inputVector() {
    int n = 0;
    cin >> n;
    vector<int> inputVector;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        inputVector.push_back(temp);
    }
    return inputVector;
}
vector<vector<int>> input2Dvector() {
    int m = 0;
    cin >> m;
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++)
    {
        matrix.push_back(inputVector());
    }
    return matrix;
}
int string_to_integer(string str) {
    int nag = 1;
    int i = 0;
    if (str[0] == '-') {
        nag = -1;
        i = 1;
    }
    int res = 0;
    for (; i < str.size(); i++)
    {
        res = (res * 10) + (str[i] - '0');
    }
    return res * nag;
}
bool isSymbol(char c) {
    switch (c)
    {
    case ' ':
        return true;
    case '!':
        return true;
    case '?':
        return true;
    case ',':
        return true;
    case ';':
        return true;
    case '.':
        return true;
    case '\'':
        return true;
    case '\"':
        return true;
    case '\\':
        return true;
    case '/':
        return true;
    case '-':
        return true;
    case '_':
        return true;
    case '~':
        return true;
    case '`':
        return true;

    default:
        return false;
    }
    return false;
}
unordered_map<string, int> wordsSplit(string str) {
    unordered_map<string, int> res;
    int n = str.size();
    int i = 0;
    while (i < n)
    {
        string t = "";
        while (i < n && !isSymbol(str[i]))
        {
            if (str[i] >= 'a' && str[i] <= 'z') {
                t += str[i];
            }
            else {
                t += (str[i] - 'A') + 'a';
            }
            i++;
        }
        res[t]++;
        while (i < n && isSymbol(str[i]))i++;
    }
    return res;

}
