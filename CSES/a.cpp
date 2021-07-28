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
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<int> adj[maxn], dfs_adj[maxn];
bool vis[maxn], tree_vis[maxn];
int dp[maxn], depth[maxn];
vector<int> cur;
vector<vector<int>> sol;

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
        if (i != p || pcount) {
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs1(i, 0, -1);
            if (!tree_vis[i]) {
                cur.clear();
                dfs2(i, -1);
                sol.push_back(cur);
            }
        }
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i.size() << " ";
        print(i);
    }
    return 0;
}
