#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5, maxs = 20;


vector<pair<int, int>> adj[maxn];
int up[maxn][maxs], mn[maxn][maxs], depth[maxn], n;

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

void dfs(int c, int p, int d) {
    up[c][0] = p;
    depth[c] = d;
    for (pair<int, int> i : adj[c]) {
        if (i.first != p) {
            mn[i.first][0] = i.second;
            dfs(i.first, c, d + 1);
        }
    }
}

void build() {
    for (int i = 1; i < maxs; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            up[j][i] = up[up[j][i - 1]][i - 1];
            mn[j][i] = min(mn[j][i - 1], mn[up[j][i - 1]][i - 1]);
        }
    }
}

int path_min(int x, int d) {
    int res = 1e9;
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            res = min(res, mn[x][i]);
            x = up[x][i];
        }
    }
    return res;
}

int query(int a, int b) {
    int l = lca(a, b);
    return min(path_min(a, depth[a] - depth[l]), path_min(b, depth[b] - depth[l]));
}

int main() {
    setIO("1");

    int m;
    cin >> n >> m;
    assert(m == n - 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    dfs(1, 0, 0);
    build();
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << "\n";
    }
    return 0;
}
