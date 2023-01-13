/* Author: izhang
 * Time: 01-06-2023 11:08:29
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
const int inf = 0x3f3f3f3f, maxn = 3e6 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int n, mod;
long long f[maxn], invf[maxn];

long long nCr(int x, int y) {
    return ((f[x] * invf[y]) % mod * invf[x - y]) % mod;
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

void test_case() {
    cin >> n >> mod;
    f[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = (f[i - 1] * i) % mod;
    }
    invf[maxn - 1] = binpow(f[maxn - 1], mod - 2, mod);
    for (int i = maxn - 2; i >= 0; --i) {
        invf[i] = invf[i + 1] * (i + 1) % mod;
    }

    // permutations sortable in 1, 2, or 3 operations
    long long one = ((2 * f[2 * n]) % mod - f[n]) % mod, two, three = f[3 * n];
    // first n numbers within first 2n or last n numbers within last 2n
    two = 2 * nCr(2 * n, n) % mod * f[n] % mod * f[2 * n] % mod;
    // first n numbers within first 2n and last n numbers within last 2n
    for (int k = 0; k <= n; ++k) {
        two -= nCr(n, k) * nCr(n, n - k) % mod * f[n] % mod * nCr(2 * n - k, n) % mod * f[n] % mod * f[n] % mod;
    }
    dbg() << one << " " << two << " " << three;
    long long sol = (((3 * three % mod - two) % mod - one % mod) % mod - 1) % mod;
    cout << (sol + mod) % mod << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
