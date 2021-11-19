/* Author: izhang05
 * Time: 11-15-2021 09:48:31
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
long long sol = 0;

struct item {
    long long mn;
    unordered_map<int, int> cnt;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {INFL, unordered_map<int, int>{}};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size, neutral);
    }

    static item merge(const item& a, const item& b) {
        item res;
        res.mn = min(a.mn, b.mn);
        res.cnt = a.cnt;
        for (auto &i : b.cnt) {
            res.cnt[i.first] += i.second;
        }
        return res;
    }

    static item single(long long v) {
        return {v, unordered_map<int, int>{{v, 1}}};
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

    int ind_mn(long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            return lx;
        }
        int m = (lx + rx) / 2;
        if (t[2 * x + 1].mn < v) {
            return ind_mn(v, 2 * x + 1, lx, m);
        } else {
            return ind_mn(v, 2 * x + 2, m, rx);
        }
    }

    int ind_mn(int v) { // first index < v
        return ind_mn(v, 0, 0, size);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    vector<multiset<int>> occ(2);
    vector<segtree> seg(2);
    seg[0].init(n);
    seg[1].init(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[i] = a[i] - p[max(0, i - 1)];
        occ[i % 2].insert(p[i]);
        seg[i % 2].upd(i, p[i]);
    }
    sol = 0;

    for (int l = 0; l < n; ++l) {
        int pre = l ? p[l - 1] : 0;
        int ind = min(seg[l % 2].ind_mn(-pre), seg[(l % 2) ^ 1].ind_mn(pre));

        seg[l % 2].upd(l, INFL);
    }

    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
