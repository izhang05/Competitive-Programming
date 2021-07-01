/* Author: izhang05
 * Time: 06-30-2021 21:39:40
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

struct item {
    long long num0, num1, inc, dec, lz;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral{0, 0, 0, 0, 0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
        build(0, 0, size);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        if (t[x].lz) {
            t[2 * x + 1].lz ^= 1;
            t[2 * x + 2].lz ^= 1;
            swap(t[2 * x + 1].num0, t[2 * x + 1].num1);
            swap(t[2 * x + 1].inc, t[2 * x + 1].dec);

            swap(t[2 * x + 2].num0, t[2 * x + 2].num1);
            swap(t[2 * x + 2].inc, t[2 * x + 2].dec);
            t[x].lz = 0;
        }
    }

    void build(int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x].num0 = 1;
            t[x].inc = 1;
            t[x].dec = 1;
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m), build(2 * x + 2, m, rx);
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    item merge(item x, item y) {
        item res{};
        res.num0 = x.num0 + y.num0;
        res.num1 = x.num1 + y.num1;
        res.inc = max({x.inc + y.num1, x.num0 + y.num1, x.num0 + y.inc});
        res.dec = max({x.dec + y.num0, x.num1 + y.num0, x.num1 + y.dec});
        return res;
    }

    void upd(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            t[x].lz ^= 1;
            if (r - l == 1) {
            }
            swap(t[x].num0, t[x].num1);
            swap(t[x].inc, t[x].dec);
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, 2 * x + 1, lx, m), upd(l, r, 2 * x + 2, m, rx);
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    void upd(int l, int r) {
        upd(l, r, 0, 0, size);
    }

    item query(int l, int r, int x, int lx, int rx) {
#ifdef DEBUG
        cout << l << " " << r << " " << x << " " << lx << " " << rx << "\n";
#endif
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return neutral;
        }
        if (lx >= l && rx <= r) {
            return t[x];
        }
        int m = (lx + rx) / 2;
        return merge(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size).inc;
    }
};

int main() {
    setIO("3");

    int n, m;
    cin >> n >> m;
    segtree seg;
    seg.init(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '7') {
            seg.upd(i, i + 1);
        }
    }

    while (m--) {
        string t;
        cin >> t;
        if (t == "count") {
            cout << seg.query(0, n) << "\n";
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            seg.upd(l, r + 1);
        }
    }
    return 0;
}
