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

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
int main() {
    setIO("36");
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b;
        ++adj[a][b];
    }
    long long maxflow = 0;
    vector<vector<int>> sol;
    while (reachable()) {
        long long flow = 1e18;
        for (int v = n - 1; v != 0; v = p[v]) {
            int u = p[v];
            flow = min(flow, adj[u][v]);
        }
        maxflow += flow;
        vector<int> cur{n};
        for (int v = n - 1; v != 0; v = p[v]) {
            int u = p[v];
            cur.push_back(u + 1);
            adj[u][v] -= flow;
            adj[v][u] += flow;
        }
        reverse(cur.begin(), cur.end());
        sol.push_back(cur);
    }
    cout << maxflow << '\n';
    for (auto &i : sol) {
        cout << i.size() << "\n";
        print(i);
    }
}