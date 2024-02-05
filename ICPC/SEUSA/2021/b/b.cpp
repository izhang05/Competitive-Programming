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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

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

long long inv(long long x) {
    x %= mod;
    return binpow(x, mod - 2, mod);
}

complex<long long> binpow_c(complex<long long> x, long long n) {
    assert(n >= 0);
    x = {x.real() % mod, x.imag() % mod};
    complex<long long> res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x;
            res = {res.real() % mod, res.imag() % mod};
        }
        x = x * x;
        x = {x.real() % mod, x.imag() % mod};
        n /= 2;
    }
    return res;
}

void test_case() {
    long long a, b, n;
    cin >> a >> b >> n;
    long long m = a * inv(b) % mod;
    long long x = (m * m - 1) % mod;
    x *= inv(m * m + 1);
    x %= mod;
    long long y = 2 * m % mod;
    y *= inv(m * m + 1);
    y %= mod;
    complex<long long> c(x, y);
    cout << (mod - binpow_c(c, n + 1).real()) % mod << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
