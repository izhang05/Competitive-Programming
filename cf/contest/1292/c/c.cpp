/* Author: izhang05
 * Time: 08-13-2021 00:10:40
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e3 + 5, maxs = 12;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[maxn][maxn], sub[maxn], up_cnt[maxn];
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

void dfs1(int c = 0, int p = -1, int d = 0) {
    up[c][0] = p;
    depth[c] = d;
    sub[c] = 1;
    for (int i : adj[c]) {
        if (i != p) {
            dfs1(i, c, d + 1);
            sub[c] += sub[i];
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

int dist(int x, int y) {
    int l = lca(x, y);
    return depth[x] - depth[l] + depth[y] - depth[l];
}

long long gen(int a, int b) {
    if (dp[a][b] != -1) {
        return dp[a][b];
    }
    if (a == b) {
        return dp[a][b] = 0;
    }
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int l = lca(a, b);
    long long &cur = dp[a][b];
    int d = dist(a, b);
    if (l == b) {
        int node = jmp(a, d - 1);
        cur = max(cur, gen(up[a][0], b) + sub[a] * (n - sub[node]));
        cur = max(cur, gen(a, node) + sub[a] * (n - sub[node]));
    } else {
        cur = max(cur, gen(up[a][0], b) + sub[a] * sub[b]);
        cur = max(cur, gen(a, up[b][0]) + sub[a] * sub[b]);
    }
    return cur;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    dfs1(0, -1);
    build();
    for (int i = 0; i < n; ++i) {
        up_cnt[i] = n - sub[i] + 1;
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sol = max(sol, gen(i, j));
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("2");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
