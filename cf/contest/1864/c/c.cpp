/* Author: izhang
 * Time: 08-26-2023 10:35:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

template<class K, class V>
using ht = gp_hash_table<
        K, V, hash<K>, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>,
        hash_standard_resize_policy<hash_exponential_size_policy<>,
                                    hash_load_check_resize_trigger<>, true>>;

ht<int, vector<int>> p({}, {}, {}, {}, {1 << 17});

void test_case() {
    int x;
    cin >> x;
    vector<int> sol{x};
    int init = x;
    multiset<int> f;
    while (x % 2 == 0) {
        f.insert(2);
        x /= 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            f.insert(i);
            x /= i;
        }
    }
    if (x != 1) {
        f.insert(x);
    }
    x = init;
    while (x != 1) {
        auto it = f.begin();
        int val = *it;
        f.erase(it);
        x /= val;
        x *= val - 1;
        sol.push_back(x);
        if (p.find(val) == p.end()) {
            vector<int> cur;
            int tmp = val;
            --tmp;
            while (tmp % 2 == 0) {
                cur.push_back(2);
                tmp /= 2;
            }
            for (int i = 3; i * i <= tmp; i += 2) {
                while (tmp % i == 0) {
                    cur.push_back(i);
                    tmp /= i;
                }
            }
            if (tmp != 1) {
                cur.push_back(tmp);
            }
            p[val] = cur;
        }
        for (auto &i : p[val]) {
            f.insert(i);
        }
        dbg() << x;
        dbg() << f;
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i << " ";
    }
    cout << "\n";
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
