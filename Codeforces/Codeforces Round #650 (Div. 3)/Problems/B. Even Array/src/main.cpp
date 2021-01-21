#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int odd = 0, even = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 != i % 2) {
                if (i % 2 == 0) {
                    ++even;
                } else {
                    ++odd;
                }
            }
        }
        if (odd == even) {
            cout << odd << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
