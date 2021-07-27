/* Author: izhang05
 * Time: 07-27-2021 00:37:13
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
const int mod = 1e9 + 7, maxn = 5e5 + 5;
const long long inf = 1e18;
struct item {
    long long lz_add, mn;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {0, inf};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    void apply_push(int x, long long v) {
        t[x].lz_add += v;
        t[x].mn += v;
    }

    void push(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        apply_push(2 * x + 1, t[x].lz_add);
        apply_push(2 * x + 2, t[x].lz_add);
        t[x].lz_add = 0;
    }

    void upd(int l, int r, long long v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            apply_push(x, v);
            return;
        }
        push(x, lx, rx);
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);
        t[x].mn = min(t[2 * x + 1].mn, t[2 * x + 2].mn);
    }

    void upd(int l, int r, long long v) {
        upd(l, r, v, 0, 0, size);
    }

    void upd(int p, long long v) {
        upd(p, p + 1, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return inf;
        }
        if (lx >= l && rx <= r) {
            return t[x].mn;
        }
        push(x, lx, rx);
        int m = (lx + rx) / 2;
        return min(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};
vector<pair<int, int>> adj[maxn];
long long sol[maxn];
int tout[maxn], t, n;
struct query {
    int l, r, ind;
};
vector<query> queries[maxn];
segtree seg;

void dfs1(int c, int p, long long d) {
    bool leaf = true;
    ++t;
    for (auto &i : adj[c]) {
        if (i.first != p) {
            leaf = false;
            dfs1(i.first, c, d + i.second);
        }
    }
    tout[c] = t;
    if (leaf) {
        seg.upd(c, d);
    } else {
        seg.upd(c, inf);
    }
}

void dfs2(int c, int p) {
#ifdef DEBUG
    cout << c << " " << seg.query(0, 2) << "\n";
#endif
    for (auto &i : queries[c]) {
        sol[i.ind] = seg.query(i.l, i.r);
    }
    for (auto &i : adj[c]) {
        if (i.first != p) {
            seg.upd(i.first, tout[i.first], -i.second);
            seg.upd(0, i.first, i.second);
            seg.upd(tout[i.first], n, i.second);
            dfs2(i.first, c);
            seg.upd(i.first, tout[i.first], i.second);
            seg.upd(0, i.first, -i.second);
            seg.upd(tout[i.first], n, -i.second);
        }
    }
}

int main() {
    setIO("1");
    int q;
    cin >> n >> q;
    seg.init(n);
    for (int i = 1; i < n; ++i) {
        int a, w;
        cin >> a >> w;
        --a;
        adj[i].emplace_back(a, w);
        adj[a].emplace_back(i, w);
    }
    for (int i = 0; i < q; ++i) {
        int v, l, r;
        cin >> v >> l >> r;
        --v, --l;
        queries[v].push_back({l, r, i});
    }
    dfs1(0, -1, 0);
    dfs2(0, -1);
    for (int i = 0; i < q; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
