/* Author: izhang05
 * Time: 08-19-2021 11:59:15
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
vector<int> adj[maxn], adj_tree[maxn], dfs_adj[maxn], new_adj_tree[maxn];
bool vis[maxn];
int depth[maxn], dp[maxn], comp_vis[maxn], cur_comp, comp[maxn];

void dfs2(int c, int p) {
    comp_vis[c] = true;
    comp[c] = cur_comp;
    for (auto &i : dfs_adj[c]) {
        if (i != p && !comp_vis[i]) {
            dfs2(i, c);
        }
    }
}

void dfs1(int c, int d, int p) {
    vis[c] = true;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i != p) {
            if (!vis[i]) {
                dfs_adj[c].push_back(i);
                dfs1(i, d + 1, c);
                dp[c] += dp[i];
            } else {
                if (depth[i] < depth[c]) {
                    ++dp[c];
                } else if (depth[c] < depth[i]) {
                    --dp[c];
                }
            }
        }
    }
    if (!dp[c]) {
        dfs2(c, p);
        ++cur_comp;
        if (p != -1) {
            adj_tree[p].push_back(c);
            adj_tree[c].push_back(p);
        }
    }
}
pair<int, int> endp;

void dfs3(int c, int p, int d = 0) {
    endp = max(endp, {d, c});
    for (auto &i : adj_tree[c]) {
        if (i != p) {
            dfs3(i, c, d + 1);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0, 0, -1);
    if (!comp_vis[0]) {
        dfs2(0, -1);
    }
    for (int i = 0; i < n; ++i) {
        for (auto &j : adj_tree[i]) {
            j = comp[j];
            new_adj_tree[comp[i]].push_back(j);
        }
    }
    swap(new_adj_tree, adj_tree);
    dfs3(0, -1);
    int rt = endp.second;
    endp = {0, 0};
    dfs3(rt, -1);
    cout << endp.first << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
