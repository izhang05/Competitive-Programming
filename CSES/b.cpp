#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

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
                if (--indeg[x] == 0)
                    q.push(x);
        }
        return ret;
    }

} // namespace kactl
//using namespace kactl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    long double x = 1;
    for (int i = 0; i < 1e5; ++i) {
        x *= .01;
    }
    cout << x << "\n";
    cout << 1 - x << "\n";
    return 0;
}
