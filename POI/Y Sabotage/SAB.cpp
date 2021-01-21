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
    freopen("1.in", "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5 + 5;
int parent[maxn], sub[maxn];
double need[maxn];

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    for (int i = 2; i < n + 1; ++i) {
        cin >> parent[i];
    }
    for (int i = n; i >= 1; --i) {
        ++sub[i];
        sub[parent[i]] += sub[i];
    }
    double sol = 0;
    for (int i = n; i >= 1; --i) {
        if (sub[i] == 1) { // leaf
            need[i] = 1;
        }
        need[parent[i]] = max(need[parent[i]], min(need[i], double(sub[i]) / (sub[parent[i]] - 1)));
        if (sub[i] > k) {
            sol = max(sol, need[i]);
        }
    }
    cout << fixed << setprecision(7) << sol << "\n";
    return 0;
}
