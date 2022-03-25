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
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 501;
int dp[maxn][maxn];


int main() {
    setIO();

    int a, b;
    cin >> a >> b;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i < max(a, b) + 1; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 1; i < a + 1; ++i) {
        for (int j = 1; j < b + 1; ++j) {
            int &cur = dp[i][j];
            for (int k = 1; k < i; ++k) {
                cur = min(cur, dp[k][j] + dp[i - k][j] + 1);
            }
            for (int k = 1; k < j; ++k) {
                cur = min(cur, dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[a][b] << "\n";
    return 0;
}
