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

//#define DEBUG

struct item {
    int sum;
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
        return {a.sum + b.sum};
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

    int query(int x, int lx, int rx, int k, int cur) {
        if (rx - lx == 1) {
            return lx;
        }
        int m = (lx + rx) / 2;
        item lv = t[2 * x + 1];
        if (cur + lv.sum >= k) {
            return query(2 * x + 1, lx, m, k, cur);
        } else {
            return query(2 * x + 2, m, rx, k, cur + lv.sum);
        }
    }

    int query(int k) {
        return query(0, 0, size, k, 0);
    }
};

int main() {
    setIO("B");
    int n, q;
    cin >> n >> q;
    segtree seg;
    seg.init(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        seg.upd(i, a[i]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p;
            seg.upd(p, a[p] ^ 1);
            a[p] ^= 1;
        } else if (t == 2) {
            int k;
            cin >> k;
            cout << seg.query(k + 1) << "\n";
        }
    }
    return 0;
}
