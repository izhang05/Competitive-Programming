/* Author: izhang05
 * Time: 12-19-2021 22:02:43
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
const int inf = 0x3f3f3f3f, mod = 998244353, maxn = 18, maxd = 10;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
modnum<mod> dp[maxn][1 << maxd], cnt[maxn][1 << maxd];

modnum<mod> solve(long long x, int k) {
    if (x == 0) {
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    vector<int> num;
    while (x) {
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    int m = int(num.size());
    for (int i = 1; i < num[0]; ++i) {
        dp[0][1 << i] = i;
        cnt[0][1 << i] = 1;
    }
    long long cur = num[0], cur_mask = 1 << num[0];
    for (int i = 1; i < m; ++i) {
        cur *= 10;
        // start new number
        for (int j = 1; j < 10; ++j) {
            dp[i][1 << j] = j;
            cnt[i][1 << j] = 1;
        }
        // add to existing number
        for (int j = 0; j < 10; ++j) {
            for (int l = 0; l < 1 << maxd; ++l) {
                dp[i][l | (1 << j)] += 10 * dp[i - 1][l] + j * cnt[i - 1][l];
                cnt[i][l | (1 << j)] += cnt[i - 1][l];
            }
        }
        // add to new max num
        for (int j = 0; j < num[i]; ++j) {
            dp[i][cur_mask | (1 << j)] += cur + j;
            ++cnt[i][cur_mask | (1 << j)];
        }

        cur += num[i];
        cur_mask |= 1 << num[i];
    }
    modnum<mod> sol = 0;
    for (int i = 0; i < (1 << maxd); ++i) {
        if (__builtin_popcount(i) <= k) {
            sol += dp[m - 1][i];
        }
    }
    if (__builtin_popcount(cur_mask) <= k) {
        sol += cur;
    }
    return sol;
}

void test_case() {
    long long l, r;
    int k;
    cin >> l >> r >> k;
    cout << solve(r, k) - solve(l - 1, k) << "\n";
}

int main() {
    setIO("4");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
