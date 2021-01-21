#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
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

int main() {
    int n, k;
    cin >> n >> k;
    indexed_set<pair<int, int>> nums;
    vector<int> a(n);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        nums.insert({a[i], i});
    }
    cout << nums.find_by_order((k - 1) / 2)->first << " ";
    for (int i = k; i < n; ++i) {
        cin >> a[i];
        nums.erase(nums.find({a[i - k], i - k}));
        nums.insert({a[i], i});
        cout << nums.find_by_order((k - 1) / 2)->first << " ";
    }
    return 0;
}