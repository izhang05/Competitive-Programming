/*
ID: izhang01
TASK: promote
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //    cin.exceptions(istream::failbit);
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
}
//#define DEBUG
const int maxn = 1e5 + 5;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, a[maxn], sol[maxn];
vector<int> adj[maxn];

indexed_set<int> dfs(int c, int p) {
    indexed_set<int> cur;
    for (int i : adj[c]) {
        if (i != p) {
            indexed_set<int> merge = dfs(i, c);
            if (merge.size() > cur.size()) {
                cur.swap(merge);
            }
            for (int j : merge) {
                cur.insert(j);
            }
        }
    }
#ifdef DEBUG
    cout << c << "\n";
    for (int i : cur) {
        cout << i << " ";
    }
    cout << "\n\n";
#endif
    sol[c] = cur.size() - cur.order_of_key(a[c]);
    cur.insert(a[c]);
    return cur;
}

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int b;
        cin >> b;
        --b;
        adj[i].push_back(b);
        adj[b].push_back(i);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << "\n";
    }
#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
