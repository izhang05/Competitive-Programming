/* Author: izhang
 * Time: 09-06-2023 23:06:14
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG

#include <debug.h>

#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
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
            dbg() << a << " " << b << " " << c;
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

}
//using namespace kactl;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, r, f, t;
    cin >> n >> r >> f >> t;
    map<string, int> ind;
    // [2, r + 2) in U, [r + 2, r + f + 2) in V
    kactl::Dinic flow(n + 2 * t + 2);
    dbg() << n + 2 * t + 2;
    for (int i = 2; i < r + 2; ++i) {
        flow.addEdge(0, i, 1);
    }
    for (int i = r + 2; i < r + f + 2; ++i) {
        flow.addEdge(i, 1, 1);
    }
    int cur_ind = 2;
    for (int i = 0; i < r; ++i) {
        string s;
        cin >> s;
        ind[s] = cur_ind++;
    }
    for (int i = 0; i < f; ++i) {
        string s;
        cin >> s;
        ind[s] = cur_ind++;
    }
    for (int i = 0; i < t; ++i) {
        int m;
        cin >> m;
        int cur_t = cur_ind++;
        ++cur_ind;
        flow.addEdge(cur_t, cur_t + 1, 1);
        for (int j = 0; j < m; ++j) {
            string s;
            cin >> s;
            if (ind.find(s) == ind.end()) {
                ind[s] = cur_ind++;
            }
            if (ind[s] >= r + f + 2) {
                flow.addEdge(ind[s], cur_t, 1);
                flow.addEdge(cur_t + 1, ind[s], 1);
            } else if (ind[s] < r + 2) {
                flow.addEdge(ind[s], cur_t, 1);
            } else {
                flow.addEdge(cur_t + 1, ind[s], 1);
            }
        }
    }
    cout << flow.calc(0, 1) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
