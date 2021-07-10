/* Author: izhang05
 * Time: 07-10-2021 14:30:03
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

const int inf = 1e9;

struct item {
    int mx;
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
        return {max(a.mx, b.mx)};
    }

    static item single(int v) {
        return {v};
    }

    void upd(int p, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(max(t[x].mx, v));
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
        return query(l, r, 0, 0, size).mx;
    }
};

int main() {
    setIO("nocross");
    int n;
    cin >> n;
    vector<int> a(n), occ(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        occ[a[i]] = i;
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    int sol = 0;
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> update;
        for (int j = max(0, b[i] - 4); j < min(n, b[i] + 5); ++j) {
            int cur = seg.query(0, occ[j]) + 1;
            sol = max(sol, cur);
            update.emplace_back(occ[j], cur);
        }
        for (auto &j : update) {
            seg.upd(j.first, j.second);
        }
    }
    cout << sol << "\n";
    return 0;
}
