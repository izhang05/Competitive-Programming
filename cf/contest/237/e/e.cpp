/* Author: izhang05
 * Time: 12-22-2021 02:23:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
using F = long long;
using C = long long; // flow type, cost type
struct Edge {
    int to, rev;
    F flo, cap;
    C cost;
};
struct mcmf {
    int N{};
    vector<C> p, dist;
    vector<pair<int, int>> pre;
    vector<vector<Edge>> adj;
    void init(int _N) {
        N = _N;
        p.resize(N), adj.resize(N), dist.resize(N), pre.resize(N);
    }
    void ae(int u, int v, F cap, C cost) {
        assert(cap >= 0);
        adj[u].push_back({v, int(adj[v].size()), 0, cap, cost});
        adj[v].push_back({u, int(adj[u].size()) - 1, 0, 0, -cost});
    }                         // use asserts, don't try smth dumb
    bool path(int s, int t) { // send flow through lowest cost path
        const C inf = numeric_limits<C>::max();
        dist.assign(N, inf);
        using T = pair<C, int>;
        priority_queue<T, vector<T>, greater<>> todo;
        todo.push({dist[s] = 0, s});
        while (!todo.empty()) { // Dijkstra
            T x = todo.top();
            todo.pop();
            if (x.first > dist[x.second]) continue;
            for (auto &i : adj[x.second]) { // all weights should be non-negative
                if (i.flo < i.cap && dist[i.to] > x.first + i.cost + p[x.second] - p[i.to]) {
                    pre[i.to] = {x.second, i.rev}, todo.push({dist[i.to] = x.first + i.cost + p[x.second] - p[i.to], i.to});
                }
            }
        } // if costs are doubles, add some EPS so you
        // don't traverse ~0-weight cycle repeatedly
        return dist[t] != inf; // true if augmenting path
    }
    pair<F, C> calc(int s, int t) {
        assert(s != t);
        for (int _ = 0; _ < N; ++_) {
            for (int i = 0; i < N; ++i) {
                for (auto &e : adj[i]) { // Bellman-Ford
                    if (e.cap) {
                        p[e.to] = min(p[e.to], p[i] + e.cost);
                    }
                }
            }
        }
        F totFlow = 0;
        C totCost = 0;
        while (path(s, t)) { // p -> potentials for Dijkstra
            for (int i = 0; i < N; ++i) {
                p[i] += dist[i]; // doesn't matter for unreachable
            }
            F df = numeric_limits<F>::max();
            for (int x = t; x != s; x = pre[x].first) {
                Edge &e = adj[pre[x].first][adj[x][pre[x].second].rev];
                df = min(df, e.cap - e.flo);
            }
            totFlow += df;
            totCost += (p[t] - p[s]) * df;
            for (int x = t; x != s; x = pre[x].first) {
                Edge &e = adj[x][pre[x].second];
                e.flo -= df;
                adj[pre[x].first][e.rev].flo += df;
            }
        } // get max flow you can send along path
        return {totFlow, totCost};
    }
};

void test_case() {
    string s;
    int n;
    cin >> s >> n;
    mcmf flow;
    flow.init(n + 28);
    vector<int> cnt(26);
    for (auto &i : s) {
        ++cnt[i - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i]) {
            flow.ae(n + 1 + i, n + 27, cnt[i], 0);
        }
    }

    for (int i = 0; i < n; ++i) {
        string s1;
        int a;
        cin >> s1 >> a;
        flow.ae(0, i + 1, a, 0);
        cnt = vector<int>(26);
        for (auto &j : s1) {
            ++cnt[j - 'a'];
        }
        for (int j = 0; j < 26; ++j) {
            if (cnt[j]) {
                flow.ae(i + 1, n + j + 1, cnt[j], i + 1);
            }
        }
    }
    pair<long long, long long> res = flow.calc(0, n + 27);
    if (res.first < (long long) s.size()) {
        cout << -1 << "\n";
    } else {
        cout << res.second << "\n";
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
