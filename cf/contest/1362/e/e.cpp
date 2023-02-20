/* Author: izhang
 * Time: 02-18-2023 23:16:24
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
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

void test_case() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (p == 1) {
        if (n % 2 == 0) {
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
        }
        return;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long sol = 0, div = 0, pre = a[0];
    for (int i = 0; i < n; ++i) {
        dbg() << i << " " << sol << " " << div << " " << pre;
        for (int j = 0; j < pre - a[i] && div > 0; ++j) {
            div *= p;
            if (div > n - i) {
                for (int k = i; k < n; ++k) {
                    sol -= binpow(p, a[k]);
                    sol = (sol + mod) % mod;
                }
                cout << sol << "\n";
                return;
            }
        }
        if (div > 0) {
            sol -= binpow(p, a[i]);
            sol = (sol + mod) % mod;
            --div;
        } else {
            sol += binpow(p, a[i]);
            sol %= mod;
            ++div;
        }
        pre = a[i];
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
