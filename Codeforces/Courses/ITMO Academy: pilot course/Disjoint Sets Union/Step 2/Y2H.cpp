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
    freopen("H.in", "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e4 + 5;

struct edge {
    int dist, a, b, ind;
    bool operator<(const edge &rhs) const {
        return this->dist < rhs.dist;
    }
};

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
    long long s;
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    vector<edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].dist;
        edges[i].ind = i + 1;
        --edges[i].a, --edges[i].b;
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    comps = n - 1;
    vector<edge> unused;
    for (int i = 0; i < m; ++i) {
        if (comps && merge(edges[i].a, edges[i].b)) {
            --comps;
        } else {
            unused.push_back(edges[i]);
        }
    }
    sort(unused.begin(), unused.end());
    long long used = 0;
    vector<int> sol;
    for (edge i : unused) {
        if (used + i.dist > s) {
            break;
        }
        sol.push_back(i.ind);
        used += i.dist;
    }

    cout << sol.size() << "\n";
    print(sol);
    return 0;
}
