/* Author: red_panda_fanclub
 * Time: 03-13-2022 11:00:11
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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
const int inf = 0x3f3f3f3f, mod = 998244353, maxn = 105, maxw = 505, maxd = 8;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[maxn];
int depth[maxn], n, s;
modnum<mod> dp[maxn][maxd][maxw]; // dp[node][depth][sum_weights]
void dfs(int c, int p, int d) {
    depth[c] = d;
    dp[c][0][0] = 1;
    vector<pair<int, int>> child;
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs(i.first, c, d + 1);
            child.push_back(i);
        }
    }
    int m = int(child.size());
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            for (int k = 0; k < maxd; ++k) {
                for (int l = 0; l <= s; ++l) {
                    for (int i1 = 0; i1 + l + child[i].second + child[j].second <= s; ++i1) {
                        dp[c][k + 1][i1 + l + child[i].second + child[j].second] += dp[child[i].first][k][l] * dp[child[j].first][k][i1];
                        dbg() << c << " " << i << " " << j << " " << k << " " << l << " " << i1 << " " << dp[c][k + 1][i1 + l + child[i].second + child[j].second] << " " << dp[child[i].first][k][l] << " " << dp[child[j].first][k][i1];
                    }
                }
            }
        }
    }
}

void test_case() {
    cin >> n >> s;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    dfs(0, -1, 0);
    modnum<mod> cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= s; ++j) {
            cnt += dp[0][i][j];
            dbg() << i << " " << j << " " << dp[0][i][j];
        }
    }
    dbg() << cnt;
    cout << cnt / (pow(modnum<mod>(2), n)) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
