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

long long solve(long long x, long long y) {
    long long sol = 0;
    for (int i = 1; i < y; ++i) {
        long long cur = (long long) i * (long long) (i + 2);
//        cout << x << " " << cur << " " << i << "\n";
        if (cur > x) {
            break;
        }
        sol += min((x - cur) / i + 1, y - i);
    }
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
//        if (x < y) {
//            swap(x, y);
//        }
        cout << solve(x, y) << "\n";
    }
    return 0;
}
