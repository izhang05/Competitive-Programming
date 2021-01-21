/*
ID: izhang01
TASK: bphoto
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int>> diff(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int t = 0; t < 2; ++t) {
        indexed_set<int> nums;
        for (int i = 0; i < n; ++i) {
            if (t == 0) {
                diff[i].first = i - nums.order_of_key(a[i]);
            } else {
                diff[n - i - 1].second = i - nums.order_of_key(a[i]);
            }
            nums.insert(a[i]);
        }
        reverse(a.begin(), a.end());
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        if (diff[i].first > 2 * diff[i].second || diff[i].second > 2 * diff[i].first) {
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}
