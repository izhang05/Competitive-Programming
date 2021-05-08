#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T>
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int dp[1 << 20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) {
                    int nex = mask | (1 << i);
                    if (i + 2 < n) {
                        if (mask & (1 << (i + 2))) {
                            nex |= 1 << (i + 1);
                        }
                    }
                    if (i - 2 >= 0) {
                        if (mask & (1 << (i - 2))) {
                            nex |= 1 << (i - 1);
                        }
                    }
                    dp[nex] += dp[mask];
                }
            }
        }
        cout << dp[(1 << n) - 1] << "\n";
    }
    return 0;
}

