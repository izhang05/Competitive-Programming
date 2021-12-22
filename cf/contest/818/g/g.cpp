/* Author: izhang05
 * Time: 12-22-2021 13:48:13
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
        cout << u << " " << v << " " << cap << " " << cost << "\n";
        adj[u].push_back({v, int(adj[v].size()), 0, cap, cost});
        adj[v].push_back({u, int(adj[u].size()) - 1, 0, 0, -cost});
    }                         // use asserts, don't try smth dumb
    bool path(int s, int t) { // send flow through lowest cost path
        const C INF = numeric_limits<C>::max();
        dist.assign(N, INF);
        using T = pair<C, int>;
        priority_queue<T, vector<T>, greater<>> todo;
        todo.push({dist[s] = 0, s});
        while (!todo.empty()) { // Dijkstra
            T x = todo.top();
            todo.pop();
            cout << x.first << " " << x.second << endl;
            if (x.first > dist[x.second]) continue;
            for (auto &i : adj[x.second]) { // all weights should be non-negative
                if (i.flo < i.cap && dist[i.to] > x.first + i.cost + p[x.second] - p[i.to]) {
                    pre[i.to] = {x.second, i.rev}, todo.push({dist[i.to] = x.first + i.cost + p[x.second] - p[i.to], i.to});
                }
            }
        } // if costs are doubles, add some EPS so you
        // don't traverse ~0-weight cycle repeatedly
        return dist[t] != INF; // true if augmenting path
    }
    pair<F, C> calc(int s, int t, F k = inf) {
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
        while (totFlow < k && path(s, t)) { // p -> potentials for Dijkstra
            cout << totFlow << endl;
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    mcmf flow;
    flow.init(2 * n + 2);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j < n; ++j) {
            if (abs(a[i - 1] - a[j]) == 1 || (a[i - 1] % 7) == (a[j] % 7)) {
                flow.ae(n + j + 1, i, 1, 0);
            }
        }
        flow.ae(0, i, 1, 0);
        flow.ae(i, i + n, 1, -1);
    }
    for (int i = n + 1; i <= 2 * n; ++i) {
        flow.ae(i, 2 * n + 1, 1, 0);
    }

    cout << -flow.calc(0, 2 * n + 1, 4).second << "\n";
    //    int n;
    //    cin >> n;
    //    vector<int> a(n);
    //    map<int, int> ind;
    //    int cur_ind = 0;
    //    for (int i = 0; i < n; ++i) {
    //        cin >> a[i];
    //        if (ind.find(a[i]) == ind.end()) {
    //            ind[a[i]] = cur_ind++;
    //        }
    //    }
    //    mcmf flow;
    //    int t = 2 * n + 7 + cur_ind + 1;
    //    flow.init(t + 1);
    //    vector<int> mod_ind(7);
    //    for (int i = 0; i < 7; ++i) {
    //        mod_ind[i] = n + 1 + i;
    //    }
    //    vector<int> diff_ind(cur_ind);
    //    for (int i = 0; i < cur_ind; ++i) {
    //        diff_ind[i] = n + 8 + i;
    //    }
    //
    //    for (int i = 0; i < n; ++i) {
    //        flow.ae(0, i + 1, 1, 0);
    //        flow.ae(mod_ind[a[i] % 7], i + 1, 1, 0);
    //        if (ind.find(a[i] - 1) != ind.end()) {
    //            flow.ae(diff_ind[ind[a[i] - 1]], i + 1, 1, 0);
    //        }
    //        if (ind.find(a[i] + 1) != ind.end()) {
    //            flow.ae(diff_ind[ind[a[i] + 1]], i + 1, 1, 0);
    //        }
    //        flow.ae(n + 8 + cur_ind + i, mod_ind[a[i] % 7], 1, 0);
    //        flow.ae(n + 8 + cur_ind + i, diff_ind[ind[a[i]]], 1, 0);
    //
    //        flow.ae(i + 1, n + 8 + cur_ind + i, 1, -1);
    //        flow.ae(n + 8 + cur_ind + i, t, 1, 0);
    //    }
    ////    return;
    //    cout << -flow.calc(0, t, 4).second << "\n";
}

int main() {
    setIO("2");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
