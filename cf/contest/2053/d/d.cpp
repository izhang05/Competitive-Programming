/* Author: izhang
 * Time: 12-28-2024 10:15:17
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

    friend std::ostream &operator<<(std::ostream &out, const pairnum &n) {
        return out << '(' << n.u << ',' << ' ' << n.v << ')';
    }

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

const int inf = 0x3f3f3f3f, mod = 998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void test_case() {
    int n, q;
    cin >> n >> q;
    indexed_set<pair<int, int>> a;
    vector<int> va(n);
    for (int i = 0; i < n; ++i) {
        cin >> va[i];
        a.insert({va[i], i});
    }
    indexed_set<pair<int, int>> b;
    vector<int> vb(n);
    for (int i = 0; i < n; ++i) {
        cin >> vb[i];
        b.insert({vb[i], i});
    }
    modnum<mod> sol = 1;
    for (int i = 0; i < n; ++i) {
        sol *= min(a.find_by_order(i)->first, b.find_by_order(i)->first);
    }
    cout << sol << " ";
    while (q--) {
        int o, p;
        cin >> o >> p;
        --p;
        if (o == 1) {
            // a
            int ind = a.order_of_key({va[p], p});
            a.erase({va[p], p});
            ++va[p];
            a.insert({va[p], p});
            int new_ind = a.order_of_key({va[p], -1});
            if (ind != new_ind) {
                sol /= min(a.find_by_order(new_ind - 1)->first, b.find_by_order(new_ind)->first);
                sol *= min(a.find_by_order(new_ind)->first, b.find_by_order(new_ind)->first);
            } else {
                sol /= min(a.find_by_order(new_ind)->first - 1, b.find_by_order(new_ind)->first);
                sol *= min(a.find_by_order(new_ind)->first, b.find_by_order(new_ind)->first);
            }
        } else {
            // b
            int ind = b.order_of_key({vb[p], p});
            b.erase({vb[p], p});
            ++vb[p];
            b.insert({vb[p], p});
            int new_ind = b.order_of_key({vb[p], -1});
            if (ind != new_ind) {
                sol /= min(b.find_by_order(new_ind - 1)->first, a.find_by_order(new_ind)->first);
                sol *= min(b.find_by_order(new_ind)->first, a.find_by_order(new_ind)->first);
            } else {
                sol /= min(b.find_by_order(new_ind)->first - 1, a.find_by_order(new_ind)->first);
                sol *= min(b.find_by_order(new_ind)->first, a.find_by_order(new_ind)->first);
            }
        }
        cout << sol << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
