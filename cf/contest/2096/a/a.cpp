/* Author: izhang
 * Time: 06-20-2025 15:42:05
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

    vi topoSort(const vector<vi> &gr) {
        vi indeg(sz(gr)), ret;
        for (auto &li: gr) for (int x: li) indeg[x]++;
        queue<int> q; // use priority_queue for lexic. largest ans.
        rep(i, 0, sz(gr)) if (indeg[i] == 0) q.push(i);
        while (!q.empty()) {
            int i = q.front(); // top() for priority queue
            ret.push_back(i);
            q.pop();
            for (int x: gr[i])
                if (--indeg[x] == 0) q.push(x);
        }
        return ret;
    }

}
//using namespace kactl;

void test_case() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<') {
            for (int j = 0; j <= i; ++j) {
                adj[i + 1].push_back(j);
            }
        } else {
            for (int j = 0; j <= i; ++j) {
                adj[j].push_back(i + 1);
            }
        }
    }
    vector<int> top = kactl::topoSort(adj);
    vector<int> sol(n);
    int cur = 1;
    for (auto &i: top) {
        sol[i] = cur++;
    }
    for (auto &i: sol) {
        cout << i << " ";
    }
    cout << "\n";
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
