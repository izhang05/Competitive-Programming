/* Author: izhang05
 * Time: 10-18-2021 11:12:39
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxs = 19;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];

long long sol;
int sub[maxn], up[maxn][maxs], depth[maxn], n, mn_dist[maxn];
bool visited[maxn];

int find_size(int v, int p) {
    sub[v] = 1;
    for (auto &i : adj[v]) {
        if (i != p && !visited[i]) {
            sub[v] += find_size(i, v);
        }
    }
    return sub[v];
}

int centroid(int v, int p, int s) {
    for (auto &i : adj[v]) {
        if (i != p && !visited[i] && sub[i] > s / 2) {
            return centroid(i, v, s);
        }
    }
    return v;
}
int c_par[maxn];

int solve(int v) {
    find_size(v, -1);
    int c = centroid(v, -1, sub[v]);
    visited[c] = true;

    for (auto &i : adj[c]) {
        if (!visited[i]) {
        }
    }

    for (auto &i : adj[c]) {
        if (!visited[i]) {
            c_par[solve(i)] = c;
        }
    }
    return c;
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

void dfs(int c = 0, int p = -1, int d = 0) {
    up[c][0] = p;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
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
void update(int c) {
    int orig = c;
    mn_dist[c] = 0;
    while (c_par[c] != -1) {
        c = c_par[c];
        mn_dist[c] = min(mn_dist[c], dist(orig, c));
    }
}

int get_sol(int c) {
    int res = mn_dist[c], orig = c;
    while (c_par[c] != -1) {
        c = c_par[c];
        res = min(res, mn_dist[c] + dist(orig, c));
    }
    return res;
}

void solve() {
    int q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    build();
    memset(c_par, -1, sizeof(c_par));
    memset(mn_dist, 0x3f, sizeof(mn_dist));
    solve(0);
    update(0);
    while (q--) {
        int t, v;
        cin >> t >> v;
        --v;
        if (t == 1) {
            update(v);
        } else {
            cout << get_sol(v) << "\n";
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
