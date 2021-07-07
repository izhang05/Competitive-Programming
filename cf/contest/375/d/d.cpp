/* Author: izhang05
 * Time: 07-06-2021 21:18:15
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
int c[maxn], sol[maxn];
vector<int> adj[maxn];
vector<pair<int, int>> q[maxn];
unordered_map<int, int> occ[maxn];
indexed_set<pair<int, int>> cnt[maxn];

void dfs(int node, int p) {
    occ[node][c[node]] = 1;
    cnt[node].insert({1, c[node]});
    for (auto &i : adj[node]) {
        if (i != p) {
            dfs(i, node);
            if (occ[i].size() > occ[node].size()) {
                occ[i].swap(occ[node]);
                cnt[i].swap(cnt[node]);
            }
            for (auto &j : occ[i]) {
                int v = occ[node][j.first];
                if (v) {
                    cnt[node].erase({v, j.first});
                }
                occ[node][j.first] += j.second;
                cnt[node].insert({v + j.second, j.first});
            }
            occ[i].clear();
            cnt[i].clear();
        }
    }
    for (auto &i : q[node]) {
        sol[i.second] = int(cnt[node].size()) - cnt[node].order_of_key({i.first, -inf});
    }
}

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        int v, k;
        cin >> v >> k;
        --v;
        q[v].emplace_back(k, i);
    }
    dfs(0, -1);
    for (int i = 0; i < m; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
