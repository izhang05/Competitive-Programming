/* Author: izhang
 * Time: 06-19-2024 14:59:23
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

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
                    for (Edge e : adj[v])
                        if (!lvl[e.to] && e.c >> (30 - L))
                            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
                }
                while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
            }
            while (lvl[t])
                ;
            return flow;
        }
        bool leftOfMinCut(int a) { return lvl[a] != 0; }
    };

} // namespace kactl
//using namespace kactl;

void test_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
