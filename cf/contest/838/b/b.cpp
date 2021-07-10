/* Author: izhang05
 * Time: 07-10-2021 00:17:11
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
const long long inf = 1e18;
struct item {
    long long lz_add, mn;
};

struct segtree {
    int size{};
    vector<item> t;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    void push(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        long long cur = t[x].lz_add;
        t[2 * x + 1].lz_add += cur;
        t[2 * x + 1].mn += cur;
        t[2 * x + 2].lz_add += cur;
        t[2 * x + 2].mn += cur;
        t[x].lz_add = 0;
    }

    void upd(int l, int r, long long v, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            t[x].lz_add += v;
            t[x].mn += v;
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m);
        upd(l, r, v, 2 * x + 2, m, rx);
        t[x].mn = min(t[2 * x + 1].mn, t[2 * x + 2].mn);
    }

    void upd(int l, int r, long long v) {
        upd(l, r, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) {
            return inf;
        }
        if (lx >= l && rx <= r) {
            return t[x].mn;
        }
        int m = (lx + rx) / 2;
        return min(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    long long query(int p) {
        return query(p, p + 1, 0, 0, size);
    }
};

const int mod = 1e9 + 7, maxn = 2e5 + 5;
vector<pair<int, int>> adj[maxn];
int tin[maxn], tout[maxn], t = 0, depth[maxn];
long long dist[maxn], up_w[maxn];
struct edge {
    int a, b, w;
};
edge edges[2 * maxn];

void dfs(int c, int p, int w, int d) {
    tin[c] = t++;
    depth[c] = d;
    dist[c] = w;
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs(i.first, c, w + i.second, d + 1);
        }
    }
    tout[c] = t;
}

int main() {
    setIO("1");
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        --edges[i].a, --edges[i].b;
        adj[edges[i].a].emplace_back(edges[i].b, edges[i].w);
        adj[edges[i].b].emplace_back(edges[i].a, edges[i].w);
    }
    for (int i = n - 1; i < 2 * n - 2; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        --edges[i].a, --edges[i].b;
        if (edges[i].b == 0) {
            swap(edges[i].a, edges[i].b);
        }
        up_w[edges[i].b] = edges[i].w;
    }
    dfs(0, -1, 0, 0);
    for (int i = 0; i < n - 1; ++i) {
        if (depth[edges[i].a] > depth[edges[i].b]) {
            swap(edges[i].a, edges[i].b);
        }
    }
    segtree down, up;
    down.init(n), up.init(n);
    for (int i = 0; i < n; ++i) {
        down.upd(tin[i], tin[i] + 1, dist[i]);
        up.upd(tin[i], tin[i] + 1, dist[i] + up_w[i]);
#ifdef DEBUG
        cout << i << " " << dist[i] << " " << down.query(tin[i]) << "\n";
#endif
    }
    while (q--) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int i, w;
            cin >> i >> w;
            --i;
            if (i < n - 1) {
                down.upd(tin[edges[i].b], tout[edges[i].b], w - edges[i].w);
#ifdef DEBUG
                cout << "update: " << edges[i].b << " " << w - edges[i].w << " " << down.query(tin[edges[i].b]) << "\n";
#endif
                up.upd(tin[edges[i].b], tout[edges[i].b], w - edges[i].w);
            } else {
                up.upd(tin[edges[i].b], tin[edges[i].b] + 1, w - edges[i].w);
            }
            edges[i].w = w;
        } else {
            int u, v;
            cin >> u >> v;
            --u, --v;
            if (tin[v] >= tin[u] && tout[v] <= tout[u]) {
                // u is ancestor of v
#ifdef DEBUG
                cout << down.query(tin[v]) << " " << down.query(tin[u]) << "\n";
#endif
                cout << down.query(tin[v]) - down.query(tin[u]) << "\n";
            } else {
                // u is not ancestor of v
#ifdef DEBUG
                cout << up.query(tin[u], tout[u]) << " " << down.query(tin[u]) << " " << down.query(tin[v]) << "\n";
#endif
                cout << up.query(tin[u], tout[u]) - down.query(tin[u]) + down.query(tin[v]) << "\n";
            }
        }
    }
    return 0;
}
