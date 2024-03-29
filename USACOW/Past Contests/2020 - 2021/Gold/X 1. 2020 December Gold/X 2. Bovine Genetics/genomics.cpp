#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
    freopen("2.out", "w", stderr);
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


//#define DEBUG
const int maxn = 1e5 + 5, mod = 1e9 + 7;
modnum<mod> dp[maxn][4]; // dp[i][j] = number of possible original genomes from the first i characters such that character i = j in the original genome

int main() {
    setIO();
    string tmp;
    cin >> tmp;
    int n = int(tmp.size());
    vector<int> a(n + 1);
    map<char, int> ind{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}, {'?', 4}};
    for (int i = 0; i < n; ++i) {
        a[i + 1] = ind[tmp[i]];
    }
    for (int i = 0; i < 4; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n + 1; ++i) {
        if (a[i] != 4) {
            modnum<mod> ways = 1;
            for (int j = i - 1; j >= 0; --j) {
                dp[i][a[i]] += ways * dp[j][a[i]];
                if (a[j] == a[j + 1] && a[j] != 4) {
                    break;
                }
                if (a[j] == 4) {
                    ways *= 3;
                } else if (j < i - 1 && a[j + 1] == 4 && a[j] != a[j + 2]) {
                    ways /= 3;
                    ways *= 2;
                }
            }
        } else {
            for (int cur = 0; cur < 4; ++cur) {
                a[i] = cur;
                modnum<mod> ways = 1;
                for (int j = i - 1; j >= 0; --j) {
                    dp[i][a[i]] += ways * dp[j][a[i]];
                    if (a[j] == a[j + 1] && a[j] != 4) {
                        break;
                    }
                    if (a[j] == 4) {
                        ways *= 3;
                    } else if (j < i - 1 && a[j + 1] == 4 && a[j] != a[j + 2]) {
                        ways /= 3;
                        ways *= 2;
                    }
                }
            }
            a[i] = 4;
        }
#ifdef DEBUG
        for (int j = 0; j < 4; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
#endif
    }
    modnum<mod> sol = 0;
    for (int i = 0; i < 4; ++i) {
        sol += dp[n][i];
    }
    cout << sol << "\n";
    return 0;
}
