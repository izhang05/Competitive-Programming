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


int main() {
    setIO();

    int n, q;
    cin >> n >> q;
    indexed_set<int> nums;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nums.insert(a[i]);
    }
    char b;
    int c, d;
    for (int i = 0; i < q; ++i) {
        cin >> b >> c >> d;
        if (b == '!') {
            nums.erase(nums.upper_bound(a[c - 1]));
            a[c - 1] = d;
            nums.insert(d);
        } else {
            cout << nums.order_of_key(d + 1) - nums.order_of_key(c) << "\n";
        }
    }
    return 0;
}
