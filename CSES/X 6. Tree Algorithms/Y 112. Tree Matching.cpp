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
const int maxn = 2e5;
int dp[maxn][2];
vector<int> adj[maxn];

void sol(int n, int p) {
    for (int i : adj[n]) {
        if (i != p) {
            sol(i, n);
            dp[n][0] += max(dp[i][0], dp[i][1]);
        }
    }
    for (int i : adj[n]) {
        if (i != p) {
            dp[n][1] = max(dp[n][1], dp[i][0] + 1 + dp[n][0] - max(dp[i][0], dp[i][1]));
        }
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sol(0, -1);
    cout << max(dp[0][0], dp[0][1]) << "\n";
    return 0;
}
