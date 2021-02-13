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
#ifdef LOCAL
    freopen("7.in", "r", stdin);
    freopen("7.out", "w", stdout);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 100000;
int n; // The number of nodes in the adj
vector<int> adj[maxn];
int timer = 0, tin[maxn], euler_tour[2 * maxn], segtree[8 * maxn]; // Segment tree for RMQ

void dfs(int node = 0, int parent = -1) {
    tin[node] = timer; // The time when we first visit a node
    euler_tour[timer++] = node;
    for (int i : adj[node]) {
        if (i != parent) {
            dfs(i, node);
            euler_tour[timer++] = node;
        }
    }
}

int mn_tin(int x, int y) {
    if (x == -1) {
        return y;
    }
    if (y == -1) {
        return x;
    }
    return (tin[x] < tin[y] ? x : y);
}

// Build the segment tree: run `build()` after running `dfs()`
void build(int node = 1, int l = 0, int r = timer - 1) {
    if (l == r) {
        segtree[node] = euler_tour[l];
    } else {
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        segtree[node] = mn_tin(segtree[node * 2], segtree[node * 2 + 1]);
    }
}

int query(int a, int b, int node = 1, int l = 0, int r = timer - 1) {
    if (l > b || r < a) {
        return -1;
    }
    if (l >= a && r <= b) {
        return segtree[node];
    }
    int mid = (l + r) / 2;
    return mn_tin(query(a, b, node * 2, l, mid), query(a, b, node * 2 + 1, mid + 1, r));
}

// Make sure you run `dfs()` and `build()` before you run this
int lca(int a, int b) {
    if (tin[a] > tin[b]) swap(a, b);
    return query(tin[a], tin[b]);
}

int main() {
#ifdef LOCAL
    auto start_time = std::chrono::high_resolution_clock::now();
#endif
    setIO();
    int q;
    cin >> n >> q;
    int a;
    for (int i = 2; i < n + 1; ++i) {
        cin >> a;
        adj[a].push_back(i);
    }
    dfs();
    build();
    int b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
#ifdef LOCAL
    auto end_time = std::chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
