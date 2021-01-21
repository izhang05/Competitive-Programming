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
    freopen("1.in", "r", stdin);
}


int main() {
    setIO();
    unordered_set<int> nums;
    int a;
    while (cin >> a) {
        if (nums.find(2020 - a) != nums.end()) {
            cout << a * (2020 - a) << "\n";
            return 0;
        }
        nums.insert(a);
    }
    return 0;
}
