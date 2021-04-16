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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }
        a.emplace_back(1, 1);
        sort(a.begin(), a.end());
        int last = a[0].first - a[0].second;
        long long sol = 0;
        for (int i = 1; i < n + 1; ++i) {
            int cur = a[i].first - a[i].second;
            if (cur < last) {
                assert(false);
            }
            if (cur == last && cur % 2 == 0) {
                sol += a[i].first - a[i - 1].first;
            } else if (cur > last) {
                sol += cur / 2 - last / 2;
            }
            last = cur;
        }
        cout << sol << "\n";
    }
    return 0;
}
