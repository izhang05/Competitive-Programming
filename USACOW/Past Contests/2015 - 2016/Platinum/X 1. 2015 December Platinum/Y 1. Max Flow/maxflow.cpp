#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    freopen("maxflow.out", "w", stderr);
}
//#define DEBUG
const int maxn = 5e4 + 5, maxs = 20;
vector<int> adj[maxn];

int up[maxn][maxs], depth[maxn], n;

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

void dfs(int c = 0, int p = -1, int d = 0) {
    up[c][0] = p;
    depth[c] = d;
    for (int i : adj[c]) {
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

long long pre[maxn], sol = 0;

void solve(int c, int p) {
    for (auto &i : adj[c]) {
        if (i != p) {
            solve(i, c);
            pre[c] += pre[i];
        }
    }
    sol = max(sol, pre[c]);
}


int main() {
    setIO();
    int k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    build();
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        int l = lca(a, b);
        ++pre[a], ++pre[b];
        --pre[l];
        if (l) {
            --pre[up[l][0]];
        }
    }
    solve(0, -1);
    cout << sol << "\n";
    return 0;
}
