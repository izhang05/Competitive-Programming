#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("3.in", "r", stdin);
    freopen("3.out", "w", stdout);
#endif
}

//#define DEBUG

struct segtree {
    int size{};
    vector<long long> t;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    void upd(int p, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (p < m) {
            upd(p, v, 2 * x + 1, lx, m);
        } else {
            upd(p, v, 2 * x + 2, m, rx);
        }
        t[x] = t[2 * x + 1] + t[2 * x + 2];
    }

    void upd(int p, int v) {
        upd(p, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return t[x];
        }
        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m, rx);
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    setIO();
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
        int t;
        cin >> t;
        if (t == 1) {
            int p, v;
            cin >> p >> v;
            --p;
            seg.upd(p, v);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            --l;
            cout << seg.query(l, r) << "\n";
        }
    }
    return 0;
}
