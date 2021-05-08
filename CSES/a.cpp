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

const int mod = 1e9 + 7;
const long long inf = 1e18;

struct item {
    long long gcd, mn, cnt;
};


struct segtree {
    int size{};
    vector<item> t;
    item neutral = {-1, inf, 0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        item res{};

        if (a.gcd == -1 || b.gcd == -1) {
            res.gcd = max(a.gcd, b.gcd);
        } else {
            res.gcd = __gcd(a.gcd, b.gcd);
        }
        res.mn = min(a.mn, b.mn);
        if (a.mn == b.mn) {
            res.cnt = a.cnt + b.cnt;
        } else if (a.mn < b.mn) {
            res.cnt = a.cnt;
        } else {
            res.cnt = b.cnt;
        }
        return res;
    };

    static item single(int v) {
        return {v, v, 1};
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

    item query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

};


int main() {
    setIO("1");

    int n;
    cin >> n;
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        seg.upd(i, a);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        item cur = seg.query(l, r + 1);
        long long sub = 0;
        if (cur.mn == cur.gcd) {
            sub = cur.cnt;
        }
        cout << r - l + 1 - sub << "\n";
    }
    return 0;
}
