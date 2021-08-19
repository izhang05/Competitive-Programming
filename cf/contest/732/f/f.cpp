/* Author: izhang05
 * Time: 08-18-2021 23:54:20
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 4e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[maxn], dfs_adj[maxn];
int depth[maxn], dp[maxn], tree_vis[maxn], cur = 0;
bool vis[maxn];
pair<int, int> sol[maxn], sz = {0, 0};

void dfs2(int c, int p) {
    ++cur;
    tree_vis[c] = true;
    for (auto &i : dfs_adj[c]) {
        if (i.first != p && !tree_vis[i.first]) {
            sol[i.second] = {c, i.first};
            dfs2(i.first, c);
        }
    }
}

void dfs1(int c, int d, int p) {
    vis[c] = true;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i.first != p) {
            if (!vis[i.first]) {
                dfs_adj[c].push_back(i);
                dfs1(i.first, d + 1, c);
                dp[c] += dp[i.first];
            } else {
                if (depth[i.first] < depth[c]) {
                    sol[i.second] = {c, i.first};
                    ++dp[c];
                } else if (depth[c] < depth[i.first]) {
                    sol[i.second] = {i.first, c};
                    --dp[c];
                }
            }
        }
    }
    if (!dp[c]) {
        cur = 0;
        dfs2(c, p);
        sz = max(sz, {cur, c});
    }
}

void dfs3(int c, int p) {
    vis[c] = true;
    for (auto &i : adj[c]) {
        if (i.first != p) {
            if (!vis[i.first]) {
                if (sol[i.second] == make_pair(0, 0)) {
                    sol[i.second] = {i.first, c};
                }
                dfs3(i.first, c);
            }
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
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }
    dfs1(0, -1, 0);
    if (!tree_vis[0]) {
        cur = 0;
        dfs2(0, -1);
        sz = max(sz, {cur, 0});
    }
    int root = sz.second;
    memset(vis, false, sizeof(vis));
    dfs3(root, -1);
    cout << sz.first << "\n";
    for (int i = 0; i < m; ++i) {
        cout << sol[i].first + 1 << " " << sol[i].second + 1 << "\n";
    }
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
