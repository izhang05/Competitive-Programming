/* Author: izhang05
 * Time: 12-21-2021 22:47:59
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 205;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int n;
struct edge {
    int to, rev;
    long long cap;
};
vector<edge> adj[maxn];
bool is_edge[maxn][maxn];
int sol[maxn][maxn];
pair<int, int> ae(int a, int b, long long cap, long long rcap = 0) {
    assert(min(cap, rcap) >= 0); // saved me > once
    adj[a].push_back({b, int(adj[b].size()), cap});
    adj[b].push_back({a, int((adj[a].size() - 1)), rcap});
    is_edge[a][b] = true;
    return {a, int(adj[a].size()) - 1};
}
long long edge_flow(pair<int, int> loc) { // get flow along original edge
    const edge &e = adj[loc.first][loc.second];
    return adj[e.to][e.rev].cap;
}
vector<int> lev;
bool bfs(int s, int t) { // level=shortest dist from source
    lev = vector<int>(2 * n + 2);
    lev[s] = 1;
    queue<int> q({s});
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &i : adj[u]) {
            if (i.cap && !lev[i.to]) {
                q.push(i.to);
                lev[i.to] = lev[u] + 1;
                if (i.to == t) {
                    return true;
                }
            }
        }
    }
    return false;
}
long long dfs(int v, int t, long long flo) {
    if (v == t) {
        return flo;
    }
    for (auto &i : adj[v]) {
        if (lev[i.to] != lev[v] + 1 || !i.cap) {
            continue;
        }
        if (long long df = dfs(i.to, t, min(flo, i.cap))) {
            i.cap -= df;
            adj[i.to][i.rev].cap += df;
            return df;
        } // saturated >=1 one edge
    }
    return 0;
}
long long maxflow(int s, int t) {
    long long tot = 0;
    while (bfs(s, t)) {
        while (long long df = dfs(s, t, numeric_limits<long long>::max())) {
            tot += df;
        }
    }
    return tot;
}

void test_case() {
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    if (accumulate(a.begin(), a.end(), 0) != accumulate(b.begin(), b.end(), 0)) {
        cout << "NO"
             << "\n";
        return;
    }
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; ++i) {
        ae(0, i, a[i - 1]);
        edges.push_back(ae(i, i + n, inf));
    }
    for (int i = n + 1; i <= 2 * n; ++i) {
        ae(i, 2 * n + 1, b[i - n - 1]);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back(ae(u, v + n, inf));
        edges.push_back(ae(v, u + n, inf));
    }
    if (maxflow(0, 2 * n + 1) == accumulate(a.begin(), a.end(), 0)) {
        cout << "YES"
             << "\n";
        for (auto &i : edges) {
            sol[i.first - 1][adj[i.first][i.second].to - n - 1] = edge_flow(i);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << sol[i][j] << " \n"[j == n - 1];
            }
        }

    } else {
        cout << "NO"
             << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
