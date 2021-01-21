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
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 3000;
double dp[maxn][maxn];

int main() {
    setIO();

    int n;
    cin >> n;
    dp[0][0] = 1;
    vector<double> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j] * (1 - a[i - 1]);
            if (j - 1 >= 0) {
                dp[i][j] += dp[i - 1][j - 1] * a[i - 1];
            }
        }
    }
    double sol = 0;
    for (int i = n / 2 + 1; i < n + 1; ++i) {
        sol += dp[n][i];
    }
    cout << setprecision(18) << sol << "\n";
    return 0;
}
