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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

struct item {
    long long sum, assign;
};

struct segtree {
    int size{};
    item neutral = {0, -1};
    vector<item> t;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }


    item merge(item a, item b) {
        if (b.assign == neutral.assign) {
            return {a.sum + b.sum, neutral.assign};
        }
        return {b.assign, b.assign};
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        t[2 * x + 1] = merge(t[2 * x + 1], t[x]);
        t[2 * x + 2] = merge(t[2 * x + 2], t[x]);
        t[x] = neutral;
    }

    void add(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            t[x] = merge(t[x], {v, -1});
            return;
        }
        int m = (lx + rx) / 2;

        add(l, r, v, 2 * x + 1, lx, m), add(l, r, v, 2 * x + 2, m, rx);
    }

    void add(int l, int r, int v) {
        add(l, r, v, 0, 0, size);
    }

    void assign(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            t[x] = merge(t[x], {0, v});
            return;
        }
        int m = (lx + rx) / 2;

        assign(l, r, v, 2 * x + 1, lx, m), assign(l, r, v, 2 * x + 2, m, rx);
    }

    void assign(int l, int r, int v) {
        assign(l, r, v, 0, 0, size);
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
};


int main() {
    setIO("17");
    int n, q;
    cin >> n >> q;
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        seg.assign(i, i + 1, a);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            seg.add(l, r + 1, x);
        } else if (t == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            seg.assign(l, r + 1, x);
        } else if (t == 3) {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r + 1).sum << "\n";
        }
    }
    return 0;
}
