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

int n;
struct item {
    int mx;
};

struct segtree {
    int size{};
    vector<item> t;

    void init(int s) {
        size = 1;
        while (size < s) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {max(a.mx, b.mx)};
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

    int query(int x, int lx, int rx, int k, int l) {
        if (rx - lx == 1) {
            return t[x].mx >= k ? lx : -1;
        }
        int m = (lx + rx) / 2;
        item lv = t[2 * x + 1];
        if (lv.mx >= k && m > l) {
            int cur = query(2 * x + 1, lx, m, k, l);
            if (cur != -1) {
                return cur;
            }
        }
        return query(2 * x + 2, m, rx, k, l);
    }

    int query(int k, int l) {
        return query(0, 0, size, k, l);
    }
};

int main() {
    setIO("D");
    int q;
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
            int p, v;
            cin >> p >> v;
            seg.upd(p, v);
        } else if (t == 2) {
            int k, l;
            cin >> k >> l;
            cout << seg.query(k, l) << "\n";
        }
    }
    return 0;
}
