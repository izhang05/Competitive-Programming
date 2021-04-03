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
    cin.exceptions(istream::failbit);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    set<pair<int, int>> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        if (i != 0) {
            nums.insert({a[i].first, i});
        }
    }
    int cur = 0, sol = 0;
    while (!nums.empty()) {
        auto it = nums.lower_bound({a[cur].first + a[cur].second, -inf});
        if (it == nums.end()) {
            --it;
        }
        int nex = it->second;
        nums.erase(it);
        sol += max(a[cur].second, a[nex].first - a[cur].first);
//        cout << cur << " " << nex << " " << max(a[cur].second, a[nex].first - a[cur].first) << "\n";
        cur = nex;
    }
    sol += max(a[cur].second, a[0].first - a[cur].first);
    cout << sol << "\n";
    return 0;
}
