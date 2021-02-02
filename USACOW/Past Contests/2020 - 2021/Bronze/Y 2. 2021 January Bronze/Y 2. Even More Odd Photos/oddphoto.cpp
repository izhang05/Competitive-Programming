#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
#endif
}

int main() {
    setIO();
    int n, a, even = 0, odd = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a % 2) {
            ++odd;
        } else {
            ++even;
        }
    }
    int sol = min(even, odd) * 2;
    if (even > odd) {
        ++sol;
    }
    bool type = true; // true = even, false = odd
    int remain = odd - even;
    while (remain > 0) {
        if (type) {
            if (remain == 1) {
                --sol;
                break;
            } else {
                remain -= 2;
            }
        } else {
            --remain;
        }
        type ^= true;
        ++sol;
    }
    cout << sol << "\n";
    return 0;
}
