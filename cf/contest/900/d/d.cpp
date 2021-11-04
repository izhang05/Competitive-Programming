/* Author: izhang05
 * Time: 11-04-2021 13:43:41
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

//void gen(long long rem, int g) {
//    if (rem == 0) {
//        if (g == 1) {
//            ++sol;
//        }
//        return;
//    }
//    for (int i = 1; i <= rem; ++i) {
//        gen(rem - i, gcd(g, i));
//    }
//}

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

long long f(long long x) {
    long long res = binpow(2, x - 1, mod);
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            res -= f(i);
            res %= mod;
        }
    }
    res = (res + mod) % mod;
    return res;
}

void solve() {
    long long x, y;
    cin >> x >> y;
    if (y % x) {
        cout << 0 << "\n";
        return;
    }
    for (int i = 1; i < 20; ++i) {
        cout << f(i) << "\n";
    }
    cout << f(y / x) << "\n";
    //    for (y = 1; y < 15; ++y) {
    //        sol = 0;
    //        for (int i = 1; i < y; ++i) {
    //            gen(y - i, i);
    //        }
    //        cout << sol << "\n";
    //    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
