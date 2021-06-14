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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 4e5 + 5, maxs = 20;
int a[maxn], up[maxn][maxs], depth[maxn], n;
vector<pair<int, int>> adj[maxn];
long long down[maxn], up_dp[maxn], dp[maxn];

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

void dfs(int c, int p, int d) {
    up[c][0] = p;
    depth[c] = d;
    down[c] = a[c];
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs(i.first, c, d + 1);
            down[c] += max(0ll, down[i.first] - 2 * i.second);
        }
    }
}
void dfs2(int c, int p, int v) {
    if (p != -1) {
        up_dp[c] = max(0ll, up_dp[p] - 2 * v) + max(0ll, down[p] - max(0ll, down[c] - 2 * v) - 2 * v);
    }
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs2(i.first, c, i.second);
        }
    }
}

int main() {
    setIO("1");
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int b, c, d;
        cin >> b >> c >> d;
        --b, --c;
        adj[b].emplace_back(c, d);
        adj[c].emplace_back(b, d);
    }
    dfs(0, -1, 0);
    build();
    dfs2(0, -1, 0);
    for (int i = 0; i < n; ++i) {
        dp[i] = down[i] + up_dp[i];
#ifdef DEBUG
        cout << i + 1 << " " << dp[i] << " " << down[i] << " " << up_dp[i] << "\n";
#endif
    }
    while (q--) {
        int b, c;
        cin >> b >> c;
        --b, --c;
    }
    return 0;
}
