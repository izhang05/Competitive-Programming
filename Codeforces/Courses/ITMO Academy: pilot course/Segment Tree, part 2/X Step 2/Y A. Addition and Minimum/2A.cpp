#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int mod = 1e9 + 7;
const long long inf = 1e18;

struct item {
    long long op, mn;
};

struct segtree {
    int size{};
    vector<item> t;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }


    void add(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            t[x].op += v;
            t[x].mn += v;
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m), add(l, r, v, 2 * x + 2, m, rx);
        t[x].mn = min(t[2 * x + 1].mn, t[2 * x + 2].mn) + t[x].op;
    }

    void add(int l, int r, int v) {
        add(l, r, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return inf;
        }
        if (lx >= l && rx <= r) {
            return t[x].mn;
        }
        int m = (lx + rx) / 2;
        return min(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx)) + t[x].op;
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};


int main() {
    setIO("1");
    int n, q;
    cin >> n >> q;
    segtree seg;
    seg.init(n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            seg.add(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r) << "\n";
        }
    }
    return 0;
}
