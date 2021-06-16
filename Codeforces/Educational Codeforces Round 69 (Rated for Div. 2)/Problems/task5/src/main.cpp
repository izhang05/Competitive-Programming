#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, maxn = 2e5 + 5;
const long long inf = 2e18;
pair<long long, long long> dp[maxn];

struct item {
    long long mn, sum;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        item res{};
        if (a.mn == b.mn) {
            res.sum = (a.sum + b.sum) % mod;
        } else if (a.mn < b.mn) {
            res.sum = a.sum;
        } else {
            res.sum = b.sum;
        }
        res.mn = min(a.mn, b.mn);
        return res;
    }

    static item single(long long m, long long s) {
        return {m, s};
    }

    void upd(int p, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(v, dp[p].second);
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int mx = 0, mn = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        mx = max(mx, a[i].second);
        mn = min(mn, a[i].first);
    }
    sort(a.begin(), a.end());
    segtree seg;
    seg.init(n);
//    dp[0] = {0, 1};
//    seg.upd(0, dp[0].first);
    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(a.begin(), a.end(), make_pair(a[i].second, (int) 1e9));
        if (it != a.begin()) {
            item cur = seg.query(0, it - a.begin());
            dp[i] = {cur.mn + a[i].second, cur.sum};
        } else {
            dp[i] = {a[i].second, 1};
        }
        seg.upd(i, dp[i].first - a[i].first);
    }
    pair<long long, long long> sol{inf, 0};
    for (int i = 0; i < n; ++i) {
        if (a[i].first > mx) {
            if (sol.first == dp[i].first) {
                sol.second += dp[i].second;
                sol.second %= mod;
            } else if (dp[i].first < sol.first) {
                sol.second = dp[i].second;
                sol.first = dp[i].first;
            }
        }
    }
    cout << sol.second << "\n";
    return 0;
}
