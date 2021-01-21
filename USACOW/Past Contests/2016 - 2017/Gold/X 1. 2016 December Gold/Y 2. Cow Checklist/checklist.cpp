/*
ID: izhang01
TASK: checklist
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
}
const int maxn = 1e3 + 5;
const long long inf = 1e18;
long long dp[maxn][maxn][2];

int dist(pair<int, int> x, pair<int, int> y) {
    return pow(x.first - y.first, 2) + pow(x.second - y.second, 2);
}

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].first >> b[i].second;
    }

    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = inf;
            }
        }
    }
    dp[1][0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (dp[i][j][k] == inf) {
                    continue;
                }
                if (k == 0) {
                    if (i < n) {
                        dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + dist(a[i - 1], a[i]));
                    }
                    if (j < m) {
                        dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + dist(a[i - 1], b[j]));
                    }
                } else {
                    if (i < n) {
                        dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + dist(b[j - 1], a[i]));
                    }
                    if (j < m) {
                        dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + dist(b[j - 1], b[j]));
                    }
                }
            }
        }
    }
//    for (int i = 0; i < n + 1; ++i) {
//        for (int j = 0; j < m + 1; ++j) {
//            cout << dp[i][j][0] << " " << dp[i][j][1] << "\n";
//        }
//        cout << "\n";
//    }
    cout << dp[n][m][0] << "\n";
    return 0;
}
