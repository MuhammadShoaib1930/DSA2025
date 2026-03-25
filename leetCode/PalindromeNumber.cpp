#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>

bool isPalindrome(int x) {
    if (x < 0) return 0;
    long long revers = 0, preVlaue = x;
    while (x > 0) {
        revers = (revers * 10) + (x % 10);
        x /= 10;
    }
    cout << "org = " << preVlaue << "     revers = " << revers << endl;
    return (preVlaue == revers);
}

int main() {
    cout << isPalindrome(123454321);
    return 0;
}
