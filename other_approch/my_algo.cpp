#include <iostream>
#include <vector>

using namespace std;

void print2dVector(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\tFinished\t" << endl;
}
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
