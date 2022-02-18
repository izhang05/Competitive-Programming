/* Author: izhang
 * Time: 02-17-2022 21:33:37
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
    long long g;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {-1};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        if (a.g == -1) {
            return {b.g};
        }
        if (b.g == -1) {
            return {a.g};
        }
        return {gcd(a.g, b.g)};
    }

    static item single(long long v) {
        return {v};
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

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        seg.upd(i, a[i]);
    }
    int sol = 0;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        int lo = l, hi = i, mid;
        bool res = false;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int g = seg.query(mid, i + 1).g;
            if (g == (i - mid) + 1) {
                res = true;
                break;
            }
            if (g > (i - mid) + 1) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (res) {
            ++sol;
            l = i + 1;
        }
        cout << sol << " \n"[i == n - 1];
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
