/*
ID: izhang01
TASK: palpath
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);
}
const int maxn = 501;
char grid[maxn][maxn];
int n, dp[maxn][maxn][maxn]; // dp[dist away from center diagonal][row of upper part][row of upper part]

bool valid(pair<int, int> x) {
    return x.first >= 0 && x.first < n && x.second >= 0 && x.second < n;
}

bool same(pair<int, int> x, pair<int, int> y) {
    if (!valid(x) || !valid(y)) {
        return false;
    }
    return grid[x.first][x.second] == grid[y.first][y.second];
}

int main() {
    setIO();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        dp[0][i][i] = 1;
    }
    for (int dist = 0; dist < n; ++dist) {
        for (int t = 0; t < n; ++t) {
            int col_t = dist - t - 1 + n;
            for (int b = 0; b < n; ++b) {
                int col_b = n - dist - b - 1;
                int cur = dp[dist][t][b];
                if (!cur) {
                    continue;
                }
                if (same(make_pair(t, col_t - 1), make_pair(b, col_b + 1))) {
                    dp[dist + 1][t][b] += cur;
                }
                if (same(make_pair(t - 1, col_t), make_pair(b, col_b + 1))) {
                    dp[dist + 1][t - 1][b] += cur;
                }
                if (same(make_pair(t, col_t), make_pair(b + 1, col_b))) {
                    dp[dist + 1][t][b + 1] += cur;
                }
                if (same(make_pair(t - 1, col_t), make_pair(b + 1, col_b))) {
                    dp[dist + 1][t - 1][b + 1] += cur;
                }
                cout << dist << " " << t << " " << b << " " << cur << "\n";
            }
        }
    }
    cout << dp[n - 1][0][n - 1] << "\n";
    return 0;
}
