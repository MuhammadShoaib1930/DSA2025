#include <iostream>
#include <vector>
using namespace std;
vector<string> fizzBuzz(int n) {
    vector<string> res = vector<string>(n, "");
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            if (i % 3 == 0) {
                res[i-1] += "Fizz";
            }
            if (i % 5 == 0) {
                res[i-1] += "Buzz";
            }
        } else {
            res[i-1] = to_string(i);
        }
    }
    return res;
}
