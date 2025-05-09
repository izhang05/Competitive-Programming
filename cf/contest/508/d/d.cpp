/* Author: izhang
 * Time: 03-26-2022 00:57:46
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
string two[4000];

void test_case() {
    int m;
    cin >> m;
    int n = 0;
    vector<char> c;
    map<string, int> ind;
    for (char i = 'a'; i <= 'z'; ++i) {
        c.push_back(i);
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
        c.push_back(i);
    }
    for (char i = '0'; i <= '9'; ++i) {
        c.push_back(i);
    }
    for (int i = 0; i < int(c.size()); ++i) {
        for (int j = 0; j < int(c.size()); ++j) {
            two[n] = c[i];
            two[n].push_back(c[j]);
            ind[two[n]] = n;
            ++n;
        }
    }
    vector<vector<pair<int, int>>> edges(n);
    vector<int> out(n), in(n);
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        string a, b;
        a += s[0], a += s[1];
        b += s[1], b += s[2];
        edges[ind[a]].emplace_back(ind[b], i);
        dbg() << a << " " << b << " " << ind[a] << " " << ind[b];
        ++out[ind[a]], ++in[ind[b]];
    }
    vector<int> sol;
    for (int i = 0; i < n; ++i) {
        if (out[i] > in[i]) {
            sol = kactl::eulerWalk(edges, m, i);
            break;
        }
    }
    if (sol.empty()) {
        for (int i = 0; i < n; ++i) {
            if (out[i] + in[i] > 0) {
                sol = kactl::eulerWalk(edges, m, i);
            }
        }
    }
    dbg() << sol;
    if (sol.empty()) {
        cout << "NO"
             << "\n";
    } else {
        cout << "YES"
             << "\n";
        string s = two[sol[0]];
        for (int i = 1; i < int(sol.size()); ++i) {
            s.push_back(two[sol[i]][1]);
        }
        cout << s << "\n";
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
