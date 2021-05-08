/*
ID: izhang01
TASK: seating
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("seating.in", "r", stdin);
    freopen("seating.out", "w", stdout);
    freopen("seating.out", "w", stderr);
}
//#define DEBUG
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

struct item {
    int seg, sum, pre, suf;
};

struct segtree {
    int size{};
    vector<item> t;
    int sol = 0;

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
                max(b.suf, b.sum + a.suf)};
    }

    static item single(int v) {
        return {v, v, v, v};
    }

    void upd(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (rx - lx == 1) {
            t[x] = single(1);
            return;
        }
        if (lx >= l && rx <= r) {
            t[x] = single(v * (r - l));
        }
        int m = (lx + rx) / 2;

        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    void upd(int l, int r, int v) {
        upd(l, r, v, 0, 0, size);
    }

    void query(int x, int lx, int rx, int k) {
        int m = (lx + rx) / 2;
        if (rx - lx == 1) {
            upd(m - 1, m, 0);
            return;
        }
        item lv = t[2 * x + 1], rv = t[2 * x + 2];
        if (lv.seg >= k) {
            query(2 * x + 1, m, rx, k);
        } else if (lv.suf + rv.pre >= k) {
            upd(m - lv.suf, m - lv.suf + k, 0);
        } else if (rv.seg >= k) {
            query(2 * x + 2, m, rx, k);
        } else {
            ++sol;
        }
    }

    void query(int k) {
        query(0, 0, size, k);
    }
};

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    segtree seg;
    seg.init(n);
    seg.upd(0, n, 1);
    for (int i = 0; i < m; ++i) {
        char t;
        cin >> t;
        if (t == 'A') {
            int k;
            cin >> k;
            seg.query(k);
        } else if (t == 'L') {
            int a, b;
            cin >> a >> b;
            --a, --b;
            seg.upd(a, b + 1, 1);
        }
    }
    cout << seg.sol << "\n";
    return 0;
}
