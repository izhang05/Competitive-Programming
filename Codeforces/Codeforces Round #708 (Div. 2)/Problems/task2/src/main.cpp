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
        int m;
        cin >> m;
        vector<int> a(n);
        map<int, int> occ;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] %= m;
            ++occ[a[i]];
        }
        int sol = 0;
        if (occ[0]) {
            ++sol;
        }
        if (m % 2 == 0 && occ[m / 2]) {
            ++sol;
        }
        for (int i = 1; i + i < m; ++i) {
            int p = m - i;
            if (occ[i] > 0 || occ[p] > 0) {
                ++sol;
                int b = occ[i], c = occ[p];
                if (b < c) {
                    swap(b, c);
                }
                sol += max(0, b - c - 1);
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
