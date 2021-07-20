/* Author: izhang05
 * Time: 07-19-2021 21:40:37
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxs = 20;
int t, tin[maxn], tout[maxn], up[maxn][maxs], depth[maxn], n;
vector<int> adj[maxn];

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x;
}

int lca(int x, int y) {
#ifdef DEBUG
    cout << x << " " << y << endl;
#endif
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
    tin[c] = t++;
    up[c][0] = p;
    depth[c] = d;
    for (int i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
    tout[c] = t;
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

struct item {
    int mn, mx, mn_ind, mx_ind;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {inf, -inf, inf, inf};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        item res{min(a.mn, b.mn), max(a.mx, b.mx)};
        if (a.mn < b.mn) {
            res.mn_ind = a.mn_ind;
        } else {
            res.mn_ind = b.mn_ind;
        }
        if (a.mx > b.mx) {
            res.mx_ind = a.mx_ind;
        } else {
            res.mx_ind = b.mx_ind;
        }
        return res;
    }

    static item single(int p, int v) {
        return {v, v, p, p};
    }

    void upd(int p, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(p, v);
            return;
        }
        int m = (lx + rx) / 2;
        if (p < m) {
            upd(p, v, 2 * x + 1, lx, m);
        } else {
            upd(p, v, 2 * x + 2, m, rx);
        }
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    void upd(int p, int v) {
        upd(p, v, 0, 0, size);
    }

    item query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return neutral;
        }
        if (lx >= l && rx <= r) {
            return t[x];
        }
        int m = (lx + rx) / 2;

        return merge(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    item query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};
segtree seg;

int int_lca(int l, int r) {
#ifdef DEBUG
    cout << "l: " << l << " r: " << r << "\n";
#endif
    int u = seg.query(l, r + 1).mn_ind, v = seg.query(l, r + 1).mx_ind;
    return lca(u, v);
}

int solve(int l, int u, int r) {
    if (u > l) {
        if (u < r) {
            return lca(int_lca(l, u - 1), int_lca(u + 1, r));
        } else {
            return int_lca(l, u - 1);
        }
    } else {
        return int_lca(u + 1, r);
    }
}

int main() {
    setIO("2");

    int q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    dfs();
    build();
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        seg.upd(i, tin[i]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int u = seg.query(l, r + 1).mn_ind, v = seg.query(l, r + 1).mx_ind;
#ifdef DEBUG
        cout << "u: " << u << " v: " << v << "\n";
#endif
        pair<int, int> sol{depth[solve(l, u, r)], u};
        sol = max(sol, {depth[solve(l, v, r)], v});
        cout << sol.second + 1 << " " << sol.first << "\n";
    }
    return 0;
}
