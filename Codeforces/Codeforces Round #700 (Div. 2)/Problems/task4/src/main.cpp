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
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    set<int> duplicates;
    int pre = 0;
    for (int i = 1; i < n; ++i) {
        if (nums[i] == nums[pre]) {
            if (pre == i - 1) {
                duplicates.insert(pre);
            }
        } else {
            pre = i;
        }
    }

    pair<int, int> a, b; // {num_elements, last}
    int sol = a.first + b.first;
    a = {0, -1}, b = {0, -1};
    for (int i = 0; i < n; ++i) {
        if (a.second != nums[i] && b.second != nums[i]) {
            auto it = duplicates.lower_bound(i);
            if (it != duplicates.end() && b.second == nums[*it]) {
                ++b.first;
                b.second = nums[i];
            } else {
                ++a.first;
                a.second = nums[i];
            }

        } else {
            if (a.second != nums[i]) {
                ++a.first;
                a.second = nums[i];
            } else if (b.second != nums[i]) {
                ++b.first;
                b.second = nums[i];
            }
        }
    }
    cout << max(sol, a.first + b.first) << "\n";
    return 0;
}