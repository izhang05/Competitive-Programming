#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1e5, mod = 1e9 + 7;
int dp[maxn], deg[maxn];
vector<int> adj[maxn], back[maxn];

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        back[b].push_back(a);
        ++deg[b];
    }
    dp[0] = 1;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i : adj[cur]) {
            if (--deg[i] == 0) {
                q.push(i);
            }
        }
        for (int i : back[cur]) {
            dp[cur] += dp[i];
            dp[cur] %= mod;
        }
    }
    cout << dp[n - 1] << "\n";
    return 0;
}
