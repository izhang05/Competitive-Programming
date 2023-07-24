#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int maxn = 1e5, mod = 1e9 + 7;
vector<int> adj[maxn];
long long dp[maxn][2]; // dp[loc][color]

void sol(int n, int p) {
    dp[n][0] = 1, dp[n][1] = 1;
    for (int i : adj[n]) {
        if (i != p) {
            sol(i, n);
            dp[n][1] *= dp[i][0];
            dp[n][1] %= mod;
        }
    }
    for (int i : adj[n]) {
        if (i != p) {
            dp[n][0] *= dp[i][0] + dp[i][1];
            dp[n][0] %= mod;
        }
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sol(0, -1);
    cout << (dp[0][0] + dp[0][1]) % mod << "\n";
    return 0;
}
