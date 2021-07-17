/* Author: izhang05
 * Time: 07-17-2021 17:54:43
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}
struct item {
    long long mx, sum;
};

struct segtree {
    int size{};
    vector<item> t;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    void mod(int l, int r, long long v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            if (t[x].mx < v) {
                return;
            }
        }
        if (rx - lx == 1) {
            t[x].sum %= v;
            t[x].mx %= v;
            return;
        }
        int m = (lx + rx) / 2;
        mod(l, r, v, 2 * x + 1, lx, m);
        mod(l, r, v, 2 * x + 2, m, rx);
        t[x].mx = max(t[2 * x + 1].mx, t[2 * x + 2].mx);
        t[x].sum = t[2 * x + 1].sum + t[2 * x + 2].sum;
    }

    void mod(int l, int r, long long v) {
        mod(l, r, v, 0, 0, size);
    }

    void set(int p, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x].sum = v;
            t[x].mx = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (p < m) {
            set(p, v, 2 * x + 1, lx, m);
        } else {
            set(p, v, 2 * x + 2, m, rx);
        }
        t[x].mx = max(t[2 * x + 1].mx, t[2 * x + 2].mx);
        t[x].sum = t[2 * x + 1].sum + t[2 * x + 2].sum;
    }

    void set(int p, int v) {
        set(p, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return t[x].sum;
        }
        int m = (lx + rx) / 2;

        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    setIO("");
    int n, m;
    cin >> n >> m;
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        seg.set(i, a);
    }
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << seg.sum(l, r + 1) << "\n";
        } else if (t == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            seg.mod(l, r + 1, x);
        } else {
            int k, x;
            cin >> k >> x;
            --k;
            seg.set(k, x);
        }
    }
    return 0;
}
