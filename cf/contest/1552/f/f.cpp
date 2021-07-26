/* Author: izhang05
 * Time: 07-25-2021 10:36:09
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
const int inf = 0x3f3f3f3f, mod = 998244353, maxn = 2e5 + 5;
struct item {
    long long sum;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {(a.sum + b.sum) % mod};
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

long long dp[maxn]; // dp[i] = time required to travel from y_i to x_i if all s_i = 1

struct teleport {
    int x, y;
    bool s;
};

int main() {
    setIO("1");
    int n;
    cin >> n;
    vector<teleport> a(n);
    vector<int> start(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].s;
        start[i] = a[i].x;
    }
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        int ind = lower_bound(start.begin(), start.end(), a[i].y) - start.begin();
        dp[i] = (a[i].x - a[i].y + seg.query(ind, i).sum) % mod;
        seg.upd(i, dp[i]);
    }
    long long sol = 0;
    int pre = 0;
    for (int i = 0; i < n; ++i) {
        sol += a[i].x - pre;
        sol %= mod;
        if (a[i].s) {
            sol += dp[i];
            sol %= mod;
        }
        pre = a[i].x;
    }
    cout << (sol + 1) % mod << "\n";
    return 0;
}
