/* Author: izhang
 * Time: 03-17-2022 22:10:22
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5, maxg = 25;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int f[maxn], cnt[maxg];
bool taken[maxn * maxg];

void test_case() {
    memset(f, -1, sizeof(f));
    for (int i = 2; i < maxn; ++i) {
        if (f[i] != -1) {
            continue;
        }
        f[i] = i;
        for (int j = i + i; j < maxn; j += i) {
            f[j] = i;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= maxg; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!taken[j * i]) {
                ++cnt[i];
                taken[j * i] = true;
            }
        }
    }
    long long sol = 0;
    for (int i = 2; i <= n; ++i) {
        map<int, int> factor;
        int cur = i;
        while (cur != 1) {
            ++factor[f[cur]];
            cur /= f[cur];
        }
        int g = factor.begin()->second;
        for (auto &j : factor) {
            g = gcd(g, j.second);
        }
        sol += cnt[g];
    }
    cout << sol + 1 << "\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
