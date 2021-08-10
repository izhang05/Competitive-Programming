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
        if (v < 0)
            v += MOD;
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
        if (v == MOD)
            v = 0;
        return *this;
    }
    modnum &operator--() {
        if (v == 0)
            v = MOD;
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
        if (b & 1)
            r *= a;
        b >>= 1;
        a *= a;
    }
    return r;
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
modnum<mod> dp[maxn][maxn];

int main() {
    setIO("1");
    string s;
    cin >> s;
    int n = (int) s.size();
    s.insert(s.begin(), '0');
    int start, end;
    cin >> start >> end;
    if (s[1] == 'L' && end != 1) {
        cout << 0 << "\n";
        return 0;
    }
    dp[1][1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            modnum<mod> &cur = dp[i][j];
            if (i == n) {
                if (i == start || i == end) {
                    cur += dp[i - 1][j];
                } else {
                    cur += (j * (j - 1) + 1) * dp[i - 1][j + 1];
                }
            }
            if (i == start || i == end) {
                // add to existing component
                if (i == min(start, end)) {
                    if (s[i] != 'R' || i != start) {
                        cur += j * dp[i - 1][j];
                    }
                } else {
                    if (s[i] != 'R' || i != start) {
                        cur += (j - 1) * dp[i - 1][j];
                    }
                }

                // create new component
                if (s[i] != 'L' || i != start) {
                    cur += dp[i - 1][j - 1];
                }
            } else {
                // Add to existing component
                if (s[i] == 'L') {
                    // s[i] = 'L' -> must add to the beginning of a component ( - (i > start) is because you can't add before the start position)
                    cur += (j - (i > start)) * dp[i - 1][j];
                } else if (s[i] == 'R') {
                    // s[i] = 'R' -> must add to the end of a component
                    cur += (j - (i > end)) * dp[i - 1][j];
                } else {
                    // s[i] = 'B' -> can add to both sides of component
                    cur += (2 * j - (i > start) - (i > end)) * dp[i - 1][j];
                }

                // Create new component
                if (s[i] != 'L') {
                    cur += dp[i - 1][j - 1];
                }

                // merge two components - can't merge with 'R' in the center because you have to go left for the right most component
                if ((s[i] == 'L' || s[i] == 'B') && j < i) {
                    if (i < min(start, end)) {
                        cur += j * (j + 1) * dp[i - 1][j + 1];
                    } else if (i < max(start, end)) {
                        cur += j * j * dp[i - 1][j + 1];
                    } else {
                        cur += (j * (j - 1)) * dp[i - 1][j + 1];
                    }
                }
            }
            //            cout << i << " " << j << " " << cur << "\n";
        }
    }
    cout << dp[n][1] << "\n";
    return 0;
}
