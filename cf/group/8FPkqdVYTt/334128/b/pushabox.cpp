/* Author: izhang05
 * Time: 08-21-2021 14:00:04
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int maxn = 1505, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char grid[maxn][maxn];
int n, m, depth[maxn * maxn], dp[maxn * maxn], tree_vis[maxn * maxn], cur = 0, bcc[maxn * maxn], comp[maxn * maxn], cur_comp = 0;
vector<int> adj[maxn * maxn], dfs_adj[maxn * maxn];

int ind(int x, int y) {
    return x * m + y;
}

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool vis[maxn * maxn];

void dfs2(int c, int p) {
    comp[c] = cur_comp;
    tree_vis[c] = true;
    bcc[c] = cur;
    for (auto &i : dfs_adj[c]) {
        if (i != p && !tree_vis[i]) {
            dfs2(i, c);
        }
    }
}

void dfs1(int c, int d, int p) {
    cout << c << " " << d << " " << p << "\n";
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
        ++cur;
    }
}

bool bfs_vis[maxn][maxn][4];

int main() {
    setIO("pushabox");
    int q;
    cin >> n >> m >> q;
    int start, box;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                grid[i][j] = '.';
                start = ind(i, j);
            } else if (grid[i][j] == 'B') {
                grid[i][j] = '.';
                box = ind(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                int cur = ind(i, j);
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (valid(x, y) && grid[x][y] == '.') {
                        adj[cur].push_back(ind(x, y));
                    }
                }
            }
        }
    }
    for (int i = 0; i < n * m; ++i) {
        if (!vis[i]) {
            dfs1(i, 0, -1);
            if (!tree_vis[i]) {
                dfs2(0, -1);
            }
            ++cur_comp;
        }
    }
    if (comp[start] != comp[box]) {
        for (int i = 0; i < q; ++i) {
            cout << "NO\n";
        }
        return 0;
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        int u = ind(x, y);
    }
    return 0;
}
