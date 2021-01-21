/*
ID: izhang01
TASK: sleepy
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int k = 0;
    indexed_set<int> nums;
    for (int i = n - 1; i >= 1; --i) {
        nums.insert(a[i]);
        if (a[i] < a[i - 1]) {
            k = i;
            break;
        }
    }
    cout << k << "\n";
    for (int i = 0; i < k; ++i) {
        cout << n - nums.size() + nums.order_of_key(a[i]) - 1;
        if (i != k - 1) {
            cout << " ";
        }
        nums.insert(a[i]);
    }
    cout << "\n";
    return 0;
}
