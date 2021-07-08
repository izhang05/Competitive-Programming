/* Author: izhang05
 * Time: 07-08-2021 14:15:02
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
const long long inf = 1e18;

struct item {
    long long sol;
    array<long long, 10> mn;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {inf, array<long long, 10>()};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
        for (int i = 0; i < 10; ++i) {
            neutral.mn[i] = inf;
        }
    }

    static item merge(item a, item b) {
        item res{};
        res.sol = min(a.sol, b.sol);
        for (int i = 0; i < 10; ++i) {
            res.mn[i] = min(a.mn[i], b.mn[i]);
            res.sol = min(res.sol, a.mn[i] + b.mn[i]);
        }
        return res;
    }

    static item single(int v) {
        item res{};
        int orig = v;
        for (int i = 0; i < 10; ++i) {
            if (v % 10) {
                res.mn[i] = orig;
            } else {
                res.mn[i] = inf;
            }
            v /= 10;
        }
        res.sol = inf;
        return res;
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
#ifdef DEBUG
        cout << x << " " << lx << " " << rx << " " << t[x].sol << "\n";
#endif
    }

    void upd(int p, int v) {
        upd(p, v, 0, 0, size);
    }

    item query(int l, int r, int x, int lx, int rx) {
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
        long long res = query(l, r, 0, 0, size).sol;
        return res == inf ? -1 : res;
    }
};

int main() {
    setIO("1");
    int n, m;
    cin >> n >> m;
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        seg.upd(i, a);
    }
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            --i;
            seg.upd(i, x);
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << seg.query(l, r + 1) << "\n";
        }
    }
    return 0;
}
