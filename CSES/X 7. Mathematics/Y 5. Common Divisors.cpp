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
const int maxn = 1e6 + 1;
int divs[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        for (int j = 1; j * j <= a; ++j) {
            if (a % j == 0) {
                ++divs[j];
                if (j != a / j) {
                    ++divs[a / j];
                }
            }
        }
    }
    for (int i = maxn; i >= 1; --i) {
        if (divs[i] >= 2) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
