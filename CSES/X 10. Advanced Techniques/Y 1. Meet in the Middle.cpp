#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
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

int main() {
    setIO("1");
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    gp_hash_table<long long, long long, chash> cnt;
    for (int i = 0; i < 1 << (n / 2); ++i) {
        long long cur = 0;
        for (int j = 0; j < n / 2; ++j) {
            if (i & (1 << j)) {
                cur += a[j];
            }
        }
        ++cnt[cur];
    }
    long long sol = 0;
    for (int i = 0; i < 1 << (n - n / 2); ++i) {
        long long cur = 0;
        for (int j = 0; j < n - n / 2; ++j) {
            if (i & (1 << j)) {
                cur += a[j + n / 2];
            }
        }
        sol += cnt[x - cur];
    }
    cout << sol << "\n";
    return 0;
}
