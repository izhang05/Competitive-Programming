/*
ID: izhang01
TASK: barnpainting
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
}
const int maxn = 1e5, mod = 1e9 + 7;
long long dp[maxn][4];
int c[maxn];
vector<int> adj[maxn];

void dfs(int n, int p) {
    if (c[n]) {
        dp[n][c[n]] = 1;
    } else {
        for (int i = 1; i < 4; ++i) {
            dp[n][i] = 1;
        }
    }
    for (int i : adj[n]) {
        if (i != p) {
            if (c[i]) {
                dp[n][c[i]] = 0;
            }
            dfs(i, n);
        }
    }
    for (int i = 1; i < 4; ++i) {
        for (int j : adj[n]) {
            if (j != p) {
                int cur = 0;
                for (int k = 1; k < 4; ++k) {
                    if (k != i) {
                        cur += dp[j][k];
                    }
                }
                dp[n][i] *= cur;
                dp[n][i] %= mod;
            }
        }
    }
}

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        --a;
        c[a] = b;
    }
    dfs(0, -1);
    cout << (dp[0][1] + dp[0][2] + dp[0][3]) % mod << "\n";
    return 0;
}
