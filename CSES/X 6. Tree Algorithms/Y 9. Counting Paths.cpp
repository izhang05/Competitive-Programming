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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, maxs = 20;
vector<int> adj[maxn];
int up[maxn][maxs], depth[maxn], n, pre[maxn];

void dfs(int c, int p, int d = 0) {
    up[c][0] = p;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x;
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    x = jmp(x, depth[x] - depth[y]);
    if (x == y) {
        return x;
    }
    for (int i = maxs - 1; i >= 0; --i) {
        int new_x = up[x][i], new_y = up[y][i];
        if (new_x != new_y) {
            x = new_x, y = new_y;
        }
    }
    return up[x][0];
}

int dist(int x, int y) {
    int l = lca(x, y);
    return depth[x] - depth[l] + depth[y] - depth[l];
}

void build() {
    for (int i = 1; i < maxs; ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[j][i - 1] == -1) {
                up[j][i] = -1;
            } else {
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
}

void dfs_pre(int c, int p) {
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs_pre(i, c);
            pre[c] += pre[i];
        }
    }
}

int main() {
    setIO("9");
    int m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    build();
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ++pre[a];
        ++pre[b];
        int l = lca(a, b);
        --pre[l];
        if (l) {
            --pre[up[l][0]];
        }
    }
    dfs_pre(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << pre[i] << " ";
    }
    cout << "\n";
    return 0;
}
