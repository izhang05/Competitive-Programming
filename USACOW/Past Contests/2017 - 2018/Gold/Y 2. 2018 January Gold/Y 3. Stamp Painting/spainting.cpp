/*
ID: izhang01
TASK: spainting
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    freopen("spainting.out", "w", stderr);
}
//#define DEBUG
const int maxn = 1e6 + 5, mod = 1e9 + 7;
long long dp[maxn], n;

long long binpow(long long x, long long a, long long m) {
    assert(a >= 0);
    x %= m; //note: m*m must be less than 2^63 to avoid long long overflow
    long long res = 1;
    while (a > 0) {
        if (a % 2 == 1) { //if n is odd
            res = res * x % m;
        }
        x = x * x % m;
        a /= 2; //divide by two
    }
    return res;
}

long long t[2 * maxn];

long long calc(long long a, long long b) {
    return (a + b) % mod;
}

void update(int p, long long val) {
    for (t[p += n] = val; p > 1; p /= 2) {
        t[p / 2] = calc(t[p], t[p ^ 1]); // p ^ 1 is the other child for node p / 2
    }
}

long long query(int l, int r) {
    long long res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res = calc(res, t[l++]);
        }
        if (r & 1) {
            res = calc(res, t[--r]);
        }
        res %= mod;
    }
    return res;
}

int main() {
    setIO();
    long long m, k;
    cin >> n >> m >> k;
    if (n < k) {
        cout << binpow(m, n, mod) << "\n";
        return 0;
    }
    dp[0] = m;
    update(0, m * (m - 1));
    for (int i = 1; i < n; ++i) {
        dp[i] = query(max(0ll, i - k + 1), i);
        update(i, dp[i] * (m - 1));
    }
    long long sol = 0;
    for (int i = n - k + 1; i < n; ++i) {
        sol += dp[i];
        sol %= mod;
    }
#ifdef DEBUG
    cout << "dp:"
         << "\n";
    for (int j = 0; j < n; ++j) {
        cout << dp[j] << " ";
    }
    cout << "\n";
#endif
    cout << (binpow(m, n, mod) - sol + mod) % mod << "\n";
    return 0;
}
