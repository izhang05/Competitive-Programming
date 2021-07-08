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
struct item {
    long long lz, mx;
};

struct segtree {
    int size = 1;
    vector<item> t;
    void init(int n) {
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        t[2 * x + 1].lz += t[x].lz;
        t[2 * x + 1].mx += t[x].lz;
        t[2 * x + 2].lz += t[x].lz;
        t[2 * x + 2].mx += t[x].lz;
        t[x].lz = 0;
    }

    void upd(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            t[x].lz += v;
            t[x].mx += v;
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m);
        upd(l, r, v, 2 * x + 2, m, rx);
        t[x].mx = max(t[2 * x + 1].mx, t[2 * x + 2].mx);
    }

    void upd(int l, int r, int v) {
        upd(l, r, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return t[x].mx;
        }
        int m = (lx + rx) / 2;
        return max(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    setIO("11");
    int n, m;
    cin >> n >> m;
    segtree seg;
    seg.init(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        seg.upd(i, n, a[i]);
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        cout << seg.query(i, i + 1) << " \n"[i == n - 1];
    }
#endif
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, v;
            cin >> p >> v;
            --p;
            seg.upd(p, n, v - a[p]);
            a[p] = v;
#ifdef DEBUG
            for (int i = 0; i < n; ++i) {
                cout << seg.query(i, i + 1) << " \n"[i == n - 1];
            }
#endif
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
#ifdef DEBUG
            cout << seg.query(l, r + 1) << " " << seg.query(l - 1, l) << "\n";
#endif

            cout << max(0ll, seg.query(l, r + 1) - seg.query(max(0, l - 1), l)) << "\n";
        }
    }
    return 0;
}
