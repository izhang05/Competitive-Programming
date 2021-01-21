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
const int maxn = 1e5 + 5, mod = 1e9 + 7;
vector<int> adj[maxn];
pair<int, int> down[maxn], up[maxn];
// <black, white>
#define black first
#define white second

void dfs1(int node, int p) {
    down[node] = {1, 1};
    for (int i : adj[node]) {
        if (i != p) {
            dfs1(i, node);
            down[node].black = ((long long) down[node].black * (down[i].black + down[i].white)) % mod;
            down[node].white = ((long long) down[node].white * down[i].white) % mod;
        }
    }
}

void dfs2(int node, int p) {
    up[node] = {}
}


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0, -1);
    return 0;
}
