/*
ID: izhang01
TASK: haircut
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
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
    vector<long long> a(n), sol(n), larger(n + 1);
    indexed_set<pair<int, int>> nums;
    long long orig = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int cur = nums.size() - nums.order_of_key(make_pair(a[i], 1e9));
        larger[a[i]] += cur;
        orig += cur;
        nums.insert(make_pair(a[i], i));
    }
    long long cur = orig;
    for (int i = n - 1; i >= 0; --i) {
        sol[i] = cur - larger[i];
        cur -= larger[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
