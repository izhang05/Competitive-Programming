/* Author: izhang05
 * Time: 07-06-2021 19:44:36
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
struct item {
    long long mx, lz;
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

    void push(int x, int lx, int rx) {
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
        push(x, lx, rx);
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
#ifdef DEBUG
            cout << x << " " << lx << " " << rx << " " << t[x].lz << " " << t[x].mx << " " << v << "\n";
#endif
            t[x].lz += v;
            t[x].mx += v;
#ifdef DEBUG
            cout << x << " " << lx << " " << rx << " " << t[x].lz << " " << t[x].mx << " " << v << "\n\n";
#endif
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m);
        upd(l, r, v, 2 * x + 2, m, rx);
        t[x].mx = max(t[2 * x + 1].mx, t[2 * x + 2].mx);
    }

    void upd(int p, int v) {
        upd(0, p + 1, v, 0, 0, size);
    }

    int query(int x, int lx, int rx) {
        push(x, lx, rx);
        if (rx - lx == 1) {
            return lx;
        }
        int m = (lx + rx) / 2;
#ifdef DEBUG
        cout << 2 * x + 2 << " " << m << " " << rx << " " << t[2 * x + 2].mx << "\n";
#endif
        if (t[2 * x + 2].mx > 0) {
            return query(2 * x + 2, m, rx);
        } else {
            return query(2 * x + 1, lx, m);
        }
    }

    int query() {
        int res = query(0, 0, size);
        return res == 0 ? -1 : res;
    }
};

int main() {
    setIO("2");

    int n, m;
    cin >> n >> m;
    segtree seg;
    seg.init(maxn);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        seg.upd(a[i], 1);
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        seg.upd(b[i], -1);
    }
    int q;
    cin >> q;
    while (q--) {
        int t, i, x;
        cin >> t >> i >> x;
        --i;
        if (t == 1) {
            seg.upd(a[i], -1);
            seg.upd(x, 1);
            a[i] = x;
        } else {
            seg.upd(b[i], 1);
            seg.upd(x, -1);
            b[i] = x;
        }
        cout << seg.query() << "\n";
    }
    return 0;
}
