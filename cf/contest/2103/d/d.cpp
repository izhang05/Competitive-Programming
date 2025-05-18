/* Author: izhang
 * Time: 05-15-2025 16:10:38
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;
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
set<int> adj[mxn];

void test_case() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
        a[i].first = i;
        adj[i].clear();
    }
    int round = 1;
    while ((int) a.size() > 1) {
        int m = a.size();
        vector<pair<int, int>> nxt;
        bool beg = true;
        for (int i = 0; i < m; ++i) {
            if (a[i].second != round) {
                beg = false;
                nxt.push_back(a[i]);
                if (round % 2 == 1) {
                    if (i > 0) {
                        adj[a[i].first].insert(a[i - 1].first);
                    }
                    if (i + 1 < m) {
                        adj[a[i].first].insert(a[i + 1].first);
                    }
                } else {
                    if (i > 0) {
                        adj[a[i - 1].first].insert(a[i].first);
                    }
                    if (i + 1 < m) {
                        adj[a[i + 1].first].insert(a[i].first);
                    }
                }
            } else {
                if (round % 2 == 1) {
                    if (beg) {
                        adj[a[i + 1].first].insert(a[i].first);
                    } else {
                        adj[a[i - 1].first].insert(a[i].first);
                    }
                } else {
                    if (beg) {
                        adj[a[i].first].insert(a[i + 1].first);
                    } else {
                        adj[a[i].first].insert(a[i - 1].first);
                    }
                }
            }
        }
        ++round;
        swap(nxt, a);
    }
    vector<vector<int>> edges(n);
    for (int i = 0; i < n; ++i) {
        edges[i] = vector(adj[i].begin(), adj[i].end());
    }
    vector<int> top = kactl::topoSort(edges);
    vector<int> sol(n);
    for (int i = 0; i < n; ++i) {
        sol[top[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " \n"[i == n - 1];
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
