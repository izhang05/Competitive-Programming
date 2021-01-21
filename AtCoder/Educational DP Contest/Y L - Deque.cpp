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
}
const int maxn = 3e3;
long long dp[maxn][maxn]; // dp[left][right]

int main() {
    setIO();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (n % 2 == 0) {
            dp[i][i] = -a[i];
        } else {
            dp[i][i] = a[i];
        }
    }
    for (int len = 1; len < n; ++len) {
        int r = len;
        for (int l = 0; r < n; ++l, ++r) {
            if ((len + 1) % 2 == n % 2) { // player 1 turn
                dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r]);
            } else {
                dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r]);
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
    return 0;
}
