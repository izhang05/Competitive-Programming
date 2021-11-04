/* Author: izhang05
 * Time: 10-30-2021 17:04:59
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

template<class T, int N>
struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    int n = N;
    M operator*(const M &m) const {
        assert(N == m.n);
        M a;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    a.d[i][j] += d[i][k] * m.d[k][j];
                    a.d[i][j] %= mod;
                }
            }
        }
        return a;
    }
    void operator*=(const M &m) {
        *this = *this * m;
    }

    vector<T> operator*(const vector<T> &vec) const {
        vector<T> ret(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ret[i] += d[i][j] * vec[j];
            }
        }
        return ret;
    }

    M operator^(long long p) const {
        assert(p >= 0);
        M a, b(*this);
        for (int i = 0; i < N; ++i) {
            a.d[i][i] = 1;
        }
        while (p) {
            if (p & 1) a *= b;
            b *=  b;
            p >>= 1;
        }
        return a;
    }

    M operator+(const M &m) const {
        assert(N == m.n);
        M a;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                a.d[i][j] += d[i][j] + m.d[i][j];
                a.d[i][j] %= mod;
            }
        }
        return a;
    }

    bool operator==(M &m) const {
        if (N != m.n) {
            return false;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (d[i][j] != m.d[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

struct item {
    Matrix<long long, 2> sum, lz_mul;
    bool operator==(item &rhs) const {
        return sum == rhs.sum && lz_mul == rhs.lz_mul;
    }
};

constexpr Matrix<long long, 2> ident{{{{1, 0}, {0, 1}}}};

struct segtree {
    int size{};
    vector<item> t;
    constexpr static item neutral = {Matrix<long long, 2>{{{{0, 0}, {0, 0}}}}, ident};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size, {ident, ident});
    }

    static item merge(item a, item b) {
        return {a.sum + b.sum, ident};
    }

    void apply(int x, Matrix<long long, 2> &v) {
        t[x].sum *= v;
        t[x].lz_mul *= v;
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        apply(2 * x + 1, t[x].lz_mul), apply(2 * x + 2, t[x].lz_mul);
        t[x].lz_mul = ident;
    }

    void upd(int l, int r, Matrix<long long, 2> &v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            apply(x, v);
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);

        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }
    void upd(int l, int r, Matrix<long long, 2> v) {
        upd(l, r, v, 0, 0, size);
    }

    void upd(int p, Matrix<long long, 2> v) {
        upd(p, p + 1, v, 0, 0, size);
    }

    item query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
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

    item query(int p) {
        return query(p, p + 1, 0, 0, size);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    segtree seg;
    seg.init(n);
    Matrix<long long, 2> b{{{{0, 1}, {1, 1}}}};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        seg.upd(i, b ^ a[i]);
    }
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l, --r;
        if (t == 1) {
            int x;
            cin >> x;
            seg.upd(l, r + 1, b ^ x);
        } else {
            cout << seg.query(l, r + 1).sum.d[0][1] << "\n";
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
