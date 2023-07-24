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
const int maxn = 405;
const long long inf = 1e18;
long long dp[maxn][maxn]; // dp[i][j] = cost of combining interval [i - j] into one


int main() {
    setIO();
    int n;
    cin >> n;
    vector<long long> pre(n + 1, 0);
    int a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = inf;
        }
        cin >> a;
        dp[i][i] = 0;
        pre[i + 1] = pre[i] + a;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + pre[j + 1] - pre[i]);
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
    return 0;
}
