/* Author: izhang
 * Time: 03-27-2022 10:35:01
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
        for (auto &li : gr)
            for (int x : li) indeg[x]++;
        queue<int> q; // use priority_queue for lexic. largest ans.
        rep(i, 0, sz(gr)) if (indeg[i] == 0) q.push(i);
        while (!q.empty()) {
            int i = q.front(); // top() for priority queue
            ret.push_back(i);
            q.pop();
            for (int x : gr[i])
                if (--indeg[x] == 0) q.push(x);
        }
        return ret;
    }

} // namespace kactl
//using namespace kactl;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<int> c(n);
    int ind = -1;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (c[i] == 1) {
            ind = i;
        }
    }
    if (ind == -1) {
        cout << "NO"
             << "\n";
        return;
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        adj[0].push_back(i);
    }
    rotate(c.begin(), c.begin() + ind, c.end());
    dbg() << c;
    stack<int> mx;
    mx.push(0);
    int pre = 1;
    for (int i = 1; i < n; ++i) {
        if (c[i] <= pre) {
            int diff = pre - c[i];
            while (!mx.empty() && diff--) {
                mx.pop();
            }
            if (mx.empty()) {
                dbg() << "bad1: " << i;
                cout << "NO"
                     << "\n";
                return;
            }
            adj[i].push_back(mx.top());
            mx.pop();
            mx.push(i);
        } else {
            if (c[i] - pre > 1) {
                dbg() << "bad2: " << i;
                cout << "NO"
                     << "\n";
                return;
            }
            adj[i - 1].push_back(i);
            mx.push(i);
        }
        pre = c[i];
    }
    dbg() << n;
    dbg() << adj;
    vector<int> res = kactl::topoSort(adj);
    cout << (int(res.size()) == n ? "YES" : "NO") << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        dbg() << "test_case: " << test_case_number;
        test_case();
    }
    return 0;
}
