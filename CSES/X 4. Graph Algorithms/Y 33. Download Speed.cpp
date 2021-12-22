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

int n;
struct edge {
    int to, rev;
    long long cap;
};
vector<edge> adj[maxn];
pair<int, int> ae(int a, int b, long long cap, long long rcap = 0) {
    assert(min(cap, rcap) >= 0); // saved me > once
    adj[a].push_back({b, int(adj[b].size()), cap});
    adj[b].push_back({a, int((adj[a].size() - 1)), rcap});
    return {a, int(adj[a].size()) - 1};
}
long long edgeFlow(pair<int, int> loc) { // get flow along original edge
    const edge &e = adj[loc.first][loc.second];
    return adj[e.to][e.rev].cap;
}
vector<int> lev, ptr;
bool bfs(int s, int t) { // level=shortest dist from source
    lev = ptr = vector<int>(n);
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
    for (int i = ptr[v]; i < (int) adj[v].size(); i++) {
        edge &e = adj[v][i];
        if (lev[e.to] != lev[v] + 1 || !e.cap) {
            continue;
        }
        if (long long df = dfs(e.to, t, min(flo, e.cap))) {
            e.cap -= df;
            adj[e.to][e.rev].cap += df;
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

int main() {
    setIO("33");
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        --a, --b;
        ae(a, b, c);
    }
    cout << maxflow(0, n - 1) << "\n";
}