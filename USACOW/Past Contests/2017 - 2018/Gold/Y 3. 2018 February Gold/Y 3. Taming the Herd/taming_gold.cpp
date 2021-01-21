/*
ID: izhang01
TASK: taming
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
}
const int maxn = 101, inf = 1e9;
int dp[maxn][maxn][maxn];// dp[loc][num_used][last_0]

int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            for (int k = 0; k < n; ++k) {
                dp[i][j][k] = inf;
            }
        }
    }

    dp[0][1][0] = a[0] != 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            for (int k = 0; k <= i; ++k) {
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + int(a[i + 1] != i - k + 1));
                dp[i + 1][j + 1][i + 1] = min(dp[i + 1][j + 1][i + 1], dp[i][j][k] + int(a[i + 1] != 0));
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        int cur = 1e9;
        for (int j = 0; j < n; ++j) {
            cur = min(cur, dp[n - 1][i][j]);
        }
        cout << cur << "\n";
    }
    return 0;
}
