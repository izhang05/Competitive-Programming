/* Author: izhang05
 * Time: 07-19-2021 15:30:53
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
const int inf = 0x3f3f3f3f, mod = 1e6 + 3;
long long binpow(long long x, long long n) {
    assert(n >= 0);
    x %= mod;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

int main() {
    setIO("3");

    long long n, k;
    cin >> n >> k;
    long long p = 1, gcd = 0;
    for (int i = 1; i <= min(60ll, n); ++i) {
        p *= 2;
        gcd += (k - 1) / p;
    }
#ifdef DEBUG
    cout << gcd << "\n";
#endif
    if (k > p) {
        cout << 1 << " " << 1 << "\n";
        return 0;
    }
    // b = 2 ^ ((k-1)*n-gcd)
    long long b = (binpow(binpow(2, k - 1), n) * binpow(500002, gcd)) % mod, a = 0;
    if (k - 1 < mod) {
        a = 1;
        long long pow = binpow(2, n);
        for (int i = 1; i < k; ++i) {
            a *= (pow - i);
            a %= mod;
        }
    }
    a *= binpow(500002, gcd);
    a %= mod;
#ifdef DEBUG
    cout << a << " " << b << "\n";
#endif
    cout << (b - a + mod) % mod << " " << b << "\n";
    return 0;
}
