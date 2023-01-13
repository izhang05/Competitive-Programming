#include <bits/stdc++.h>

using namespace std;

const int maxn = 40;
long double dp[maxn], dp1[maxn];

int main() {
    dp[0] = dp1[0] = 1;
    for (int _ = 0; _ < 9; ++_) {
        for (int i = maxn - 1; i >= 0; --i) {
            for (int j = 1; j <= 4 && i + j < maxn; ++j) {
                dp[i + j] += dp[i] / 4;
            }
            dp[i] = 0;
        }
    }
    for (int _ = 0; _ < 6; ++_) {
        for (int i = maxn - 1; i >= 0; --i) {
            for (int j = 1; j <= 6 && i + j < maxn; ++j) {
                dp1[i + j] += dp1[i] / 6;
            }
            dp1[i] = 0;
        }
    }
    long double sol = 0;
    for (int i = 0; i < maxn; ++i) {
        long double cur = 0;
        for (int j = 0; j < i; ++j) {
            cur += dp1[j];
        }
        sol += dp[i] * cur;
    }
    cout << fixed << setprecision(7) << round(sol * 1e7) / 1e7 << "\n";
    return 0;
}
