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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 210;
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

int main() {
    setIO("44");
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ae(0, i, 1);
    }
    for (int i = n + 1; i <= 2 * n; ++i) {
        ae(i, 2 * n + 1, 1);
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'o') {
                ae(i + 1, j + n + 1, inf);
            }
        }
    }
    cout << maxflow(0, 2 * n + 1) << "\n";
    for (int i = 1; i < n + 1; ++i) {
        if (lev[i] == 0) {
            cout << 1 << " " << i << "\n";
        }
    }
    for (int i = n + 1; i <= 2 * n; ++i) {
        if (lev[i]) {
            cout << 2 << " " << i - n << "\n";
        }
    }
    return 0;
}
