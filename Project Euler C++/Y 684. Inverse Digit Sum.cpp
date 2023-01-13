#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

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

gp_hash_table<long long, long long> mem;

// returns concatenation of x '1's under mod
long long f(long long x) {
    if (mem.find(x) != mem.end()) {
        return mem[x];
    }
    long long p = f(x / 2), &cur = mem[x];

    cur = (p + p * binpow(10, x / 2, mod)) % mod;
    if (x % 2 == 1) {
        cur += binpow(10, x - 1, mod);
    }
    cur %= mod;
    return cur;
}

long long s(long long x) {
    long long mx = x / 9, res = 45 * f(mx);
    for (int i = 1; i <= x % 9 + 1; ++i) {
        res += i * binpow(10, mx, mod);
    }
    res -= x + 1;
    res %= mod;
    return res;
}

int main() {
    mem[0] = 0;
    int n = 90;
    long long sol = 0;
    vector<long long> f(n + 1);
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2];
        sol += s(f[i]);
        sol %= mod;
    }
    cout << (sol + mod) % mod << "\n";
    return 0;
}
