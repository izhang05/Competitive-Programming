/*
ID: izhang01
TASK: marathon
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
}

int dist(pair<int, int> x, pair<int, int> y) {
    return abs(y.first - x.first) + abs(y.second - x.second);
}

const int maxn = 501, inf = 1e9;
int dp[maxn][maxn][2]; // dp[index][num_removed]

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
        for (int j = 0; j < k + 1; ++j) {
            for (int l = 0; l < 2; ++l) {
                dp[i][j][l] = inf;
            }
        }
    }
    dp[0][0][1] = 0;
    dp[1][0][1] = dist(p[0], p[1]);
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int l = 1; l + j <= k && i + l < n; ++l) {
                dp[i + l + 1][j + l][0] = min(dp[i + l][j + 1][0], dp[i][j][1] - dist(p[i], p[i - 1]) + dist(p[i - 1], p[i + l]));
            }
            dp[i + 1][j][1] = min(dp[i + 1][j][1], min(dp[i][j][0], dp[i][j][1]) + dist(p[i], p[i + 1]));
        }
    }
    int sol = 1e9;
    for (int i = 0; i < k + 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            sol = min(sol, dp[n - 1][i][j]);
        }
    }
    cout << "18: " << dp[3][1][0] << "\n";
    cout << "26: " << dp[3][1][1] << "\n";
    cout << "36: " << dp[4][1][1] << "\n";
    cout << "24: " << dp[7][4][0] << "\n";
    cout << sol << "\n";
    return 0;
}
