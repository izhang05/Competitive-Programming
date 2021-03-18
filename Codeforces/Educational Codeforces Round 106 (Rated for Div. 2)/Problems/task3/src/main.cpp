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
        vector<long long> c(n), odd, even;
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
            if (i % 2) {
                odd.push_back(c[i]);
            } else {
                even.push_back(c[i]);
            }
        }
        vector<long long> odd_cost(odd.size()), even_cost(even.size());
        long long cur = 0, cur_sol = 1e18, cur_min = 1e18;
        for (int i = 0; i < odd.size(); ++i) {
            cur_min = min(cur_min, odd[i]);
            cur += odd[i];
            odd_cost[i] = cur + (n - i) * cur_min - cur_min;
        }
        cur = 0, cur_sol = 1e18, cur_min = 1e18;
        for (int i = 0; i < even.size(); ++i) {
            cur_min = min(cur_min, even[i]);
            cur += even[i];
            even_cost[i] = cur + (n - i) * cur_min - cur_min;
        }
        long long sol = 1e18;
//        print(even_cost);
//        print(odd_cost);
        for (int i = 0; i < odd.size(); ++i) {
            long long cur_cost =
                    odd_cost[i] + min(even_cost[i], even_cost[min((int) even.size() - 1, i + 1)]);
            sol = min(sol, cur_cost);
        }
        cout << sol << "\n";
    }
    return 0;
}

