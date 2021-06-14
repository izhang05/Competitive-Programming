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
const int mod = 1e9 + 7;
const long long inf = 1e18;

struct item {
    long long op, values;
};

struct segtree {
    int size{};
    vector<item> t;
    long long no_op = inf, neutral = inf;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    long long modify_op(long long a, long long b, long long len) {
        if (b == no_op) {
            return a;
        }
        return b;
    }

    long long calc_op(long long a, long long b) {
        return min(a, b);
    }

    void apply_mod_op(long long &a, long long b, long long len) {
        a = modify_op(a, b, len);
    }

    void prop(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        int m = (lx + rx) / 2;
        prop(2 * x + 1, lx, m);
        prop(2 * x + 2, m, rx);
    }

    void modify(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            apply_mod_op(t[x].op, v, 1);
            apply_mod_op(t[x].values, v, rx - lx);
            return;
        }
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m), modify(l, r, v, 2 * x + 2, m, rx);
        t[x].values = modify_op(calc_op(t[2 * x + 1].values, t[2 * x + 2].values), t[x].op, rx - lx);
    }

    void modify(int l, int r, int v) {
        modify(l, r, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return neutral;
        }
        if (lx >= l && rx <= r) {
            return t[x].values;
        }
        int m = (lx + rx) / 2;
        return modify_op(calc_op(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx)), t[x].op, min(rx, r) - max(lx, l));
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};


int main() {
    setIO("1");
    int n, q;
    cin >> n >> q;
    segtree seg;
    seg.init(n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            seg.modify(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r) << "\n";
        }
    }
    return 0;
}
