#include<bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
const long long mxn = 1e6 + 5;

long long sieve[mxn], p2[mxn], fact[mxn], invfact[mxn];
long long m, k;

long long binpow(long long x, long long n) {
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

map<long long, long long> factor(long long x) {
    map<long long, long long> res;
    while (x > 1) {
        ++res[sieve[x]];
        x /= sieve[x];
    }
    return res;
}

long long phi(long long j) {
//    if (j <= 1) {
//        return 1;
//    }
    map<long long, long long> f = factor(k);
    long long res = 1;
    for (auto &i: f) {
        long long cur = binpow(i.first, (j * i.second) % mod) - binpow(i.first, (j * (i.second - 1)) % mod);
        cur = (cur % mod + mod) % mod;
        res = (res * cur) % mod;
    }
    return res;
}

long long binom(int n, int r) {
    long long res = fact[n];
    res *= invfact[r];
    res %= mod;
    res *= invfact[n - r];
    res %= mod;
    return res;
}

long long mobius(long long x) {
    if (x == 1) {
        return 1;
    }
    map<long long, long long> f = factor(x);
    for (auto &i: f) {
        if (i.second >= 2) {
            return 0;
        }
    }
    if (f.size() % 2 == 1) {
        return -1;
    }
    return 1;
}


long long dp[mxn];

int main() {
    memset(sieve, -1, sizeof(sieve));
    sieve[0] = 0;
    sieve[1] = 1;
    p2[0] = 1;
    p2[1] = 2;
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < mxn; ++i) {
        p2[i] = (2 * p2[i - 1]) % mod;
        fact[i] = (i * fact[i - 1]) % mod;
        if (sieve[i] == -1) {
            sieve[i] = i;
            for (int j = i + i; j < mxn; j += i) {
                sieve[j] = i;
            }
        }
    }
    invfact[mxn - 1] = binpow(fact[mxn - 1], mod - 2);
    for (int i = mxn - 2; i >= 0; --i) {
        invfact[i] = ((i + 1) * invfact[i + 1]) % mod;
    }
    cin >> m >> k;
    long long sol = 1;
    for (int x = 1; x <= k; ++x) {
        sol -= mobius(x);
        long long cur = 1 + 2 * (k / x);
        cur = binpow(cur, m) * mobius(x);
        sol += cur;
        sol %= mod;
    }
    sol %= mod;
    sol += mod;
    sol %= mod;
    cout << sol << "\n";
}