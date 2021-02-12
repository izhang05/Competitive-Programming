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
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("Y 6.in", "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
int parent[maxn];
bool visited[maxn];
vector<int> adj[maxn];
bool solved;


void dfs(int node, int p) {
    visited[node] = true;
    for (int i : adj[node]) {
        if (visited[i]) {
            if (i != p) {
                solved = true;
                vector<int> path_node, path_i;
                while (parent[node] != node) {
                    path_node.push_back(node);
                    node = parent[node];
                }
                path_node.push_back(node);
                while (parent[i] != i) {
                    path_i.push_back(i);
                    i = parent[i];
                }
                path_i.push_back(i);
                reverse(path_node.begin(), path_node.end());
                reverse(path_i.begin(), path_i.end());
                int lo = 0, hi = (int) min(path_node.size(), path_i.size()) - 1, mid, res = -1;
                while (lo <= hi) {
                    mid = (lo + hi) / 2;
                    if (path_node[mid] == path_i[mid]) {
                        res = mid;
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
//                print(path_node);
//                print(path_i);
//                cout << res << "\n";
                vector<int> sol;
                for (int j = res; j < path_node.size(); ++j) {
                    sol.push_back(path_node[j] + 1);
                }
                for (int j = (int) path_i.size() - 1; j >= res; --j) {
                    sol.push_back(path_i[j] + 1);
                }
                cout << sol.size() << "\n";
                print(sol);
                return;
            }
        } else {
            parent[i] = node;
            dfs(i, node);
            if (solved) {
                return;
            }
        }
    }
}

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            parent[i] = i;
            dfs(i, -1);
        }
        if (solved) {
            break;
        }
    }
    if (!solved) {
        cout << "IMPOSSIBLE"
             << "\n";
    }
    return 0;
}
