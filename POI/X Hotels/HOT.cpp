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
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("HOT.in", "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e3 + 5;
vector<int> adj[maxn];
short num[maxn][maxn], n;


long long nCr(int a, int b) {
    return 1;
//    long long res = 1;
//    for (int i = a - b + 1; i < a + 1; ++i) {
//        res *= i;
//    }
//    for (int i = 2; i < b + 1; ++i) {
//        res /= i;
//    }
//    return res;
}

void dfs(int node, int parent, int root, int depth) {
    ++num[root][depth];
    for (int i : adj[node]) {
        if (i != parent) {
            dfs(i, node, root, depth + 1);
        }
    }
}

int main() {
    setIO();
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //    for (int i = 0; i < n; ++i) {
    //        cout << i << "\n";
    //        print(adj[i]);
    //        cout << "\n";
    //    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        memset(num, 0, sizeof(num));
        vector<int> children = adj[i];
        if (children.size() < 3) {
            continue;
        }
        for (int j : adj[i]) {
            dfs(j, i, j, 0);
        }
        for (int depth = 0; depth < n; ++depth) {
            vector<int> counts, erase;
            for (int j : children) {
                if (!num[j][depth]) {
                    erase.push_back(j);
                } else {
                    counts.push_back(num[j][depth]);
                }
            }
            for (int j : erase) {
                children.erase(find(children.begin(), children.end(), j));
            }
            if (counts.size() < 3) {
                break;
            }
            long long cur = nCr(counts.size(), 3);
            for (int j : counts) {
                cur *= j;
            }
            //            cout << i << " " << cur << "\n";
            sol += cur;
        }
    }
    cout << sol << "\n";
    return 0;
}
