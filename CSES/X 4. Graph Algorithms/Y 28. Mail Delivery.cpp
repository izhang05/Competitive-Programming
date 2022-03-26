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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
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
            if (x < 0 || sz(ret) != nedges + 1)
                return {};
        return {ret.rbegin(), ret.rend()};
    }

} // namespace kactl
//using namespace kactl;

int main() {
    setIO("28");
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        edges[a].emplace_back(b, i);
        edges[b].emplace_back(a, i);
    }
    vector<int> sol = kactl::eulerWalk(edges, m);
    if (sol.empty() || sol[0] != sol.back()) {
        cout << "IMPOSSIBLE"
             << "\n";
    } else {
        for (auto &i : sol) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
