#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    setIO("17");
    int n, k;
    cin >> n >> k;
    indexed_set<int> nums;
    for (int i = 1; i < n + 1; ++i) {
        nums.insert(i);
    }
    int ind = 0;
    while (!nums.empty()) {
        int rem = int(nums.size());
        ind = (ind + k) % rem;
        auto it = nums.find_by_order(ind);
        cout << *it << " ";
        nums.erase(it);
    }
    cout << "\n";
    return 0;
}
