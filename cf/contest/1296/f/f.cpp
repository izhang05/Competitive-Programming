/* Author: izhang05
 * Time: 06-28-2021 18:01:08
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e3 + 5, maxs = 20;

int val[maxn];

struct q {
    int a, b, g;
};
vector<pair<int, int>> adj[maxn];

int up[maxn][maxs], depth[maxn], n;
pair<int, int> par[maxn];

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
    for (pair<int, int> i : adj[c]) {
        if (i.first != p) {
            par[i.first] = {c, i.second};
            dfs(i.first, c, d + 1);
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

int main() {
    setIO("1");
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
        val[i] = 1;
    }
    dfs();
    build();
    int m;
    cin >> m;
    vector<q> pass(m);
    for (int i = 0; i < m; ++i) {
        cin >> pass[i].a >> pass[i].b >> pass[i].g;
        --pass[i].a, --pass[i].b;
        int a = pass[i].a, b = pass[i].b, l = lca(a, b);
        while (a != l) {
            val[par[a].second] = max(val[par[a].second], pass[i].g);
            a = par[a].first;
        }
        while (b != l) {
            val[par[b].second] = max(val[par[b].second], pass[i].g);
            b = par[b].first;
        }
    }
    for (auto &i : pass) {
        int l = lca(i.a, i.b);
        bool good = false;
        while (i.a != l && !good) {
            if (val[par[i.a].second] == i.g) {
                good = true;
            }
            i.a = par[i.a].first;
        }
        while (i.b != l && !good) {
            if (val[par[i.b].second] == i.g) {
                good = true;
            }
            i.b = par[i.b].first;
        }
        if (!good) {
            cout << -1 << "\n";
            return 0;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << val[i] << " \n"[i == n - 1];
    }
    return 0;
}
