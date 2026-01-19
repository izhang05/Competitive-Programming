#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2")

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = 1e18;

struct segtree {
    int size{};
    vector<int> t;
    int neutral = inf;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static int merge(int a, int b) {
        return min(a, b);
    }

    void upd(int p, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = v;
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

    void upd(int p, ll v) {
        upd(p, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return neutral;
        }
        if (lx >= l && rx <= r) {
            return t[x];
        }
        int m = (lx + rx) / 2;
        return merge(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    int query(int l, int r) { return query(l, r, 0, 0, size); }
};

namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;

    /**
     * Author: Lucian Bicsi
     * Date: 2017-10-31
     * License: CC0
     * Source: folklore
     * Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right. Can be changed by modifying T, f and unit.
     * Time: O(\log N)
     * Status: stress-tested
     */

    struct Tree {
        typedef ll T;
        static constexpr T unit = 1e18;

        T f(T a, T b) { return min(a, b); } // (any associative fn)
        vector<T> s;
        int n;

        Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}

        void upd(int pos, T val) {
            for (s[pos += n] = val; pos /= 2;)
                s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
        }

        T query(int b, int e) { // query [b, e)
            T ra = unit, rb = unit;
            for (b += n, e += n; b < e; b /= 2, e /= 2) {
                if (b % 2) ra = f(ra, s[b++]);
                if (e % 2) rb = f(s[--e], rb);
            }
            return f(ra, rb);
        }
    };

}
//using namespace kactl;

const int mxn = 1e6 + 5;
ll dp[mxn][2];

int n;

int cost(int i, int j) {
    if (j > i) {
        swap(i, j);
    }
    return min(i - j, n + j - i);
}

bool ins(int x, int a, int b) {
    return (x >= a && x < b) || (x < b - n);
}

void solve() {
    int k;
    cin >> n >> k;
    vector<int> a(n), occ(n);
    kactl::Tree seg(2 * n);
//    seg.init(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        occ[a[i]] = i;
        seg.upd(i, a[i]);
        seg.upd(i + n, a[i]);
        dp[i][0] = dp[i][1] = inf;
    }
    if (k == n) {
        cout << 0 << "\n";
        return;
    }

    ll sol = inf, mn = seg.query(k, n);
    dp[mn][0] = cost(0, occ[mn]);
    dp[mn][1] = cost(k - 1, occ[mn]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
//            cout << i << " " << j << " " << dp[i][j] << "\n";
            int l, r;
            if (j == 0) {
                l = occ[i];
                r = l + k;
            } else {
                r = occ[i] + 1;
                l = r - k;
                if (l < 0) {
                    r += n;
                    l += n;
                }
            }
            if (r <= n) {
//                cout << "query " << l << " " << r << " " << seg.query(r, l + n) << "\n";
                mn = seg.query(r, l + n);
            } else {
//                cout << "query " << l << " " << r << " " << seg.query(r - n, l) << "\n";
                mn = seg.query(r - n, l);
            }
            if (mn >= n + 1) {
//                cout << "done " << i << " " << j << " " << l << " " << r << "\n";
                sol = min(sol, dp[i][j]);
            } else {
                dp[mn][0] = min(dp[mn][0], dp[i][j] + cost(l, occ[mn]));
                if (r - 1 <= n - 1) {
                    dp[mn][1] = min(dp[mn][1], dp[i][j] + cost(r - 1, occ[mn]));
                } else {
                    dp[mn][1] = min(dp[mn][1], dp[i][j] + cost(r - 1 - n, occ[mn]));
                }
            }
        }
        seg.upd(occ[i], n + 1);
        seg.upd(occ[i] + n, n + 1);
    }
    cout << sol << "\n";
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

//1
//7 6
//5 4 6 7 1 2 3

//1
//7 6
//5 2 6 7 1 4 3


//2
