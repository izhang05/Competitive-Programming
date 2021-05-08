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

struct segtree {
    int size{};
    long long neutral = -1;
    vector<long long> t;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }


    long long merge(long long a, long long b) {
        if (b == neutral) {
            return a;
        }
        return b;
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        t[2 * x + 1] = merge(t[2 * x + 1], t[x]);
        t[2 * x + 2] = merge(t[2 * x + 2], t[x]);
        t[x] = neutral;
    }

    void upd(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            t[x] = merge(t[x], v);
            return;
        }
        int m = (lx + rx) / 2;

        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);
    }

    void upd(int l, int r, int v) {
        upd(l, r, v, 0, 0, size);
    }

    long long query(int p, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (rx - lx == 1) {
            return t[x];
        }
        int m = (lx + rx) / 2;
        if (p < m) {
            return query(p, 2 * x + 1, lx, m);
        } else {
            return query(p, 2 * x + 2, m, rx);
        }
    }

    long long query(int p) {
        return query(p, 0, 0, size);
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
            seg.upd(l, r, x);
        } else {
            int p;
            cin >> p;
            cout << seg.query(p) << "\n";
        }
    }
    return 0;
}
