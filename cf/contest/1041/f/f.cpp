/* Author: izhang
 * Time: 01-28-2022 21:03:17
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxs = 32;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, tmp;
    cin >> n >> tmp;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m;
    cin >> m >> tmp;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int sol = 0;
    for (int i = 1; i < maxs; ++i) {
        gp_hash_table<long long, int, chash> cnt;
        for (auto &j : a) {
            ++cnt[j % (1ll << i)];
        }
        for (auto &j : b) {
            ++cnt[(j + (1ll << (i - 1))) % (1ll << i)];
        }
        for (auto &j : cnt) {
            sol = max(sol, j.second);
        }
    }
    cout << max(2, sol) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
