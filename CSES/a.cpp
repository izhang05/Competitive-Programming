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

const int inf = 0x3f3f3f3f, mod = 998244353;

struct item {
    pair<long long, long long> func;

    long long eval(long long x) {
        return (func.first * x + func.second) % mod;
    }
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {{1, 0}};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {{(b.func.first * a.func.first) % mod, (b.func.first * a.func.second + b.func.second) % mod}};
    }

    static item single(item v) {
        return v;
    }

    void upd(int p, item v, int x, int lx, int rx) {
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

    void upd(int p, pair<long long, long long> v) {
        upd(p, item{v}, 0, 0, size);
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
    setIO("1");

    int n, q;
    cin >> n >> q;
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        seg.upd(i, {a, b});
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            seg.upd(p, {c, d});
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            cout << seg.query(l, r).eval(x) << "\n";
        }
    }
    return 0;
}
