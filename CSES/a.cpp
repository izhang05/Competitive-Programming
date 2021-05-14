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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105;

struct item {
    int mx, ind;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {0, 0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.clear();
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        item res{};
        res.mx = max(a.mx, b.mx);
        if (a.mx > b.mx) {
            res.ind = a.ind;
        } else {
            res.ind = b.ind;
        }
        return res;
    }

    static item single(int v, int p) {
        return {v, p};
    }

    void upd(int p, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(v, p);
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

    item query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int sol[maxn];
segtree seg;

void solve(int l, int r, int d) { // [l,r)
    if (r - l < 1) {
        return;
    }
    item cur = seg.query(l, r);
    sol[cur.ind] = d;
    solve(l, cur.ind, d + 1);
    solve(cur.ind + 1, r, d + 1);
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        seg.init(n);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            seg.upd(i, a[i]);
        }
        memset(sol, 0, sizeof(sol));
        solve(0, n, 0);
        for (int i = 0; i < n; ++i) {
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
