#include <iostream>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    string solution;
    if (n == 1 & t == 10) {
        solution = "-1";
    } else if (t == 10) {
        for (int i = 0; i < n - 1; ++i) {
            solution += "1";
        }
        solution += "0";
    } else {
        for (int i = 0; i < n; ++i) {
            solution += to_string(t);
        }
    }
    cout << solution << "\n";
    return 0;
}