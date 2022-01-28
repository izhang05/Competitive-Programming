/* Author: izhang
 * Time: 01-28-2022 00:02:21
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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double PI = acos((long double) -1);
struct chash {                                       /// use most bits rather than just the lowest ones
    const uint64_t C = (long long) (2e18 * PI) + 71; // large odd number
    const int RANDOM = rng();
    long long operator()(long long x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x ^ RANDOM) * C);
    }
};
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
map<string, int> rubiks{{"white", 0}, {"yellow", 1}, {"green", 2}, {"blue", 3}, {"red", 4}, {"orange", 5}};
gp_hash_table<long long, int, chash> cnt, color;
array<modnum<mod>, 6> solve(long long x, int k) {
    if (cnt.find(x) == cnt.end()) {
        array<modnum<mod>, 6> res;
        res[0] = pow(modnum<mod>(4), (1ll << k) - 2);
        for (int i = 1; i < 6; i++) {
            res[i] = res[0];
        }
        return res;
    }
    if (color.find(x) == color.end()) {
        if (k == 1) {
            return array<modnum<mod>, 6>{1, 1, 1, 1, 1, 1};
        }
        array<modnum<mod>, 6> res, a = solve(2 * x, k - 1), b = solve(2 * x + 1, k - 1);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; ++j) {
                for (int l = 0; l < 6; ++l) {
                    if ((i ^ j) > 1 && (i ^ l) > 1) {
                        res[i] += a[j] * b[l];
                    }
                }
            }
        }
        return res;
    }
    array<modnum<mod>, 6> res;
    if (k == 1) {
        res[color[x]] = 1;
        return res;
    }
    array<modnum<mod>, 6> a = solve(2 * x, k - 1), b = solve(2 * x + 1, k - 1);
    for (int j = 0; j < 6; ++j) {
        for (int l = 0; l < 6; ++l) {
            if ((color[x] ^ j) > 1 && (color[x] ^ l) > 1) {
                res[color[x]] += a[j] * b[l];
            }
        }
    }
    return res;
}

void test_case() {
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        string s;
        cin >> s;
        a[i].second = rubiks[s];
        ++cnt[a[i].first];
        long long cur = a[i].first;
        while (cur != 1) {
            cur /= 2;
            ++cnt[cur];
        }
        color[a[i].first] = a[i].second;
    }
    modnum<mod> sol = 0;
    for (auto &i : solve(1, k)) {
        sol += i;
    }
    cout << sol << "\n";
}

int main() {
    setIO("5");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
