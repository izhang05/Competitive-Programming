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
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        int sol = n + m;
        for (int i = 0; i < n; ++i) {
            string cur_a = "";
            cur_a += a[i];
            for (int j = i; j < n; ++j) {
                if (j != i) {
                    cur_a += a[j];
                }
                for (int k = 0; k < m; ++k) {
                    string cur_b = "";
                    cur_b += b[k];
                    for (int l = k; l < m; ++l) {
                        if (l != k) {
                            cur_b += b[l];
                        }
                        if (cur_a == cur_b) {
                            sol = min(sol, n - (j - i + 1) + m - (l - k + 1));
                        }
                    }
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
