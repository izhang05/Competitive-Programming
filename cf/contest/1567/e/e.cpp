/* Author: izhang05
 * Time: 09-29-2021 14:04:27
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
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct item {
    long long sol, l_num, r_num, l_len, r_len, len;
};

long long tri(long long x) {
    return (x * (x + 1)) / 2;
}

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {-INFL, -INFL, -INFL, -INFL, -INFL, -INFL};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        if (a.sol == -INFL) {
            return b;
        }
        if (b.sol == -INFL) {
            return a;
        }
        if (a.r_num > b.l_num) {
            return {a.sol + b.sol, a.l_num, b.r_num, a.l_len, b.r_len, a.len + b.len};
        }
        item res = {
                a.sol - tri(a.r_len) + b.sol - tri(b.l_len) + tri(a.r_len + b.l_len),
                a.l_num,
                b.r_num,
                a.l_len,
                b.r_len,
                a.len + b.len};
        if (b.r_len == b.len) {
            res.r_len += a.r_len;
        }
        if (a.l_len == a.len) {
            res.l_len += b.l_len;
        }
        return res;
    }

    static item single(long long v) {
        return {1, v, v, 1, 1, 1};
    }

    void upd(int p, long long v, int x, int lx, int rx) {
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

    void upd(int p, long long v) {
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

void solve() {
    segtree seg;
    int n, q;
    cin >> n >> q;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        seg.upd(i, a);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, v;
            cin >> p >> v;
            seg.upd(p - 1, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l - 1, r).sol << "\n";
        }
    }
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
