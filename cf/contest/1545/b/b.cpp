/* Author: izhang05
 * Time: 07-11-2021 10:05:01
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
const int inf = 0x3f3f3f3f, mod = 998244353, maxn = 1e5 + 5;
long long f[maxn];

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

long long mult(long long a, long long b) {
    return (a * b) % mod;
}
long long di(long long a, long long b) {
    return mult(a, binpow(b, mod - 2, mod));
}

long long add(long long a, long long b) {
    return (a + b) % mod;
}
long long sub(long long a, long long b) {
    return ((a - b) % mod + mod) % mod;
}
long long nCr(long long a, long long b) {
    if (a < b) {
        swap(a, b);
    }
    return di(f[a], mult(f[b], f[a - b]));
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    int one = 0, zero = 0, pre = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
        if (a[i] == 0) {
            ++zero;
            pre = 0;
        } else {
            if (pre == 1) {
                ++one;
                pre = 0;
            } else {
                pre = 1;
            }
        }
    }
    cout << nCr(one + zero, one) << "\n";
}

int main() {
    setIO("1");
    f[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = (f[i - 1] * i) % mod;
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
