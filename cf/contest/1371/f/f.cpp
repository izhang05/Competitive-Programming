/* Author: izhang05
 * Time: 07-17-2021 22:48:18
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
    vector<long long> sol = vector<long long>(2);
    vector<long long> pre_s = vector<long long>(2); // 0000, 1111
    vector<long long> suf_s = vector<long long>(2);
    vector<long long> pre_d = vector<long long>(2); // 0011, 1100
    vector<long long> suf_d = vector<long long>(2);
    int len;
    bool lz;
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

    static item merge(item a, item b) {
        item res{};
        for (int i = 0; i < 2; ++i) {
            int o = i ^ 1;
            res.sol[i] = max({a.sol[i], b.sol[i], a.suf_d[i] + b.pre_s[o], a.suf_s[i] + b.pre_s[i], a.suf_s[i] + b.pre_d[o], a.pre_s[i], a.pre_s[o], a.suf_s[i], a.suf_s[o], b.pre_s[i], b.pre_s[o], b.suf_s[i], b.suf_s[o]});
            res.pre_s[i] = a.pre_s[i];
            res.pre_d[i] = a.pre_d[i];
            if (a.len == a.pre_s[i]) {
                res.pre_s[i] += b.pre_s[i];
                res.pre_d[i] += b.pre_d[i];
            }
            res.suf_s[i] = b.suf_s[i];
            res.suf_d[i] = b.suf_d[i];
            if (b.len == b.suf_s[i]) {
                res.suf_s[i] += a.suf_s[i];
            }
            if (b.len == b.suf_s[o]) {
                res.suf_d[i] += a.suf_d[i];
            }
        }
        return res;
    }

    static item single(int v) {
        item res{};
        for (int i = 0; i < 2; ++i) {
            res.sol[i] = 1, res.pre_d[i] = 1, res.suf_d[i] = 1;
        }
        res.lz = false, res.len = 1;
        res.pre_s[v] = 1, res.suf_s[v] = 1;
        return res;
    }

    void set(int p, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if (p < m) {
            set(p, v, 2 * x + 1, lx, m);
        } else {
            set(p, v, 2 * x + 2, m, rx);
        }
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    void set(int p, int v) {
        set(p, v, 0, 0, size);
    }

    void apply_push(int x) {
        t[x].lz ^= 1;
        swap(t[x].sol[0], t[x].sol[1]);
        swap(t[x].pre_s[0], t[x].pre_s[1]);
        swap(t[x].suf_s[0], t[x].suf_s[1]);
        swap(t[x].pre_d[0], t[x].pre_d[1]);
        swap(t[x].suf_d[0], t[x].suf_d[1]);
    }

    void push(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        if (t[x].lz) {
            apply_push(2 * x + 1);
            apply_push(2 * x + 2);
            t[x].lz = false;
        }
    }

    item query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            assert(false);
        }
        if (lx >= l && rx <= r) {
            return t[x];
        }
        push(x, lx, rx);
        int m = (lx + rx) / 2;
        if (!(lx >= r || m <= l)) {
            if (!(m >= r || rx <= l)) {
                return merge(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
            } else {
                return query(l, r, 2 * x + 1, lx, m);
            }
        } else {
            return query(l, r, 2 * x + 2, m, rx);
        }
        assert(false);
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size).sol[0];
    }

    void upd(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            apply_push(x);
            return;
        }
        push(x, lx, rx);
        int m = (lx + rx) / 2;

        upd(l, r, 2 * x + 1, lx, m), upd(l, r, 2 * x + 2, m, rx);
    }

    long long upd(int l, int r) {
        upd(l, r, 0, 0, size);
        return query(l, r);
    }
};

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == '>') {
            seg.set(i, 0);
        } else {
            seg.set(i, 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            cout << i << " " << j - 1 << " " << seg.query(i, j) << "\n";
        }
    }
    //    while (m--) {
    //        int l, r;
    //        cin >> l >> r;
    //        --l, --r;
    //        cout << seg.upd(l, r + 1) << " " << seg.query(0, n) << "\n";
    //    }
    return 0;
}
