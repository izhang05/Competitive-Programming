/* Author: izhang05
 * Time: 12-15-2021 09:04:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct item {
    long long ;
};

struct segtree {
    int size{};
    vector<item> t;
    constexpr static item neutral = ;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        if (a == neutral) {
            return b;
        }
        if (b == neutral) {
            return a;
        }
        return ;
    }

    void apply(int x, long long v)  {

    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        apply(2 * x + 1, ), apply(2 * x + 2, );

    }

    void upd(int l, int r, long long v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            apply(x, v);
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);

        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }
    void upd(int l, int r, long long v) {
        upd(l, r, v, 0, 0, size);
    }

    void upd(int p, long long v) {
        upd(p, p + 1, v, 0, 0, size);
    }

    item query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
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

    item query(int p) {
        return query(p, p + 1, 0, 0, size);
    }
};

int par[maxn], depth[maxn], st[maxn], en[maxn], t, sz[maxn], top[maxn];
vector<int> adj[maxn];

segtree seg;

void dfs1(int c = 0, int p = -1, int d = 0) {
    seg.upd(t, -1);
    st[c] = t++;
    depth[c] = d;
    sz[c] = 1;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c, d + 1);
            sz[c] += sz[i];
            if (sz[i] > sz[adj[c][0]]) {
                swap(i, adj[c][0]);
            }
        }
    }
    en[c] = t;
}

void dfs2(int c = 0, int p = -1) {
    for (auto &i : adj[c]) {
        if (i != p) {
            top[i] = i == adj[c][0] ? top[c] : i;
            dfs2(i, c);
        }
    }
}

void test_case() {
    int n, q;
    cin >> n >> q;
    seg.init(n);
    for (int i = 1; i < n; ++i) {
        cin >> par[i];
        --par[i];
        adj[i].push_back(par[i]);
        adj[par[i]].push_back(i);
    }
    while (q--) {
        int t, v;
        cin >> t >> v;
        --v;
        if (t == 1) {
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
