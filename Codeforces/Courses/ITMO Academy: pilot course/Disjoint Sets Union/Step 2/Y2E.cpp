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
    freopen("E.in", "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
int parent[maxn], depth[maxn], comps;

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (depth[xroot] > depth[yroot]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        parent[xroot] = yroot;
        depth[yroot] += depth[xroot];
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    comps = n;
    vector<pair<int, pair<int, int>>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        --edges[i].second.first, --edges[i].second.second;
    }
    sort(edges.begin(), edges.end());
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    for (pair<int, pair<int, int>> i : edges) {
        if (merge(i.second.first, i.second.second)) {
            --comps;
            sol += i.first;
        }
        if (!comps) {
            break;
        }
    }
    cout << sol << "\n";
    return 0;
}
