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
const double PI = acos((double) -1);
struct chash {                                       /// use most bits rather than just the lowest ones
    const uint64_t C = (long long) (2e18 * PI) + 71; // large odd number
    const int RANDOM = rng();
    long long operator()(long long x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x ^ RANDOM) * C);
    }
};

int main() {
    setIO("25");
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    gp_hash_table<int, queue<int>, chash> occ({}, {}, {}, {}, {1 << 10});
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]].push(i);
    }
    for (int i = 0; i < n; ++i) {
        occ[a[i]].pop();
        if (occ[a[i]].empty()) {
            occ.erase(a[i]);
        }
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < j; ++k) {
                auto it = occ.find(x - (a[i] + a[j] + a[k]));
                if (it != occ.end()) {
                    cout << k + 1 << " " << j + 1 << " " << i + 1 << " " << it->second.front() + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
