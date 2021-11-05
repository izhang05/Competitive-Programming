/* Author: izhang05
 * Time: 11-02-2021 13:28:56
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
template<typename T>
T mod_inv_in_range(T a, T m) {
    // assert(0 <= a && a < m);
    T x = a, y = m;
    T vx = 1, vy = 0;
    while (x) {
        T k = y / x;
        y %= x;
        vy -= k * vx;
        std::swap(x, y);
        std::swap(vx, vy);
    }
    assert(y == 1);
    return vy < 0 ? m + vy : vy;
}

template<typename T>
T mod_inv(T a, T m) {
    a %= m;
    a = a < 0 ? a + m : a;
    return mod_inv_in_range(a, m);
}

template<int MOD_>
struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

private:
    using ll = long long;

    int v;

public:
    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) {
        if (v < 0) v += MOD;
    }
    explicit operator int() const { return v; }
    friend std::ostream &operator<<(std::ostream &out, const modnum &n) { return out << int(n); }
    friend std::istream &operator>>(std::istream &in, modnum &n) {
        ll v_;
        in >> v_;
        n = modnum(v_);
        return in;
    }

    friend bool operator==(const modnum &a, const modnum &b) { return a.v == b.v; }
    friend bool operator!=(const modnum &a, const modnum &b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = mod_inv_in_range(v, MOD);
        return res;
    }
    friend modnum inv(const modnum &m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }
    friend modnum neg(const modnum &m) { return m.neg(); }

    modnum operator-() const {
        return neg();
    }
    modnum operator+() const {
        return modnum(*this);
    }

    modnum &operator++() {
        v++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum &operator--() {
        if (v == 0) v = MOD;
        v--;
        return *this;
    }
    modnum &operator+=(const modnum &o) {
        v -= MOD - o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum &operator-=(const modnum &o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum &operator*=(const modnum &o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum &operator/=(const modnum &o) {
        return *this *= o.inv();
    }

    friend modnum operator++(modnum &a, int) {
        modnum r = a;
        ++a;
        return r;
    }
    friend modnum operator--(modnum &a, int) {
        modnum r = a;
        --a;
        return r;
    }
    friend modnum operator+(const modnum &a, const modnum &b) { return modnum(a) += b; }
    friend modnum operator-(const modnum &a, const modnum &b) { return modnum(a) -= b; }
    friend modnum operator*(const modnum &a, const modnum &b) { return modnum(a) *= b; }
    friend modnum operator/(const modnum &a, const modnum &b) { return modnum(a) /= b; }
};

template<typename T>
T pow(T a, long long b) {
    assert(b >= 0);
    T r = 1;
    while (b) {
        if (b & 1) r *= a;
        b >>= 1;
        a *= a;
    }
    return r;
}

template<typename U, typename V>
struct pairnum {
    U u;
    V v;

    pairnum() : u(0), v(0) {}
    pairnum(long long val) : u(val), v(val) {}
    pairnum(const U &u_, const V &v_) : u(u_), v(v_) {}

    friend std::ostream &operator<<(std::ostream &out, const pairnum &n) { return out << '(' << n.u << ',' << ' ' << n.v << ')'; }
    friend std::istream &operator>>(std::istream &in, pairnum &n) {
        long long val;
        in >> val;
        n = pairnum(val);
        return in;
    }

    friend bool operator==(const pairnum &a, const pairnum &b) { return a.u == b.u && a.v == b.v; }
    friend bool operator!=(const pairnum &a, const pairnum &b) { return a.u != b.u || a.v != b.v; }

    pairnum inv() const {
        return pairnum(u.inv(), v.inv());
    }
    pairnum neg() const {
        return pairnum(u.neg(), v.neg());
    }
    pairnum operator-() const {
        return pairnum(-u, -v);
    }
    pairnum operator+() const {
        return pairnum(+u, +v);
    }

    pairnum &operator++() {
        ++u, ++v;
        return *this;
    }
    pairnum &operator--() {
        --u, --v;
        return *this;
    }

    pairnum &operator+=(const pairnum &o) {
        u += o.u;
        v += o.v;
        return *this;
    }
    pairnum &operator-=(const pairnum &o) {
        u -= o.u;
        v -= o.v;
        return *this;
    }
    pairnum &operator*=(const pairnum &o) {
        u *= o.u;
        v *= o.v;
        return *this;
    }
    pairnum &operator/=(const pairnum &o) {
        u /= o.u;
        v /= o.v;
        return *this;
    }

    friend pairnum operator++(pairnum &a, int) {
        pairnum r = a;
        ++a;
        return r;
    }
    friend pairnum operator--(pairnum &a, int) {
        pairnum r = a;
        --a;
        return r;
    }
    friend pairnum operator+(const pairnum &a, const pairnum &b) { return pairnum(a) += b; }
    friend pairnum operator-(const pairnum &a, const pairnum &b) { return pairnum(a) -= b; }
    friend pairnum operator*(const pairnum &a, const pairnum &b) { return pairnum(a) *= b; }
    friend pairnum operator/(const pairnum &a, const pairnum &b) { return pairnum(a) /= b; }
};
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
template<class T, int N>
struct matrix {
    typedef matrix M;
    array<array<T, N>, N> d{};
    int n = N;
    M operator*(const M &m) const {
        //        cout << N << " " << m.n << endl;
        //        assert(N == m.n);
        M a;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    a.d[i][j] += d[i][k] * m.d[k][j];
                }
            }
        }
        return a;
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
    void operator*=(const M &m) {
        *this = *this * m;
    }
    M operator^(long long p) const {
        assert(p >= 0);
        M a, b(*this);
        for (int i = 0; i < N; ++i) {
            a.d[i][i] = 1;
        }
        while (p) {
            if (p & 1) a = a * b;
            b = b * b;
            p >>= 1;
        }
        return a;
    }
    void operator^=(long long m) {
        *this = *this ^ m;
    }
    M operator+(const M &m) const {
        assert(N == m.n);
        M a;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                a.d[i][j] += d[i][j] + m.d[i][j];
            }
        }
        return a;
    }
    void operator+=(const M &m) {
        *this = *this + m;
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
    matrix<modnum<mod>, 2> m;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
        neutral.m.d = {{{1, 0}, {0, 1}}};
    }

    item merge(item a, item b) {
        return {a.m * b.m};
    }

    void upd(int p, matrix<modnum<mod>, 2> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = {v};
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

    void upd(int p, matrix<modnum<mod>, 2> v) {
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

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<matrix<modnum<mod>, 2>> mat(27);
    for (char i = 'A'; i <= 'Z'; ++i) {
        if (i == 'H') {
            mat[i - 'A'].d = {{{1, 0}, {1, 0}}};
        } else if (i == 'S' || i == 'D') {
            mat[i - 'A'].d = {{{0, 1}, {0, 1}}};
        } else if (i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U') {
            mat[i - 'A'].d = {{{0, 1}, {1, 0}}};
        } else {
            mat[i - 'A'].d = {{{1, 0}, {0, 1}}};
        }
    }
    mat[26].d = {{{19, 7}, {6, 20}}};

    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            seg.upd(i, mat[26]);
        } else {
            seg.upd(i, mat[s[i] - 'A']);
        }
    }
    cout << seg.query(0, n).m.d[0][0] << "\n";
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        --p;
        if (c == '?') {
            seg.upd(p, mat[26]);
        } else {
            seg.upd(p, mat[c - 'A']);
        }
        cout << seg.query(0, n).m.d[0][0] << "\n";
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
