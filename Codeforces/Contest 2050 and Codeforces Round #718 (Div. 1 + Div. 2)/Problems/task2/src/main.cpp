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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105;
int grid[maxn][maxn], sol[maxn][maxn];
map<int, int> paths[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        multiset<int> nums;
        for (int i = 0; i < n; ++i) {
            paths[i].clear();
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                sol[i][j] = 0;
                ++paths[i][grid[i][j]];
                nums.insert(grid[i][j]);
            }
        }
        vector<int> cost(m);
        auto it = nums.begin();
        for (int i = 0; i < m; ++i) {
            cost[i] = *it;
            ++it;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (cost[j] != 0) {
                    if (paths[i].find(cost[j]) != paths[i].end()) {
                        sol[i][j] = cost[j];
                        if (--paths[i][cost[j]] == 0) {
                            paths[i].erase(cost[j]);
                        }
                        cost[j] = 0;
                    }
                }
            }
            vector<int> cur;
            for (auto j : paths[i]) {
                for (int k = 0; k < j.second; ++k) {
                    cur.push_back(j.first);
                }
            }
            int k = 0;
            for (int j = 0; j < m; ++j) {
                if (!sol[i][j]) {
                    sol[i][j] = cur[k++];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << sol[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
