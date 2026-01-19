#include <bits/stdc++.h>

using namespace std;

long long solve(long long t) {
    if (t == 0 || t == 1) {
        return 0;
    }
    if (t % 3 == 2) {
        return (t + 1) / 3;
    }
    return solve(t - t / 3 - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int q;
    cin >> q;
    while (q--) {
        int a;
        long long c, t;
        cin >> a >> c >> t;
        if (a == 1) {
            if (t < 2 * c) {
                cout << c << "\n";
            } else {
                long long cur = 3 * c - 1;
                while (t > cur) {
                    if (cur % 2 == 1) {
                        cur = 3 * ((cur + 1) / 2);
                    } else {
                        cur = 3 * cur / 2 + 1;
                    }
                }
                cout << cur - t << "\n";
            }
        } else {
            if (c > t / 2) {
                cout << c << "\n";
            } else {
                cout << solve(c + t) << "\n";
            }
        }
    }
    return 0;
}
