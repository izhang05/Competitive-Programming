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

const int maxn = 1e5;
vector<int> adj[maxn], back_adj[maxn];
int deg[maxn], dp[maxn], parent[maxn];


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        ++deg[b];
        adj[a].push_back(b);
        back_adj[b].push_back(a);
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
            q.push(i);
        }
        parent[i] = -1;
        dp[i] = -1e9;
    }
    dp[0] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i : adj[cur]) {
            if (--deg[i] == 0) {
                q.push(i);
            }
            if (dp[cur] + 1 > dp[i]) {
                dp[i] = dp[cur] + 1;
                parent[i] = cur;
            }
        }
    }


    if (dp[n - 1] > 0) {
        stack<int> sol;
        int u = n - 1;
        while (u >= 0) {
            sol.push(u);
            u = parent[u];
        }
        cout << dp[n - 1] << "\n";
        while (!sol.empty()) {
            cout << sol.top() + 1 << " ";
            sol.pop();
        }
    } else {
        cout << "IMPOSSIBLE" << "\n";
    }
    return 0;
}
