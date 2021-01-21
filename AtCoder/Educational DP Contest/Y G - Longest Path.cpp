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

const int maxn = 1e5;
vector<int> adj[maxn];
int dp[maxn], in_deg[maxn];

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        ++in_deg[b];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (!in_deg[i]) {
            q.push(i);
        }
    }
    int sol = 0;
    while (!q.empty()) {
        int cur = q.front();
        sol = max(sol, dp[cur]);
        q.pop();
        for (int i : adj[cur]) {
            if (--in_deg[i] == 0) {
                q.push(i);
                dp[i] = max(dp[i], dp[cur] + 1);
            }
        }
    }

    cout << sol << "\n";
    return 0;
}
