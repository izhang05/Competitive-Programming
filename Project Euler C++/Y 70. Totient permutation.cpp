#include <bits/stdc++.h>

using namespace std;
const int n = 1e7;
int phi[n];

bool permute(int a, int b) {
    multiset<int> ma, mb;
    while (a) {
        ma.insert(a % 10);
        a /= 10;
    }
    while (b) {
        mb.insert(b % 10);
        b /= 10;
    }
    return ma == mb;
}

int main() {
    for (int i = 0; i < n; i++) {
        phi[i] = i;
    }

    for (int i = 2; i < n; i++) {
        if (phi[i] == i) {
            for (int j = i; j < n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    pair<long double, int> sol = {1e18, 0};
    for (int i = 2; i < n; ++i) {
        if (permute(i, phi[i])) {
            sol = min(sol, {(long double) i / phi[i], i});
        }
    }
    cout << sol.second << "\n";
    return 0;
}
