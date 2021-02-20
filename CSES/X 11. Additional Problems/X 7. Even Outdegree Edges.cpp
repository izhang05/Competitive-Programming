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
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("7.in", "r", stdin);
    freopen("7.out", "w", stdout);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<int> adj[maxn];
int deg[maxn];

int main() {
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    setIO();
    int n, m;
    cin >> n >> m;
    if (m % 2 == 1) {
        cout << "IMPOSSIBLE"
             << "\n";
        return 0;
    }
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++deg[a];
        ++deg[b];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;


#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
