/* Author: izhang05
 * Time: 06-30-2021 20:22:46
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int maxn = 2e5 + 5;
const long long inf = 1e18;

struct segtree {
    int size{};
    vector<long long> lz_add, mn;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        lz_add.resize(2 * size);
        mn.resize(2 * size);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        lz_add[2 * x + 1] += lz_add[x];
        lz_add[2 * x + 2] += lz_add[x];
        mn[2 * x + 1] += lz_add[x];
        mn[2 * x + 2] += lz_add[x];
        lz_add[x] = 0;
    }

    void upd(int l, int r, long long v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            lz_add[x] += v;
            mn[x] += v;
            return;
        }
        int m = (lx + rx) / 2;

        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);
        mn[x] = min(mn[2 * x + 1], mn[2 * x + 2]);
    }

    void upd(int l, int r, long long v) {
        upd(l, r, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return inf;
        }
        if (lx >= l && rx <= r) {
            return mn[x];
        }
        int m = (lx + rx) / 2;
        return min(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    setIO("2");

    int n;
    cin >> n;
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        seg.upd(i, i + 1, a);
    }
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (cin.peek() == '\n') {
            if (l <= r) {
                cout << seg.query(l, r + 1) << "\n";
            } else {
                cout << min(seg.query(l, n), seg.query(0, r + 1)) << "\n";
            }
        } else {
            int v;
            cin >> v;
            if (l <= r) {
                seg.upd(l, r + 1, v);
            } else {
                seg.upd(l, n, v);
                seg.upd(0, r + 1, v);
            }
        }
    }
    return 0;
}
