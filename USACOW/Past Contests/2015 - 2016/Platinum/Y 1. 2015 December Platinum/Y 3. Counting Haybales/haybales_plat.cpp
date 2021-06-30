/*
ID: izhang01
TASK: haybales
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    freopen("haybales.out", "w", stderr);
}
//#define DEBUG

const long long inf = 1e18, mod = 1e9 + 7;

struct segtree {
    int size{};
    vector<long long> mn, sum, lz_add;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        mn.resize(2 * size);
        sum.resize(2 * size);
        lz_add.resize(2 * size);
    }

    void pushup(int x) {
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        mn[x] = min(mn[2 * x + 1], mn[2 * x + 2]);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        int m = (lx + rx) / 2;
        if (lz_add[x] != 0) {
            lz_add[2 * x + 1] += lz_add[x];
            lz_add[2 * x + 2] += lz_add[x];

            sum[2 * x + 1] += (m - lx) * lz_add[x];
            sum[2 * x + 2] += (rx - m) * lz_add[x];
            mn[2 * x + 1] += lz_add[x];
            mn[2 * x + 2] += lz_add[x];
            lz_add[x] = 0;
        }
    }

    void add(int l, int r, long long v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            sum[x] += (rx - lx) * v;
            mn[x] += v;
            lz_add[x] += v;
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

    long long get_sum(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return sum[x];
        }
        int m = (lx + rx) / 2;
        return get_sum(l, r, 2 * x + 1, lx, m) + get_sum(l, r, 2 * x + 2, m, rx);
    }

    long long get_sum(int l, int r) {
        return get_sum(l, r, 0, 0, size);
    }

    long long get_mn(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return inf;
        }
        if (lx >= l && rx <= r) {
            return mn[x];
        }
        int m = (lx + rx) / 2;
        return min(get_mn(l, r, 2 * x + 1, lx, m), get_mn(l, r, 2 * x + 2, m, rx));
    }

    long long get_mn(int l, int r) {
        return get_mn(l, r, 0, 0, size);
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
        seg.add(i, i + 1, a);
    }
    while (q--) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        --a, --b;
        if (t == 'M') {
            cout << seg.get_mn(a, b + 1) << "\n";
        } else if (t == 'P') {
            int x;
            cin >> x;
            seg.add(a, b + 1, x);
        } else if (t == 'S') {
            cout << seg.get_sum(a, b + 1) << "\n";
        }
    }
    return 0;
}
