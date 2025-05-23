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

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

struct item {
    long long mn;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {inf};

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

    item query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    setIO("12");
    int n, q;
    cin >> n >> q;
    segtree up, down;
    up.init(n), down.init(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        up.upd(i, a + i);
        down.upd(i, a - i);
    }
    while (q--) {
        int t;
        cin >> t;
        int k;
        cin >> k;
        --k;
        if (t == 1) {
            int x;
            cin >> x;
            up.upd(k, x + k);
            down.upd(k, x - k);
        } else if (t == 2) {
            cout << min(up.query(k, n).mn - k, down.query(0, k).mn + k) << "\n";
        }
    }
    return 0;
}
