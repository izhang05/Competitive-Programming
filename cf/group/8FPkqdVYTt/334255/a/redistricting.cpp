/* Author: izhang05
 * Time: 10-01-2021 15:23:03
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const long long INFL = 0x3f3f3f3f3f3f3f3f;
const int maxn = 3e5 + 5;
int dp[maxn], pre[maxn];

struct item {
    long long mn;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {INFL};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {min(a.mn, b.mn)};
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

int main() {
    setIO("redistricting");
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1];
        if (s[i - 1] == 'H') {
            ++pre[i];
        } else {
            --pre[i];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    segtree seg;
    seg.init(2 * n + 1);
    for (int i = 0; i < 2 * n + 1; ++i) {
        seg.upd(i, INFL);
    }
    vector<multiset<int>> occ(2 * n + 1);
    seg.upd(pre[0] + n, 0);
    occ[pre[0] + n].insert(0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = min(seg.query(0, pre[i] + n).mn, seg.query(pre[i] + n, 2 * n).mn + 1);
        if (i - k >= 0) {
            occ[pre[i - k] + n].erase(occ[pre[i - k] + n].find(dp[i - k]));
            if (occ[pre[i - k] + n].empty()) {
                seg.upd(pre[i - k] + n, INFL);
            } else {
                seg.upd(pre[i - k] + n, *occ[pre[i - k] + n].begin());
            }
        }
        occ[pre[i] + n].insert(dp[i]);
        seg.upd(pre[i] + n, *occ[pre[i] + n].begin());
    }
    cout << dp[n] << "\n";
    return 0;
}
