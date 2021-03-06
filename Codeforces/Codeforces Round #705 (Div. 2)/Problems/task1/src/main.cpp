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
        int n, k;
        cin >> n >> k;
        vector<int> sol;
        for (int i = k + 1; i <= n; ++i) {
            sol.push_back(i);
        }
        for (int i = (k - 1) / 2 + 1; i < k; ++i) {
            sol.push_back(i);
        }
        if (sol.empty()) {
            cout << 0 << "\n";
        } else {
            cout << sol.size() << "\n";
            for (int i = 0; i < sol.size() - 1; ++i) {
                cout << sol[i] << " ";
            }
            cout << sol[sol.size() - 1] << "\n";
        }
    }
    return 0;
}
