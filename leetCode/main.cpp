#include <iostream>
#include <vector>

#include "_04_2.cpp"
using namespace std;

void _print(vector<int> res) {
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}
vector<int> _input(int n) {
    vector<int> values = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    return values;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
        vector<int> values = _input(1);
        cout << removeElement(values,1000) << " ";
        _print(values);
    return 0;
}
