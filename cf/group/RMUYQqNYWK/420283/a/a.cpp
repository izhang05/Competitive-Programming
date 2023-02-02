/* Author: izhang
 * Time: 01-30-2023 14:03:07
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;

    /**
     * Author: Simon Lindholm
     * Date: 2019-12-31
     * License: CC0
     * Source: folklore
     * Description: Eulerian undirected/directed path/cycle algorithm.
     * Input should be a vector of (dest, global edge index), where
     * for undirected graphs, forward/backward edges have the same index.
     * Returns a list of nodes in the Eulerian path/cycle with src at both start and end, or
     * empty list if no cycle/path exists.
     * To get edge indices back, add .second to s and ret.
     * Time: O(V + E)
     * Status: stress-tested
     */

    vi eulerWalk(vector<vector<pii>> &gr, int nedges, int src = 0) {
        int n = sz(gr);
        vi D(n), its(n), eu(nedges), ret, s = {src};
        D[src]++; // to allow Euler paths, not just cycles
        while (!s.empty()) {
            int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
            if (it == end) {
                ret.push_back(x);
                s.pop_back();
                continue;
            }
            tie(y, e) = gr[x][it++];
            if (!eu[e]) {
                D[x]--, D[y]++;
                eu[e] = 1;
                s.push_back(y);
            }
        }
        for (int x : D)
            if (x < 0 || sz(ret) != nedges + 1) return {};
        return {ret.rbegin(), ret.rend()};
    }

} // namespace kactl
//using namespace kactl;

void test_case() {
    int n, m;
    cin >> n >> m;
    int ind = 0;
    vector<int> deg(n);
    set<pair<int, int>> edges;
    vector<vector<pair<int, int>>> adj(n + 3);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges.insert({u, v});
        edges.insert({v, u});
        ++deg[u], ++deg[v];
        adj[u].emplace_back(v, ind);
        adj[v].emplace_back(u, ind);
        ++ind;
    }
    vector<int> odd;
    for (int i = 0; i < n; ++i) {
        if (deg[i] % 2 == 1) {
            odd.push_back(i);
        }
    }
    for (int &i : odd) {
        adj[n].emplace_back(i, ind);
        adj[i].emplace_back(n, ind);
        ++ind;
    }
    cout << n - int(odd.size()) << "\n";
    dbg() << adj;
    for (int i = 0; i <= n; ++i) {
        adj[i].emplace_back(n + 1, ind);
        adj[n + 1].emplace_back(i, ind);
        ++ind;
        adj[i].emplace_back(n + 2, ind);
        adj[n + 2].emplace_back(i, ind);
        ++ind;
    }
    if (n % 2 == 0) {
        adj[n + 1].emplace_back(n + 2, ind);
        adj[n + 2].emplace_back(n + 1, ind);
        ++ind;
    }
    vector<int> walk = kactl::eulerWalk(adj, ind);
    dbg() << walk;
    for (int j = 0; j < int(walk.size()) - 1; ++j) {
        pair<int, int> cur = {walk[j], walk[j + 1]};
        if (edges.find(cur) != edges.end()) {
            cout << cur.first + 1 << " " << cur.second + 1 << "\n";
        }
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
