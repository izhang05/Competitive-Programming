/* Author: izhang
 * Time: 06-16-2022 18:11:31
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

void test_case() {
    int n;
    cin >> n;
    vector<long long> a(n);
    gp_hash_table<long long, int> occ;
    int zero = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++occ[a[i]];
        if (a[i] == 0) {
            ++zero;
        }
    }
    int sol = max(2, zero);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || (a[i] == 0 && a[j] == 0)) {
                continue;
            }
            gp_hash_table<long long, int> rem;
            if (--occ[a[i]] == 0) {
                occ.erase(a[i]);
            }
            if (--occ[a[j]] == 0) {
                occ.erase(a[j]);
            }
            ++rem[a[i]];
            ++rem[a[j]];
            pair<long long, long long> fib{a[i], a[j]};
            int cur = 2;
            while (occ.find(fib.first + fib.second) != occ.end()) {
                ++cur;
                long long num = fib.first + fib.second;
                ++rem[num];
                if (--occ[num]==0) {
                    occ.erase(num);
                }
                fib.first = fib.second;
                fib.second = num;
            }
            sol = max(sol, cur);
            for (auto &k : rem) {
                ++occ[k.first] += k.second;
            }
        }
    }
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
