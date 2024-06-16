/* Author: izhang
 * Time: 06-01-2024 16:30:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 3e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool prime[mxn];
vector<int> primes;

void test_case() {
    long long n;
    cin >> n;
    long long lo = 1, hi = int(primes.size()), mid, sol;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        long long edges = (mid * (mid - 1)) / 2 + mid;
        if (mid % 2 == 0) {
            edges -= ((mid / 2) - 1);
        }
        if (edges >= n - 1) {
            sol = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    vector<vector<pair<int, int>>> graph(sol);
    map<pair<int, int>, int> ind;
    int cur_ind = 0;
    if (sol % 2 == 1) {
        for (int i = 0; i < sol; ++i) {
            for (int j = 0; j < sol; ++j) {
                if (i == j) {
                    continue;
                }
                pair<int, int> cur = {min(i, j), max(i, j)};
                if (ind.find(cur) == ind.end()) {
                    ind[cur] = cur_ind++;
                }
                graph[i].emplace_back(j, ind[cur]);
            }
        }
    } else {
        for (int i = 0; i < sol; ++i) {
            for (int j = 0; j < sol; ++j) {
                if (abs(i - j) == 1 && min(i, j) % 2 == 0) {
                    continue;
                }
                if (i == j) {
                    continue;
                }
                pair<int, int> cur = {min(i, j), max(i, j)};
                if (ind.find(cur) == ind.end()) {
                    ind[cur] = cur_ind++;
                }
                graph[i].emplace_back(j, ind[cur]);
            }
        }
        pair<int, int> cur = {0, 1};
        ind[cur] = cur_ind++;
        graph[0].emplace_back(1, ind[cur]);
        graph[1].emplace_back(0, ind[cur]);
    }
    dbg() << graph << " " << cur_ind << " " << sol;
    vector<int> tmp = kactl::eulerWalk(graph, cur_ind);
    set<int> seen;
    vector<int> res;
    for (auto &i : tmp) {
        res.push_back(i);
        if (seen.find(i) == seen.end()) {
            res.push_back(i);
            seen.insert(i);
        }
    }
    dbg() << res;
    for (int i = 0; i < n; ++i) {
        cout << primes[res[i]] << " ";
    }
    cout << endl;
}

int main() {
    setIO("1");
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i < mxn; ++i) {
        if (prime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < mxn; j += i) {
                prime[j] = false;
            }
        }
    }
    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
