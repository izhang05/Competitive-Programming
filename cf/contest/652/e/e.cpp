/* Author: izhang
 * Time: 02-06-2022 23:04:14
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct edge {
    int to, w;
    bool bridge;
};
vector<edge> adj[maxn], tree_adj[maxn], comp_adj[maxn];
bool visited[maxn];
int depth[maxn], dp[maxn];
int comp[maxn], t = 0;

void dfs1(int c, int p, int d = 0) {
    visited[c] = true;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i.to != p) {
            if (!visited[i.to]) {
                tree_adj[c].push_back(i);
                dfs1(i.to, c, d + 1);
            } else {
                if (depth[i.to] < depth[c]) {
                    ++dp[i.to];
                    --dp[c];
                } else {
                    --dp[i.to];
                    ++dp[c];
                }
            }
        }
    }
}

void dfs2(int c, int cnt = 0) {
    cnt += dp[c];
    for (auto &i : tree_adj[c]) {
        if (cnt == 0) {
            i.bridge = true;
        }
        dfs2(i.to, cnt);
    }
}

void dfs3(int c, int p) {
    comp[c] = t;
    for (auto &i : adj[c]) {
        if (i.to != p && !i.bridge) {
            dfs3(i.to, c);
        }
    }
}

void test_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b, c, false});
        adj[b].push_back({a, c, false});
    }
    dfs1(0, -1);
    dfs2(0);
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs3(i, -1);
            ++t;
        }
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
