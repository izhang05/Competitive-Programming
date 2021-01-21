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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int maxn = 2e5 + 5;
int n, tin[maxn], tour_n, node[2 * maxn];
vector<int> child[maxn];

long long t[4 * maxn];

long long calc(long long a, long long b) {
    return min(a, b);
}

void build() {
    for (int i = tour_n - 1; i > 0; --i) {
        t[i] = calc(t[2 * i], t[2 * i + 1]);
    }
}

void update(int p, long long val) {
    for (t[p += tour_n] = val; p > 1; p /= 2) {
        t[p / 2] = calc(t[p], t[p ^ 1]); // p ^ 1 is the other child for node p / 2
    }
}

long long query(int l, int r) {
    long long res = 0;
    for (l += tour_n, r += tour_n; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res = calc(res, t[l++]);
        }
        if (r & 1) {
            res = calc(res, t[--r]);
        }
    }
    return res;
}

int ind = 0;
void dfs(int cur, int parent) {
    tin[cur] = ind;
    update(ind++, cur);
    for (int i : child[cur]) {
        if (i != (parent)) {
            dfs(i, cur);
            update(ind++, cur);
        }
    }
}


int main() {
    setIO();
    int q;
    cin >> n >> q;
    tour_n = 2 * n - 1;
    int a;
    for (int i = 1; i < n; ++i) {
        cin >> a;
        child[a - 1].push_back(i);
    }
    dfs(0, -1);
    return 0;
}
