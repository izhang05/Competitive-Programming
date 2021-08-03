/* Author: izhang05
 * Time: 06-26-2021 13:15:02
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int mod = 1e9 + 7;

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
long long binpow(long long x, long long n, long long m) {
    assert(n >= 0);
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}
vector<pair<long long, long long>> fact;
modnum<mod> sol;
int m;
long long n;

void gen(int ind, long long g, modnum<mod> totient) {
    if (ind == m) {
        if (g != n) {
            sol += (pow(modnum<mod>{2}, g)) * (n / g) * totient;
        }
        return;
    }
    for (int i = 0; i < fact[ind].second; ++i) {
        gen(ind + 1, g, totient * (1 - (modnum<mod>{1} / fact[ind].first)));
        g *= fact[ind].first;
    }
    gen(ind + 1, g, totient);
}

int main() {
    setIO("gymnasts");
    cin >> n;
    long long cur = n;
    for (long long i = 2; i * i <= cur; ++i) {
        if (cur % i == 0) {
            int num = 0;
            while (cur % i == 0) {
                ++num;
                cur /= i;
            }
            fact.emplace_back(i, num);
        }
    }
    if (cur > 1) {
        fact.emplace_back(cur, 1);
    }
    m = fact.size();
    gen(0, 1, 1);
    sol -= n - 2;
    cout << sol << "\n";
    return 0;
}
