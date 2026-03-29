#include <iostream>
#include <vector>

#include "_05_2.cpp"
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
    int m=1;
    // cin >> m;

    for (int i = 0; i < m; i++){

        int n=1;
        // cin >> n;
        vector<int> v1 ={1 ,2, 3, 0 ,0 ,0};
        vector<int> v2 = {2, 5 ,6};

        merge(v1,3,v2,3);
        _print(v1);
    }
    return 0;
}
