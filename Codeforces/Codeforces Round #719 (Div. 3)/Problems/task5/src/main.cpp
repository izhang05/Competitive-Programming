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
#define int long long
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = inf, r = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                l = min(l, i);
                r = max(r, i);
            }
        }
        int lc = 1, rc = 1, sol = 0;
        while (r - 1 >= 0 && s[r - 1] == '*') {
            --r;
            ++rc;
        }
        while (l + 1 < n && s[l + 1] == '*') {
            ++l;
            ++lc;
        }
        while (l < r) {
            if (lc <= rc) {
                ++l;
                sol += lc;
                if (s[l] == '*') {
                    ++lc;
                }
                while (l + 1 < n && s[l + 1] == '*') {
                    ++l;
                    ++lc;
                }
            } else {
                --r;
                sol += rc;
                if (s[r] == '*') {
                    ++rc;
                }
                while (r - 1 >= 0 && s[r - 1] == '*') {
                    --r;
                    ++rc;
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
