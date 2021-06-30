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
    vector<long long> val, lz_add, lz_set;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        val.resize(2 * size);
        lz_add.resize(2 * size);
        lz_set.resize(2 * size);
    }

    void pushup(int x) {
        val[x] = val[2 * x + 1] + val[2 * x + 2];
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        int m = (lx + rx) / 2;
        if (lz_set[x] != 0) {
            // range set
            lz_set[2 * x + 1] = lz_set[2 * x + 2] = lz_set[x];
            val[2 * x + 1] = (m - lx) * lz_set[x];
            val[2 * x + 2] = (rx - m) * lz_set[x];
            lz_add[2 * x + 1] = lz_add[2 * x + 2] = 0;
            lz_set[x] = 0;
        } else if (lz_add[x] != 0) {
            // range add
            if (lz_set[2 * x + 1] == 0) {
                lz_add[2 * x + 1] += lz_add[x];
            } else {
                lz_set[2 * x + 1] += lz_add[x];
                assert(lz_add[2 * x + 1] == 0);
                lz_add[2 * x + 1] = 0;
            }
            if (lz_set[2 * x + 2] == 0) {
                lz_add[2 * x + 2] += lz_add[x];
            } else {
                lz_set[2 * x + 2] += lz_add[x];
                assert(lz_add[2 * x + 2] == 0);
                lz_add[2 * x + 2] = 0;
            }
            val[2 * x + 1] += (m - lx) * lz_add[x];
            val[2 * x + 2] += (rx - m) * lz_add[x];
            lz_add[x] = 0;
        }
    }

    void add(int l, int r, long long v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            val[x] += (rx - lx) * v;
            if (lz_set[x] == 0) {
                lz_add[x] += v;
            } else {
                lz_set[x] += v;
            }
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m), add(l, r, v, 2 * x + 2, m, rx);
        pushup(x);
    }

    void add(int l, int r, long long v) {
        add(l, r, v, 0, 0, size);
    }

    void set(int l, int r, long long v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            val[x] = (rx - lx) * v;
            lz_add[x] = 0;
            lz_set[x] = v;
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        set(l, r, v, 2 * x + 1, lx, m), set(l, r, v, 2 * x + 2, m, rx);
        pushup(x);
    }

    void set(int l, int r, long long v) {
        set(l, r, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return val[x];
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m, rx);
    }

    long long query(int l, int r) {
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
        seg.set(i, i + 1, a);
    }
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        --a, --b;
        if (t == 1) {
            int x;
            cin >> x;
            seg.add(a, b + 1, x);
        } else if (t == 2) {
            int x;
            cin >> x;
            seg.set(a, b + 1, x);
        } else if (t == 3) {
            cout << seg.query(a, b + 1) << "\n";
        }
    }
    return 0;
}
