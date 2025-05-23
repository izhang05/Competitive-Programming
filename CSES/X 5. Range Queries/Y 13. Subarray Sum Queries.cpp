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
    long long sum, seg, pre, suf;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {0, 0, 0, 0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {
                a.sum + b.sum,
                max({a.seg, b.seg, a.suf + b.pre}),
                max(a.pre, a.sum + b.pre),
                max(b.suf, b.sum + a.suf)
        };
    }

    static item single(int v) {
        return {v, max(0, v), max(0, v), max(0, v)};
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

    item query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    setIO("13");
    int n, q;
    cin >> n >> q;
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        seg.upd(i, a);
    }
    while (q--) {
        int p, v;
        cin >> p >> v;
        --p;
        seg.upd(p, v);
        cout << seg.query(0, n).seg << "\n";
    }
    return 0;
}
