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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("15.out", "w", stdout);
    freopen("15.in", "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;


int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n + 1; ++i) {
        dp[i] = inf;
    }
    dp[0] = -inf;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if (it != dp.end()) {
            dp[it - dp.begin()] = a[i];
        }
        //        for (int len = 1; len < n + 1; ++len) {
        //            if (dp[len - 1] < a[i] && a[i] < dp[len]) {
        //                dp[len] = a[i];
        //            }
        //        }
    }
    int sol = 0;
    for (int i = 0; i < n + 1; ++i) {
        if (dp[i] != inf) {
            sol = i;
        }
    }
    cout << sol << "\n";
    return 0;
}
