#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxx = 11;
long long k, x, m, dp[maxn][maxx][3]; // [...][...][0] -> less than k, [1] -> exactly k, [2] -> greater than k
vector<int> adj[maxn];

long long dp2[maxx][3];
void dfs(int c, int p) {
    dp[c][0][0] = k - 1;
    dp[c][1][1] = 1;
    dp[c][0][2] = m - k;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            memset(dp2, 0, sizeof(dp2));
            for (int j = 0; j <= x; ++j) {
                for (int l = 0; l + j <= x; ++l) {
                    for (int n = 0; n < 3; ++n) {
                        dp2[j + l][0] += dp[c][j][0] * dp[i][l][n];
                        dp2[j + l][0] %= mod;
                    }
                    dp2[j + l][1] += dp[c][j][1] * dp[i][l][0];
                    dp2[j + l][1] %= mod;
                    dp2[j + l][2] += dp[c][j][2] * dp[i][l][0];
                    dp2[j + l][2] %= mod;
                    dp2[j + l][2] += dp[c][j][2] * dp[i][l][2];
                    dp2[j + l][2] %= mod;
                }
            }
            for (int j = 0; j <= x; ++j) {
                for (int l = 0; l < 3; ++l) {
                    dp[c][j][l] = dp2[j][l];
                }
            }
        }
    }
}

int main() {
    setIO("1");

    int n;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> k >> x;
    dfs(0, -1);
    long long sol = 0;
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j < 3; ++j) {
#ifdef DEBUG
            cout << i << " " << j << " " << dp[0][i][j] << "\n";
#endif
            sol += dp[0][i][j];
            sol %= mod;
        }
    }
    cout << sol << "\n";
    return 0;
}
