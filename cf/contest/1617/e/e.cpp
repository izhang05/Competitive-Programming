/* Author: izhang
 * Time: 02-23-2022 23:11:39
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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double PI = acos((long double) -1);
struct chash {                                       /// use most bits rather than just the lowest ones
    const uint64_t C = (long long) (2e18 * PI) + 71; // large odd number
    const int RANDOM = rng();
    long long operator()(long long x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x ^ RANDOM) * C);
    }
};
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
     * Author: Unknown
     * Date: 2002-09-13
     * Source: predates tinyKACTL
     * Description: Topological sorting. Given is an oriented graph.
     * Output is an ordering of vertices, such that there are edges only from left to right.
     * If there are cycles, the returned list will have size smaller than  -- nodes reachable
     * from cycles will not be returned.
     * Time: $O(|V|+|E|)$
     * Status: stress-tested
     */

    vi topoSort(gp_hash_table<int, int, chash> &gr) {
        gp_hash_table<int, int, chash> indeg;
        vi ret;
        for (auto &i : gr) {
            indeg[i.first] = 0;
        }
        for (auto &li : gr)
            ++indeg[li.second];
        queue<int> q; // use priority_queue for lexic. largest ans.
        for (auto &i : indeg) {
            if (i.second == 0) {
                q.push(i.first);
            }
        }
        while (!q.empty()) {
            int i = q.front(); // top() for priority queue
            ret.push_back(i);
            q.pop();
            gr[i];
            if (--indeg[gr[i]] == 0) q.push(gr[i]);
        }
        return ret;
    }

} // namespace kactl
//using namespace kactl;
gp_hash_table<int, int, chash> nxt;
//gp_hash_table<int, gp_hash_table<int, null_type, chash>, chash> adj;
gp_hash_table<int, pair<pair<int, int>, pair<int, int>>, chash> mx;

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx[a[i]].first = {0, i + 1};
        int x = a[i];
        while (x) {
            if (x == 1) {
                nxt[x] = 0;
                x = 0;
            } else {
                nxt[x] = (1 << (__lg(x - 1) + 1)) - x;
                x = (1 << (__lg(x - 1) + 1)) - x;
            }
        }
    }
    vector<int> t = kactl::topoSort(nxt);
    for (auto &i : t) {
        if (i == 0) {
            break;
        }
        pair<int, int> cur = {mx[i].first.first + 1, mx[i].first.second};
        if (cur > mx[nxt[i]].first) {
            mx[nxt[i]].second = mx[nxt[i]].first;
            mx[nxt[i]].first = cur;
        } else if (cur > mx[nxt[i]].second) {
            mx[nxt[i]].second = cur;
        }
    }
    pair<int, pair<int, int>> sol;
    for (auto &i : mx) {
        if (i.second.first.second && i.second.second.second) {
            sol = max(sol, {i.second.first.first + i.second.second.first, {i.second.first.second, i.second.second.second}});
        }
    }
    cout << sol.second.first << " " << sol.second.second << " " << sol.first << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}