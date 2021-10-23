/*
ID: izhang01
TASK: cbarn2
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
}
//#define DEBUG
const int maxn = 1e2 + 3, maxk = 8;
const long long inf = 0x3f3f3f3f;
long long dp[maxn][maxn][maxk];

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : dp) {
        for (auto &j : i) {
            for (long long &l : j) {
                l = inf;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i][(i - 1 + n) % n][k] = 0;
    }
    for (int left = k; left > 0; --left) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
#ifdef DEBUG
                cout << i << " " << j << " " << left << " " << dp[i][j][left] << endl;
#endif
                if (dp[i][j][left] == inf) {
                    continue;
                }
                long long cur = 0;
                for (int l = 0; l < n; ++l) {
                    int next = (j + 1 + l) % n;
                    cur += a[next] * l;
                    dp[i][next][left - 1] = min(dp[i][next][left - 1], cur + dp[i][j][left]);
                }
            }
        }
    }
    long long sol = inf;
#ifdef DEBUG
    cout << "\n";
#endif
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            sol = min(sol, dp[i][(i - 1 + n) % n][j]);
        }
#ifdef DEBUG
        cout << i << " " << dp[i][(i - 1 + n) % n][0] << "\n";
#endif
    }
    cout << sol << "\n";
    return 0;
}
