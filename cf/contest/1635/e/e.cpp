/* Author: izhang
 * Time: 02-20-2022 09:35:36
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
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

vector<pair<int, int>> adj[maxn];
bool visited[maxn];
int color[maxn];
void dfs(int c, int p, int cur_color) {
    visited[c] = true;
    color[c] = cur_color;
    for (auto &i : adj[c]) {
        if (i.first != p) {
            if (visited[i.first] && color[i.first] == cur_color) {
                cout << "NO\n";
                exit(0);
            }
            if (!visited[i.first]) {
                dfs(i.first, c, cur_color ^ 1);
            }
        }
    }
}

void test_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        --t, --a, --b;
        adj[a].emplace_back(b, t);
        adj[b].emplace_back(a, t);
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, -1, 0);
        }
    }
    vector<vector<int>> n_adj(n);
    for (int i = 0; i < n; ++i) {
        for (auto &j : adj[i]) {
            if (color[i] == j.second) {
                n_adj[i].push_back(j.first);
            }
        }
    }
    vector<int> res = kactl::topoSort(n_adj);
    if (int(res.size()) < n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<pair<char, int>> sol(n);
    int ind = 0;
    for (auto &i : res) {
        sol[i] = {color[i] ? 'R' : 'L', ind++};
    }
    for (auto &i : sol) {
        cout << i.first << " " << i.second << "\n";
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
