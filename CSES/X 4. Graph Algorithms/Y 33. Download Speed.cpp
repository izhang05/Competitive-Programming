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

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)

const int maxn = 505;
int n, m;
long long adj[maxn][maxn];
bool vis[maxn];
int p[maxn];

bool reachable() {
    memset(vis, false, sizeof(vis));
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j = 0; j < n; j++) {
            if (adj[i][j] && !vis[j]) {
                vis[j] = true;
                p[j] = i, q.push(j);
            }
        }
    }
    return vis[n - 1];
}

int main() {
    setIO("33");
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a][b] += c;
    }
    long long maxflow = 0;
    while (reachable()) {
        long long flow = 1e18;
        for (int v = n - 1; v != 0; v = p[v]) {
            int u = p[v];
            flow = min(flow, adj[u][v]);
        }
        maxflow += flow;
        for (int v = n - 1; v != 0; v = p[v]) {
            int u = p[v];
            adj[u][v] -= flow;
            adj[v][u] += flow;
        }
    }
    cout << maxflow << '\n';
}