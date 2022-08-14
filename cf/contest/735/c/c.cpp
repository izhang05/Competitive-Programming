/* Author: izhang
 * Time: 08-10-2022 18:21:03
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
     * Author: Lukas Polacek
     * Date: 2009-10-28
     * License: CC0
     * Source: Czech graph algorithms book, by Demel. (Tarjan's algorithm)
     * Description: Finds strongly connected components in a
     * directed graph. If vertices $u, v$ belong to the same component,
     * we can reach  from  and vice versa.
     * Usage: scc(graph, [\&](vi\& v) { ... }) visits all components
     * in reverse topological order. comp[i] holds the component
     * index of a node (a component only has edges to components with
     * lower index). ncomps will contain the number of components.
     * Time: O(E + V)
     * Status: Bruteforce-tested for N <= 5
     */

    vi val, comp, z, cont;
    int Time, ncomps;
    template<class G, class F>
    int dfs(int j, G &g, F &f) {
        int low = val[j] = ++Time, x;
        z.push_back(j);
        for (auto e : g[j])
            if (comp[e] < 0)
                low = min(low, val[e] ?: dfs(e, g, f));

        if (low == val[j]) {
            do {
                x = z.back();
                z.pop_back();
                comp[x] = ncomps;
                cont.push_back(x);
            } while (x != j);
            f(cont);
            cont.clear();
            ncomps++;
        }
        return val[j] = low;
    }
    template<class G, class F>
    void scc(G &g, F f) {
        int n = sz(g);
        val.assign(n, 0);
        comp.assign(n, -1);
        Time = ncomps = 0;
        rep(i, 0, n) if (comp[i] < 0) dfs(i, g, f);
    }

} // namespace kactl
//using namespace kactl;

void test_case() {
    long long n;
    cin >> n;
    vector<long long> fib(90);
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < int(fib.size()); ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << prev(upper_bound(fib.begin(), fib.end(), n)) - fib.begin() << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
