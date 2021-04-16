/*
ID: izhang01
TASK: money
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    freopen("money.out", "w", stderr);
}
//#define DEBUG

long long dp[30][int(1e4 + 5)];

int main() {
    setIO();
    int n, v;
    cin >> n >> v;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= v; ++j) {
            long long cur = dp[i][j];
            if (!cur) {
                continue;
            }
#ifdef DEBUG
            cout << i << " " << j << " " << cur << "\n";
#endif
            dp[i + 1][j] += cur;
            int cur_v = j + a[i];
            while (cur_v <= v) {
                dp[i + 1][cur_v] += cur;
                cur_v += a[i];
            }
        }
    }
    cout << dp[n][v] << "\n";
    return 0;
}
