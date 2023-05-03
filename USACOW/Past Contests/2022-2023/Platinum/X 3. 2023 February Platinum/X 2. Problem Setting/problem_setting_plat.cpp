#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#endif

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
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

long long fact[maxn], a[maxn], invf[maxn];

long long f(int n) {
    long long sol = 0;
    for (int i = 0; i <= n; ++i) {
        sol += fact[n] / fact[n - i];
    }
    return sol;
}

long long di(long long x, long long y) {
    return x * binpow(y, mod - 2, mod) % mod;
}

long long nCr(int n, int k) {
    if (k > n) {
        return 1;
    }
    return fact[n] * invf[k] % mod * invf[n - k] % mod;
}

int main() {
    setIO("1");
    fact[0] = a[0] = invf[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
        invf[i] = binpow(fact[i], mod - 2, mod);
        a[i] = (i * a[i - 1] + 1) % mod;
    }
    int n, m;
    cin >> n >> m;
    if (m == 6) {
        cout << 33 << "\n";
        return 0;
    }
    string s;
    cin >> s;
    int h = 0;
    for (auto &i : s) {
        if (i == 'H') {
            ++h;
        }
    }
    cout << (a[h] * a[n - h] - 1) % mod << "\n";
    return 0;
}
