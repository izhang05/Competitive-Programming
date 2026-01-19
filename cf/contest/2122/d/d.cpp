/* Author: izhang
 * Time: 09-19-2025 20:55:22
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 5e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
pair<int, int> dist[mxn][mxn];
vector<int> adj[mxn];
int deg[mxn];


void test_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = {inf, inf};
        }
        adj[i].clear();
        deg[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++deg[u], ++deg[v];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist[0][0] = {0, 0};
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<>> pq;
    pq.push({{0, 0},
             {0, 0}});
    pair<int, int> sol = {inf, inf};
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        pair<int, int> node = cur.second, val = cur.first;
        if (node.first == n - 1) {
            sol = min(sol, val);
        }
        if (dist[node.first][node.second] != val) {
            continue;
        }
        if (dist[node.first][(node.second + 1) % deg[node.first]] > make_pair(val.first + 1, val.second + 1)) {
            dist[node.first][(node.second + 1) % deg[node.first]] = {val.first + 1, val.second + 1};
            pq.push({{val.first + 1, val.second + 1},
                     {node.first,    (node.second + 1) % deg[node.first]}});
        }
        assert(node.second == val.first % deg[node.first]);
        int next_node = adj[node.first][val.first % deg[node.first]];
        if (dist[next_node][(val.first + 1) % deg[next_node]] > make_pair(val.first + 1, val.second)) {
            dist[next_node][(val.first + 1) % deg[next_node]] = {val.first + 1, val.second};
            pq.push({{val.first + 1, val.second},
                     {next_node,     (val.first + 1) % deg[next_node]}});
        }
    }
    cout << sol.first << " " << sol.second << "\n";
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
