#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 1e6, sol = 0;
    for (int i = 3; i * i - (i - 2) * (i - 2) <= n; ++i) {
        for (int j = i - 2; i * i - j * j <= n && j >= 1; j -= 2) {
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}
