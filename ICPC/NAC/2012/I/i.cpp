#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: chilli
 * Date: 2019-04-26
 * License: CC0
 * Source: https://cp-algorithms.com/graph/dinic.html
 * Description: Flow algorithm with complexity $O(VE\log U)$ where $U = \max |\text{cap}|$.
 * $O(\min(E^{1/2}, V^{2/3})E)$ if $U = 1$; $O(\sqrt{V}E)$ for bipartite matching.
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
 */

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;

        ll flow() { return max(oc - c, 0LL); } // if you need flows
    };

    vi lvl, ptr, q;
    vector<vector<Edge>> adj;

    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}

    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }

    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int &i = ptr[v]; i < sz(adj[v]); i++) {
            Edge &e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }

    ll calc(int s, int t) {
        ll flow = 0;
        q[0] = s;
        rep(L, 0, 31) do { // 'int L=30' maybe faster for random data
                lvl = ptr = vi(sz(q));
                int qi = 0, qe = lvl[s] = 1;
                while (qi < qe && !lvl[t]) {
                    int v = q[qi++];
                    for (Edge e: adj[v])
                        if (!lvl[e.to] && e.c >> (30 - L))
                            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
                }
                while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
            } while (lvl[t]);
        return flow;
    }

    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[j][i] = (s[j] == 'Y');
        }
    }
    for (int k = n; k >= 0; --k) {
        Dinic f(2 * n + 2);
        for (int i = 2; i <= n + 1; ++i) {
            f.addEdge(0, i, k);
        }
        for (int i = n + 2; i < 2 * n + 2; ++i) {
            f.addEdge(i, 1, k);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    f.addEdge(i + 2, j + n + 2, 1);
                }
            }
        }
        if (f.calc(0, 1) == k * n) {
            cout << k << "\n";
            Dinic cur(2 * n + 2);
            for (int i = 2; i <= n + 1; ++i) {
                cur.addEdge(0, i, 1);
            }
            for (int i = n + 2; i < 2 * n + 2; ++i) {
                cur.addEdge(i, 1, 1);
            }
            for (int i = 0; i < n; ++i) {
                for (auto &j: f.adj[i + 2]) {
                    if (j.flow()) {
                        cur.addEdge(i + 2, j.to, 1);
                    }
                }
            }
            for (int i = 0; i < k; ++i) {
                cur.calc(0, 1);
                Dinic new_cur(2 * n + 2);
                for (int j = 2; j <= n + 1; ++j) {
                    new_cur.addEdge(0, j, 1);
                }
                for (int j = n + 2; j < 2 * n + 2; ++j) {
                    new_cur.addEdge(j, 1, 1);
                }
                for (int j = 0; j < n; ++j) {
                    for (auto &l: cur.adj[j + 2]) {
                        if (l.flow()) {
                            cout << l.to - n - 1 << " ";
                        } else {
                            new_cur.addEdge(j + 2, l.to, 1);
                        }
                    }
                }
                cout << "\n";
                cur = new_cur;
            }
            break;
        }
    }
}
//
//#include <bits/stdc++.h>
//
//using namespace std;
//#define rep(i, a, b) for(int i = a; i < (b); ++i)
//#define all(x) begin(x), end(x)
//#define sz(x) (int)(x).size()
//typedef long long ll;
//typedef pair<int, int> pii;
//typedef vector<int> vi;
//
///**
// * Author: chilli
// * Date: 2019-04-26
// * License: CC0
// * Source: https://cp-algorithms.com/graph/dinic.html
// * Description: Flow algorithm with complexity $O(VE\log U)$ where $U = \max |\text{cap}|$.
// * $O(\min(E^{1/2}, V^{2/3})E)$ if $U = 1$; $O(\sqrt{V}E)$ for bipartite matching.
// * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
// */
//
//struct Dinic {
//    struct Edge {
//        int to, rev;
//        ll c, oc;
//
//        ll flow() { return max(oc - c, 0LL); } // if you need flows
//    };
//
//    vi lvl, ptr, q;
//    vector<vector<Edge>> adj;
//
//    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
//
//    void addEdge(int a, int b, ll c, ll rcap = 0) {
//        adj[a].push_back({b, sz(adj[b]), c, c});
//        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
//    }
//
//    ll dfs(int v, int t, ll f) {
//        if (v == t || !f) return f;
//        for (int &i = ptr[v]; i < sz(adj[v]); i++) {
//            Edge &e = adj[v][i];
//            if (lvl[e.to] == lvl[v] + 1)
//                if (ll p = dfs(e.to, t, min(f, e.c))) {
//                    e.c -= p, adj[e.to][e.rev].c += p;
//                    return p;
//                }
//        }
//        return 0;
//    }
//
//    ll calc(int s, int t) {
//        ll flow = 0;
//        q[0] = s;
//        rep(L, 0, 31) do { // 'int L=30' maybe faster for random data
//                lvl = ptr = vi(sz(q));
//                int qi = 0, qe = lvl[s] = 1;
//                while (qi < qe && !lvl[t]) {
//                    int v = q[qi++];
//                    for (Edge e: adj[v])
//                        if (!lvl[e.to] && e.c >> (30 - L))
//                            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
//                }
//                while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
//            } while (lvl[t]);
//        return flow;
//    }
//
//    bool leftOfMinCut(int a) { return lvl[a] != 0; }
//};
//
//
//int main() {
//    cin.tie(0)->sync_with_stdio(0);
//    cin.exceptions(cin.failbit);
//
//    int n;
//    cin >> n;
//    vector<vector<int>> grid(n, vector<int>(n));
//    for (int i = 0; i < n; ++i) {
//        string s;
//        cin >> s;
//        for (int j = 0; j < n; ++j) {
//            grid[j][i] = (s[j] == 'Y');
//        }
//    }
//    vector<vector<int>> sol;
//    while (true) {
//        Dinic f(2 * n + 2);
//        for (int i = 2; i <= n + 1; ++i) {
//            f.addEdge(0, i, 1);
//        }
//        for (int i = n + 2; i < 2 * n + 2; ++i) {
//            f.addEdge(i, 1, 1);
//        }
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (grid[i][j]) {
//                    f.addEdge(i + 2, j + n + 2, 1);
//                }
//            }
//        }
//        if (f.calc(0, 1) != n) {
//            break;
//        }
//        vector<int> take(n);
//        for (int i = 0; i < n; ++i) {
//            for (auto &j: f.adj[i + 2]) {
//                if (j.flow()) {
//                    take[i] = j.to - n - 1;
//                    grid[i][j.to - n - 2] = false;
//                }
//            }
//        }
//        sol.push_back(take);
//    }
//
//    cout << sol.size() << "\n";
//    for (auto &i: sol) {
//        for (auto &j: i) {
//            cout << j << " ";
//        }
//        cout << "\n";
//    }
//}