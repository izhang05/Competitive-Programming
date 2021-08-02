#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<pair<int, int>> adj[maxn];
bool vis[maxn];
int depth[maxn], dp[maxn];
int sol[maxn];// 0 = not visited, 1 = left, 2 = right, 3 = both

void dfs2(int c, int p) {
    tree_vis[c] = true;
    cur.push_back(c);
    for (auto &i : dfs_adj[c]) {
        if (i != p && !tree_vis[i]) {
            dfs2(i, c);
        }
    }
}

void dfs1(int c, int d, int p) {
    vis[c] = true;
    depth[c] = d;
    int pcount = 0;
    for (auto &i : adj[c]) {
        if (i.first != p || pcount) {
            if (!vis[i.first]) {
                dfs_adj[c].push_back(i);
                dfs1(i.first, d + 1, c);
                dp[c] += dp[i.first];
            } else {
                if (depth[i.first] < depth[c]) {
                    ++dp[c];
                } else if (depth[c] < depth[i.first]) {
                    --dp[c];
                }
            }
        } else {
            ++pcount;
        }
    }
    if (!dp[c]) {
        cur.clear();
        dfs2(c, p);
        sol.push_back(cur);
    }
}


int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i, 0, -1);
        }
    }
    return 0;
}
