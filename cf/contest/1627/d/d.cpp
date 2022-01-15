/* Author: izhang
 * Time: 01-15-2022 09:35:01
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
    vector<int> a(n);
    vector<int> good(1e6 + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        good[a[i]] = true;
    }
    int sol = 0;
    for (int i = 1e6; i >= 1; --i) {
        if (good[i]) {
            continue;
        }
        int mx = int(1e6) / i;
        gp_hash_table<int, null_type, chash> nums;
        for (int j = 2; j <= mx; ++j) {
            nums.insert(j);
        }
        vector<int> pos(mx + 1, 1);
        int cnt = 0;
        for (int j = 2; j <= mx; ++j) {
            if (!pos[j]) {
                continue;
            }
            if (good[j * i]) {
                ++cnt;
                if (cnt == 2) {
                    break;
                }
                for (int k = j + j; k <= mx; k += j) {
                    pos[k] = false;
                }
            }
        }
        if (cnt == 2) {
            ++sol;
            good[i] = true;
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
