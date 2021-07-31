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

const int maxn = 2e5 + 5;

int n, q, v[maxn];
vector<int> adj[maxn];

int sz[maxn], par[maxn], dep[maxn], st[maxn], tp[maxn], t = 1, out[maxn];

struct item {
    long long mx;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {max(a.mx, b.mx)};
    }

    static item single(int v) {
        return {v};
    }

    void upd(int p, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(v);
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

    int query(int l, int r) {
        return query(l, r, 0, 0, size).mx;
    }
};

segtree seg;
void dfs_sz(int c = 0, int p = 0, int d = 0) {
    sz[c] = 1;
    par[c] = p;
    dep[c] = d;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs_sz(i, c, d + 1);
            sz[c] += sz[i];
            if (sz[i] > sz[adj[c][0]]) {
                swap(i, adj[c][0]);
            }
        }
    }
}

void dfs_hld(int c = 0, int p = 0) {
    st[c] = t++;
    seg.upd(st[c], v[c]);
    for (auto i : adj[c]) {
        if (i != p) {
            tp[i] = (i == adj[c][0] ? tp[c] : i);
            dfs_hld(i, c);
        }
    }
    out[c] = t;
}

int path(int x, int y) {
    int ret = 0;
    while (tp[x] != tp[y]) {
        if (dep[tp[x]] < dep[tp[y]]) {
            swap(x, y);
        }
        ret = max(ret, seg.query(st[tp[x]], st[x] + 1));
        x = par[tp[x]];
    }
    if (dep[x] > dep[y]) {
        swap(x, y);
    }
    ret = max(ret, seg.query(st[x], st[y] + 1));
    return ret;
}

int main() {
    setIO("12");
    cin >> n >> q;
    seg.init(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_sz();
    dfs_hld();
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            --s;
            v[s] = x;
            seg.upd(st[s], v[s]);
        } else {
            int a, b;
            cin >> a >> b;
            --a, --b;
            cout << path(a, b) << " ";
        }
    }
    cout << "\n";
}
