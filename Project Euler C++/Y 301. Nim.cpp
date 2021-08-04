#include <bits/stdc++.h>

using namespace std;


int main() {
    int sol = 0;
    for (long long i = 1; i <= (1ll << 30); ++i) {
        if (!(i ^ (2 * i) ^ (3 * i))) {
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}
