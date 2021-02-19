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
    freopen("1.in", "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e3 + 10;
int parent[maxn], depth[maxn];

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
        depth[yroot] = max(depth[yroot], depth[xroot] + 1);
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

struct circle {
    int x, y, r;

    double dist(circle a) const {
        return sqrt((long long) (this->x - a.x) * (this->x - a.x) + (long long) (this->y - a.y) * (this->y - a.y)) -
               this->r - a.r;
    }
};

// 0: bottom, 1: right, 2: top, 3: left


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    int w, h;
    cin >> w >> h;
    vector<circle> trees(n), visitors(m);
    for (int i = 0; i < n; ++i) {
        cin >> trees[i].x >> trees[i].y >> trees[i].r;
    }
    int a;
    for (int i = 0; i < m; ++i) {
        cin >> a >> visitors[i].r;

    }
    return 0;
}
