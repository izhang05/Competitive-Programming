/*
ID:  izhang01
TASK: team
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    freopen("team.out", "w", stderr);
}
//#define DEBUG
const int mod = 1e9 + 9, maxn = 1e3 + 5, maxk = 12;
long long dp[maxn][maxn][maxk], pre[maxn][maxn][maxk];

int main() {
    setIO();
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            pre[i][j][0] = 1;
        }
    }
    for (int l = 1; l <= k; ++l) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i - 1] > b[j - 1]) {
                    dp[i][j][l] += pre[i - 1][j - 1][l - 1];
                    dp[i][j][l] %= mod;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                pre[i][j][l] = (dp[i][j][l] + pre[i - 1][j][l] + pre[i][j - 1][l] - pre[i - 1][j - 1][l]) % mod;
                pre[i][j][l] += mod;
                pre[i][j][l] %= mod;
            }
        }
    }
    long long sol = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            sol += dp[i][j][k];
            sol %= mod;
        }
    }
    cout << sol << "\n";
    return 0;
}
