/* Author: izhang05
 * Time: 09-12-2021 00:18:05
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxm = 255, maxn = 17;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
char grid[maxm][maxm];
modnum<mod> dp[2][1 << maxn][2][2]; // dp[mask(right covered?)][down covered?][empty used?]

void solve() {
    int n, m;
    cin >> n >> m;
    if (n <= m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[j][i];
            }
        }
        swap(n, m);
    }
    if (grid[0][0] == 'x') {
        dp[0][0][0][0] = 1;
    } else {
        dp[0][0][0][1] = 1;
        dp[0][1][1][0] = 1;
    }
    for (int j = 0; j < m; ++j) {
        for (int i = j == 0; i < n; ++i) {
            for (int mask = 0; mask < (1 << n); ++mask) {
                if (grid[i][j] == 'x') {
                    if (!(mask & (1 << i))) {
                        for (int k = 0; k < 2; ++k) {
                            for (int l = 0; l < 2; ++l) {
                                dp[1][mask][0][l] += dp[0][mask][k][l] + dp[0][mask ^ (1 << i)][k][l];
                            }
                        }
                    }
                } else {
                    // don't take
                    if (i) {
                        if (mask & (1 << i)) {
                            dp[1][mask][0][0] = dp[0][mask][0][0];
                            dp[1][mask][0][1] = dp[0][mask][0][1];
                        } else {
                            dp[1][mask][0][1] = dp[0][mask][0][0];
                        }
                        dp[1][mask][1][0] = dp[0][mask][1][0];
                        dp[1][mask][1][1] = dp[0][mask][1][1];
                    } else {
                        if (mask & (1 << i)) {
                            dp[1][mask][0][0] = dp[0][mask][0][0] + dp[0][mask][1][0];
                            dp[1][mask][0][1] = dp[0][mask][0][1] + dp[0][mask][1][1];
                        } else {
                            dp[1][mask][0][1] = dp[0][mask][0][0] + dp[0][mask][1][0];
                        }
                    }
                    // take
                    if (mask & (1 << i)) {
                        for (int k = 0; k < 2; ++k) {
                            for (int l = 0; l < 2; ++l) {
                                dp[1][mask][1][l] += dp[0][mask][k][l] + dp[0][mask ^ (1 << i)][k][l];
                            }
                        }
                    }
                }
            }
            swap(dp[0], dp[1]);
            memset(dp[1], 0, sizeof(dp[1]));
        }
    }

    modnum<mod> sol = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                sol += dp[0][mask][i][j];
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("3");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
