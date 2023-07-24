#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int inf = 1e9;

int main() {
    setIO();

    int n;
    cin >> n;
    int h[n], dp[n];
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        dp[i] = inf;
    }
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n) {
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        }
        if (i + 2 < n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
        }
    }
    cout << dp[n - 1] << "\n";
    return 0;
}
