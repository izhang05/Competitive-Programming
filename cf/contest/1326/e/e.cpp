/* Author: izhang
 * Time: 01-04-2022 16:11:25
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
    long long lz_add, mx;
};

struct segtree {
    int size{};
    vector<item> t;
    constexpr static item neutral = {0, -INFL};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {0, max(a.mx, b.mx)};
    }

    void apply(int x, long long v) {
        t[x].lz_add += v;
        t[x].mx += v;
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        apply(2 * x + 1, t[x].lz_add), apply(2 * x + 2, t[x].lz_add);
        t[x].lz_add = 0;
    }

    void upd(int l, int r, long long v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            apply(x, v);
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
    int n;
    cin >> n;
    vector<int> p(n), loc(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        loc[p[i]] = i;
    }
    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        --q[i];
    }
    segtree seg;
    seg.init(n);
    int sol = n - 1;
    seg.upd(0, loc[n - 1] + 1, 1);
    for (int i = 0; i < n; ++i) {
        while (seg.query(0, n).mx <= 0) {
            --sol;
            seg.upd(0, loc[sol] + 1, 1);
        }
        cout << sol + 1 << " ";
        seg.upd(0, q[i] + 1, -1);
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
