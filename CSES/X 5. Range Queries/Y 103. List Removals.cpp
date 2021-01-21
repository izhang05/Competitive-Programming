#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


int main() {
    setIO();
    int n;
    cin >> n;
    int a;
    indexed_set<pair<int, int>> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        nums.insert(make_pair(i, a));
    }
    for (int i = 0; i < n; ++i) {
        cin >> a;
        --a;
        auto it = nums.find_by_order(a);
        cout << it->second << " ";
        nums.erase(it);
    }
    return 0;
}
