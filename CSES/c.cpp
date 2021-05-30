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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e4 + 5, maxk = 505;
vector<int> adj[maxn];
long long dp[maxn][maxk], k;
long long sol = 0;

void dfs(int c, int p) {
    dp[c][0] = 1;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            for (int j = 0; j < k; ++j) {
                sol += dp[i][j] * dp[c][k - (j + 1)];
            }
            for (int j = 0; j < k; ++j) {
                dp[c][j + 1] += dp[i][j];
            }
        }
    }
//    for (int i = 0; i <= k / 2; ++i) {
//        sol += dp[c][i] * dp[c][k - i];
//    }
#ifdef DEBUG
    cout << c << " " << sol << "\n";
#endif
}

int main() {
    setIO("c");

    int n;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << sol << "\n";
    return 0;
}
