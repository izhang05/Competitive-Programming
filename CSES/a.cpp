/* Author: izhang05
 * Time: 06-29-2021 14:33:25
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}
const int maxn = 2e5 + 5;

struct segtree {
    int size{};
    long long neutral = 0, no_op = LLONG_MAX - 1;
    vector<long long> operations, values;

    long long modify_op(long long a, long long b, long long len) {
        if (b == no_op) {
            return a;
        }
        return b * len;
    }

    long long calc_op(long long a, long long b) {
        return a + b;
    }

    void apply_mod_op(long long &a, long long b, long long len) {
        a = modify_op(a, b, len);
    }

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        operations.resize(2 * size);
        values.resize(2 * size);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        int m = (lx + rx) / 2;
        apply_mod_op(operations[2 * x + 1], operations[x], 1);
        apply_mod_op(values[2 * x + 1], operations[x], m - lx);
        apply_mod_op(operations[2 * x + 2], operations[x], 1);
        apply_mod_op(values[2 * x + 2], operations[x], rx - m);
        operations[x] = no_op;
    }

    void upd(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            apply_mod_op(operations[x], v, 1);
            apply_mod_op(values[x], v, rx - lx);
            return;
        }
        int m = (lx + rx) / 2;

        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);
        values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
    }

    void upd(int l, int r, int v) {
        upd(l, r, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return neutral;
        }
        if (lx >= l && rx <= r) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        long long m1 = query(l, r, 2 * x + 1, lx, m), m2 = query(l, r, 2 * x + 2, m, rx);
        return calc_op(m1, m2);
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    segtree seg;
    seg.init(n);
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            seg.upd(l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r) << "\n";
        }
    }
    return 0;
}
