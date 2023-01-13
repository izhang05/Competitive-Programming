#include <bits/stdc++.h>

using namespace std;

const int n = 1e8;

int sieve[n];

int main() {
    for (int i = 2; i < n; ++i) {
        if (!sieve[i]) {
            for (int j = i + i; j < n; j += i) {
                sieve[j] = i;
            }
        }
    }
    int sol = 0;
    for (int i = 2; i < n; ++i) {
        if (sieve[i]) {
            if (!sieve[i / sieve[i]]) {
                ++sol;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
