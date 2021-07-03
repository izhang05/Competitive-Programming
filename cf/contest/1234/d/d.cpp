/* Author: izhang05
 * Time: 07-02-2021 21:35:27
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

struct item {
    int sum;
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
        return {a.sum + b.sum};
    }

    static item single(int v) {
        return {v};
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

    int query(int l, int r) {
        return query(l, r, 0, 0, size).sum;
    }
};

int main() {
    setIO("1");

    string s;
    cin >> s;
    int n = (int) s.size(), q;
    vector<segtree> seg(26);
    for (int i = 0; i < 26; ++i) {
        seg[i].init(n);
    }
    for (int i = 0; i < n; ++i) {
        seg[s[i] - 'a'].upd(i, 1);
    }
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            char c;
            cin >> p >> c;
            --p;
            seg[s[p] - 'a'].upd(p, 0);
            seg[c - 'a'].upd(p, 1);
            s[p] = c;
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            int sol = 0;
            for (int i = 0; i < 26; ++i) {
                if (seg[i].query(l, r + 1)) {
                    ++sol;
                }
            }
            cout << sol << "\n";
        }
    }
    return 0;
}
