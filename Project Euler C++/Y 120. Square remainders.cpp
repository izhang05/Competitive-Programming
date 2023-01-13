#include <bits/stdc++.h>

using namespace std;

int main() {
    int sol = 0;
    for (int a = 3; a <= 1000; ++a) {
        int cur = 2;
        for (int i = 1; i <= a; ++i) {
            cur = max(cur, (2 * i * a) % (a * a));
        }
        sol += cur;
    }
    cout << sol << "\n";
    return 0;
}
