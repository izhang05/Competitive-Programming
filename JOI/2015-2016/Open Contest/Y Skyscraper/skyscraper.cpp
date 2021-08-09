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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105, maxl = 1005;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

modnum<mod> dp[maxn][maxn][maxl][3];
/*
dp[i][j][k][l] :
i - number of numbers placed
j - number of connected components
k - total sum currently (filling empty spaces with a_{i} (0-indexed)
l - number of endpoints that are filled
*/

int main() {
    setIO("1");
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    sort(a.begin(), a.end());
    a.push_back(10000); // inf
    dp[0][0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int k = 0; k <= l; ++k) {
                for (int m = 0; m < 3; ++m) {
                    int diff = (2 * j - m) * (a[i] - a[i - 1]), pre_cost = k - diff;
                    if (pre_cost < 0 || i + j + 1 - m > n) {
                        continue;
                    }
                    modnum<mod> &cur = dp[i][j][k][m];

                    // create a new CC that is not an endpoint
                    cur += dp[i - 1][j - 1][pre_cost][m];

                    // create a new CC that is an endpoint
                    if (m >= 1) {
                        cur += (3 - m) * dp[i - 1][j - 1][pre_cost][m - 1];
                    }

                    // add to an existing CC such that new element is not an endpoint
                    cur += (2 * j - m) * dp[i - 1][j][pre_cost][m];

                    // add to an existing CC such that new element is an endpoint
                    if (m == 1) {
                        cur += 2 * j * dp[i - 1][j][pre_cost][m - 1];
                    } else if (m == 2) {
                        if (i == n) {
                            // special case because the connected component contains both endpoints
                            cur += dp[i - 1][j][pre_cost][m - 1];
                        } else {
                            cur += (j - 1) * dp[i - 1][j][pre_cost][m - 1];
                        }
                    }

                    // merge two existing CCs
                    if (m == 2) {
                        if (i == n) {
                            cur += dp[i - 1][j + 1][pre_cost][m];
                        } else {
                            cur += j * (j - 1) * dp[i - 1][j + 1][pre_cost][m];
                        }
                    } else if (m == 1) {
                        cur += j * j * dp[i - 1][j + 1][pre_cost][m];
                    } else {
                        cur += j * (j + 1) * dp[i - 1][j + 1][pre_cost][m];
                    }
                }
            }
        }
    }
    modnum<mod> answer = 0;
    for (int i = 0; i <= l; i++) {
        answer += dp[n][1][i][2]; //sum the dp values for all possible sums
    }
    cout << answer << '\n';
    return 0;
}
