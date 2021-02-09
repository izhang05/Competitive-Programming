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
    set<pair<int, int>> s; // {num, ind}
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        s.insert({nums[i], i});
    }
    pair<int, int> a, b; // {num_elements, last}
    a = {0, -1}, b = {0, -1};
    for (int i = 0; i < n; ++i) {
        if (a.second == nums[i] || b.second == nums[i]) {
        } else {
            if (a.second != nums[i] && b.second != nums[i]) {
                auto it_a = s.upper_bound({a.second, i}), it_b = s.upper_bound({b.second, i});
                bool want_a = !(it_a == s.end() || it_a->first != a.second);
                bool want_b = !(it_b == s.end() || it_b->first != b.second);
                if (want_a) {
                    if (want_b) {
                        if (it_a->second < it_b->second) {
                            ++b.first;
                            b.second = nums[i];
                        } else {
                            ++a.first;
                            a.second = nums[i];
                        }
                    } else {
                        ++b.first;
                        b.second = nums[i];
                    }
                } else {
                    ++a.first;
                    a.second = nums[i];
                }
            }
        }
    }
    cout << a.first + b.first << "\n";
    return 0;
}
