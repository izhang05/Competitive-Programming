/*
ID: izhang01
TASK: time
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
}

const int maxt = 1001, maxn = 1000;
int dp[maxn][maxt], val[maxn];
bool visited[maxn];

int main() {
    setIO();
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> adj[n];
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxt; ++j) {
            dp[i][j] = -1;
        }
    }
    dp[0][1] = 0;
    int sol = 0;
    for (int t = 1; t < maxt; ++t) {
        for (int i = 0; i < n; ++i) {
            if (dp[i][t] == -1) {
                continue;
            }
            for (int j : adj[i]) {
                dp[j][t + 1] = max(dp[j][t + 1], dp[i][t] + val[j]);
                if (j == 0) {
                    sol = max(sol, dp[j][t + 1] - c * t * t);
                }
            }
        }
    }

    cout << sol << "\n";
    return 0;
}
