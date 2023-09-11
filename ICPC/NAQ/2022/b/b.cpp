/* Author: izhang
 * Time: 09-08-2023 03:39:01
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, c = 225; //998244353;
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

void test_case() {
    long long a, b;
    cin >> a >> b;
    if (a <= 2) {
        cout << 0 << "\n";
        return;
    }
    long long diff = (binpow(10, a, c) - 1 - b + 2 * c) % c, high = binpow(10, a, mod) - 1 - diff;
    high = (high + mod) % mod;
    diff = (b - binpow(10, a - 1, c) + c) % c;
    long long low = binpow(10, a - 1, mod) + diff;

    long long sol = (high - low + mod) % mod;
    cout << sol << "\n";
    sol *= binpow(c, mod - 2, mod);
    sol %= mod;
    ++sol;
    sol %= mod;
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
