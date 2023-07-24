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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int mxv = 1e5 + 1;
long long dp[mxv];
const long long inf = 1e18;

int main() {
    setIO();
    for (long long &i : dp) {
        i = inf;
    }
    int n, w;
    cin >> n >> w;
    dp[0] = 0;
    int weight, val;
    for (int i = 0; i < n; ++i) {
        cin >> weight >> val;
        for (int j = mxv - val - 1; j >= 0; --j) {
            dp[j + val] = min(dp[j + val], dp[j] + weight);
        }
    }
    for (int i = mxv - 1; i >= 0; --i) {
        if (dp[i] <= w) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
