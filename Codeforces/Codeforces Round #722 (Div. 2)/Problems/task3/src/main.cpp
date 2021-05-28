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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;

vector<int> adj[maxn];
long long l[maxn], r[maxn], dp[maxn][2];

void dfs(int c, int p) {
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            dp[c][0] += max(dp[i][0] + abs(l[c] - l[i]), dp[i][1] + abs(l[c] - r[i]));
            dp[c][1] += max(dp[i][0] + abs(r[c] - l[i]), dp[i][1] + abs(r[c] - r[i]));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                dp[i][j] = 0;
            }
            adj[i].clear();
            cin >> l[i] >> r[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0, -1);
        cout << max(dp[0][0], dp[0][1]) << "\n";
    }
    return 0;
}
