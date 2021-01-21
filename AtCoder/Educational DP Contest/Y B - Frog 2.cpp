#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int inf = 1e9;

int main() {
    setIO();

    int n, k;
    cin >> n >> k;
    int h[n], dp[n];
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        dp[i] = inf;
    }
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < k + 1 && j + i < n; ++j) {
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
        }
    }
    cout << dp[n - 1] << "\n";
    return 0;
}
