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
const int maxn = 3e3 + 2;
pair<int, pair<int, int>> dp[maxn][maxn];

int main() {
    setIO();

    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], make_pair(dp[i][j].first + 1, make_pair(i, j)));
            }
            dp[i + 1][j] = max(dp[i + 1][j], make_pair(dp[i][j].first, make_pair(i, j)));
            dp[i][j + 1] = max(dp[i][j + 1], make_pair(dp[i][j].first, make_pair(i, j)));
        }
    }
    string sol;
    pair<int, int> cur = dp[n][m].second;
    while(sol.size() < dp[n][m].first) {
        if (a[cur.first] == b[cur.second]) {
            sol += a[cur.first];
        }
        cur = dp[cur.first][cur.second].second;
    }
    reverse(sol.begin(), sol.end());
    cout << sol << "\n";
    return 0;
}
