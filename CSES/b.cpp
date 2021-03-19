#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    freopen("b.out", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxs = 20;
vector<int> adj[maxn];
int depth[maxn], sub[maxn], n, par[maxn], up[maxn][maxs], best[maxn];
bool visited[maxn];

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
    for (auto i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

int find_centroid(int c, int p, int s) {
    for (auto i : adj[c]) {
        if (!visited[i] && sub[i] > s / 2 && i != p) {
            return find_centroid(i, c, s);
        }
    }
    return c;
}

int find_size(int v, int p = -1) {
    if (visited[v]) {
        return 0;
    }
    sub[v] = 1;

    for (int x : adj[v]) {
        if (x != p) {
            sub[v] += find_size(x, v);
        }
    }

    return sub[v];
}

void build(int v = 0, int p = -1) {
    find_size(v);

    int c = find_centroid(v, -1, sub[v]);
    visited[c] = true;
    par[c] = p;

    for (int x : adj[c]) {
        if (!visited[x]) {
            build(x, c);
        }
    }
}

void update(int c) {
    best[c] = 0;
    int u = c;
    while (par[u] != -1) {
        u = par[u];
        best[u] = min(best[u], dist(u, c));
    }
}

int query(int c) {
    int sol = best[c], u = c;
    while (par[u] != -1) {
        u = par[u];
        sol = min(sol, best[u] + dist(u, c));
    }
    return sol;
}

int main() {
    setIO();

    int m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(best, 0x3f, sizeof(best));
    dfs(0, -1, 0);
    for (int i = 1; i < maxs; ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[j][i - 1] == -1) {
                up[j][i] = -1;
            } else {
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
    build();
    update(0);
#ifdef DEBUG
    cout << dist(0, 1) << "\n";
    for (int j = 0; j < n; ++j) {
        cout << best[j] << " ";
    }
    cout << "\n";
#endif
    for (int i = 0; i < m; ++i) {
        int t, c;
        cin >> t >> c;
        --c;
        if (t == 1) {
            update(c);
        } else {
            cout << query(c) << "\n";
        }
    }
    return 0;
}
