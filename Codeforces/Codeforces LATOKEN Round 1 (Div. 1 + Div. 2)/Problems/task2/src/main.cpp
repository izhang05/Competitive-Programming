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
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int sol = 0;
        for (int i = 0; i < n; ++i) {
            int left;
            if (i > 0) {
                left = a[i - 1];
            } else {
                left = 0;
            }
            int right;
            if (i < n - 1) {
                right = a[i + 1];
            } else {
                right = 0;
            }
            if (a[i] > left && a[i] > right) {
                int next = max(left, right);
                sol += a[i] - next;
                a[i] = next;
            }
        }
        int pre = 0;
        for (int i = 0; i < n; ++i) {
            sol += abs(a[i] - pre);
            pre = a[i];
        }
        cout << sol + a[n - 1] << "\n";
    }
    return 0;
}
