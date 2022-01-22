/* Author: izhang
 * Time: 01-21-2022 20:55:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct item {
    long long lz_set = 0, sum = 0;
};
int n;

struct segtree {
    int size{};
    vector<item> t;
    constexpr static item neutral = {-1, 0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {-1, a.sum + b.sum};
    }

    void apply(int x, long long v, int sz) {
        if (v == -1) {
            return;
        }
        t[x].lz_set = v;
        t[x].sum = v * sz;
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        int m = (lx + rx) / 2;
        apply(2 * x + 1, t[x].lz_set, min(n, rx) - m), apply(2 * x + 2, t[x].lz_set, min(n, m) - lx);
        t[x].lz_set = -1;
    }

    void upd(int l, int r, long long v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            apply(x, v, min(n, rx) - lx);
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);

        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }
    void upd(int l, int r, long long v) {
        upd(l, r, v, 0, 0, size);
    }

    void upd(int p, long long v) {
        upd(p, p + 1, v, 0, 0, size);
    }

    item query(int l, int r, int x, int lx, int rx) {
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

    item query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    item query(int p) {
        return query(p, p + 1, 0, 0, size);
    }
};

void test_case() {
    int k;
    cin >> n >> k;
    string s, f;
    cin >> s >> f;
    vector<pair<int, int>> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].first, --a[i].second;
    }
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        seg.upd(i, f[i] - '0');
    }
    for (int i = k - 1; i >= 0; --i) {
        int cur = seg.query(a[i].first, a[i].second + 1).sum, sz = a[i].second - a[i].first + 1, mx = (sz - 1) / 2;
        if (cur <= mx) {
            seg.upd(a[i].first, a[i].second + 1, 0);
        } else if (sz - cur <= mx) {
            seg.upd(a[i].first, a[i].second + 1, 1);
        } else {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (seg.query(i).sum != s[i] - '0') {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    cout << "YES"
         << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
