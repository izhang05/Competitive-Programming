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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, r;
    cin >> l >> r;
    int paths = r - l + 1;
    if (paths > 30) {
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    if (l == r) {
        cout << 2 << " " << 1 << "\n";
        cout << 1 << " " << 2 << " " << l << "\n";
        return 0;
    }
    cout << paths + 2 << " " << paths * 2 << "\n";
    for (int i = 2; i < paths + 2; ++i) {
        cout << 1 << " " << i << " " << 1 << "\n";
        cout << i << " " << paths + 2 << " " << i - 3 + l << "\n";
    }
    return 0;
}
