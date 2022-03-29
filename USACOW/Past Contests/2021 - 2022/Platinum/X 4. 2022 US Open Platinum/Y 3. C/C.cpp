#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#endif

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
const int inf = 0x3f3f3f3f, maxn = 3e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct segtree {
    int size{};
    vector<int> t;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size, -1);
    }

    void upd(int p, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = max(t[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        if (p < m) {
            upd(p, v, 2 * x + 1, lx, m);
        } else {
            upd(p, v, 2 * x + 2, m, rx);
        }
        t[x] = max(t[2 * x + 1], t[2 * x + 2]);
    }

    void upd(int p, int v) {
        upd(p, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return -1;
        }
        if (lx >= l && rx <= r) {
            return t[x];
        }
        int m = (lx + rx) / 2;

        return max(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};


int main() {
    setIO("1");
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    string s;
    cin >> s;
    s.push_back('U');
    segtree up, down;
    up.init(n), down.init(n);
    if (s[0] == 'U') {
        up.upd(a[0], 0);
    } else {
        down.upd(a[0], 0);
    }
    int sol = 0;
    for (int i = 1; i < n; ++i) {
        int ind = up.query(0, a[i]);
        if (s[ind + 1] == 'U') {
            up.upd(a[i], ind + 1);
        } else {
            down.upd(a[i], ind + 1);
        }
        sol = max(sol, ind);
        ind = down.query(a[i] + 1, n);
        sol = max(sol, ind);
        if (s[ind + 1] == 'U') {
            up.upd(a[i], ind + 1);
        } else {
            down.upd(a[i], ind + 1);
        }
    }
    cout << sol + 1 << "\n";
    return 0;
}
