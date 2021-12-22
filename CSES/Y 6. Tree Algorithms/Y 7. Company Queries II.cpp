#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("7.in", "r", stdin);
    freopen("7.out", "w", stdout);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

const int maxn = 2e5 + 5, maxs = 18; // log_2 2e5$

int up[maxn][maxs], depth[maxn];
vector<int> adj[maxn];

int n;
int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x ?: -1; // modification to return -1 if not found
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
void dfs(int c, int p, int d) {
    depth[c] = d;
    for (int i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

int main() {
    setIO();

    int q;
    cin >> n >> q;
    for (int i = 2; i < n + 1; ++i) {
        int a;
        cin >> a;
        adj[a].push_back(i);
        up[i][0] = a;
    }

    for (int i = 1; i < maxs; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    dfs(1, -1, 0);
#ifdef DEBUG
    for (int i = 1; i < n + 1; ++i) {
        cout << i << " " << depth[i] << "\n";
    }
#endif
    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}