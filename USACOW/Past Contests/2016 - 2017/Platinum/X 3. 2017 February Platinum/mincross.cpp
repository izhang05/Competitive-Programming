/*
ID: izhang01
TASK: mincross
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mincross.in", "r", stdin);
    freopen("mincross.out", "w", stdout);
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
    vector<int> a(n), b(n), index(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        index[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    long long sol = 0;
    indexed_set<long long> nums;
    for (int i = 0; i < n; ++i) {
        sol += nums.size() - nums.order_of_key(index[b[i]]);
        nums.insert(index[b[i]]);
    }
    cout << sol << "\n";
    long long cur = sol;
    for (int i = 0; i < n; ++i) {
        cur -= nums.order_of_key(index[b[i]]);
        cur += nums.size() - nums.order_of_key(index[b[i]]) - 1;
        sol = min(cur, sol);
        cout << cur << "\n";
    }
    assert(sol >= 0);
    cout << sol << "\n";
    return 0;
}
