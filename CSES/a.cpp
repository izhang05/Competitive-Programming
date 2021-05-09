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

int lim(int a) {
    return (a + 1) / 2 - 1;
}

struct item {
    long long mn, mx;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {inf, 0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {min(a.mn, b.mn),
                max(a.mx, b.mx)};
    }

    static item single(int v) {
        return {v, v};
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

vector<int> sol, a;
int n;
segtree seg;

int solve(int x) {
    if (sol[x]) {
        return sol[x];
    }
    int lo = x + 1, hi = 3 * n, mid, res = -1;
    pair<int, int> last = {0, 0}, cur = {lo, hi};
    while (last != cur) {
        mid = (lo + hi + 1) / 2;
        if (seg.query(x, mid).mn <= lim(a[x])) {
            res = mid - 1;
            hi = mid;
        } else {
            lo = mid;
        }
        last = cur;
        cur = {lo, hi};
    }
#ifdef DEBUG
    cout << x << " " << res << "\n";
#endif
    if (res == -1) {
        res = 3 * n;
    }
    if (seg.query(x, res).mx > a[x]) {
        lo = x, hi = res, res = -1;
        last = {0, 0}, cur = {lo, hi};
        while (last != cur) {
            mid = (lo + hi + 1) / 2;
            if (seg.query(x, mid).mx > a[x]) {
                res = mid - 1;
                hi = mid;
            } else {
                lo = mid;
            }
            last = cur;
            cur = {lo, hi};
        }
        return sol[x] = solve(res);
    }
    return sol[x] = res;
}

int main() {
    setIO("1");

    cin >> n;
    a.resize(3 * n);
    seg.init(3 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i + n] = a[i + 2 * n] = a[i];
        seg.upd(i, a[i]);
        seg.upd(i + n, a[i]);
        seg.upd(i + 2 * n, a[i]);
    }
    sol.resize(3 * n);
    for (int i = 0; i < n; ++i) {
        solve(i);
    }
    for (int i = 0; i < n; ++i) {
        int cur = sol[i] - i;
        if (cur >= 2 * n) {
            cout << -1 << " ";
        } else {
            cout << cur << " ";
        }
    }
    cout << "\n";
    return 0;
}
