/* Author: izhang05
 * Time: 08-03-2021 22:17:29
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 3, maxs = 20;
vector<int> adj[maxn];
long long sz[maxn], sum[maxn], depth[maxn], up_sum[maxn], up_sz[maxn];

int up[maxn][maxs], n;

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

void dfs(int c, int p, int d) {
    up[c][0] = p;
    sz[c] = 1;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
            sz[c] += sz[i];
            sum[c] += sum[i] + sz[i];
        }
    }
}

void dfs2(int c, int p) {
    up_sz[c] = 1;
    if (p != -1) {
        up_sz[c] += sz[p] - sz[c] + up_sz[p] - 1;
        up_sum[c] = up_sum[p] + up_sz[p] + sum[p] - (sum[c] + sz[c]) + sz[p] - sz[c] - 1;
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
        }
    }
}

int main() {
    setIO("1");
    int m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, 0);
    build();
    dfs2(0, -1);
    cout << fixed << setprecision(16);
    while (m--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (depth[a] > depth[b]) {
            swap(a, b);
        }
        int l = lca(a, b);
        long double num, denom;
        if (l != a) {
            //            cout << a << " " << b << " " << sz[a] << " " << sz[b] << " " << sum[a] << " " << sum[b] << "\n";
            denom = sz[a] * sz[b], num = sum[a] * sz[b] + sz[a] * sum[b];
        } else {
            int pre = jmp(b, dist(a, b) - 1);
            long long total_sz = up_sz[a] + sz[a] - 1 - sz[pre], total_sum = up_sum[a] + sum[a] - (sum[pre] + sz[pre]);
            //            cout << a << " " << b << " " << total_sz << " " << sz[b] << " " << total_sum << " " << sum[b] << "\n";
            denom = sz[b] * (total_sz), num = sum[b] * total_sz + sz[b] * total_sum;
        }
        cout << (num / denom) + dist(a, b) + 1 << "\n";
    }
    return 0;
}
