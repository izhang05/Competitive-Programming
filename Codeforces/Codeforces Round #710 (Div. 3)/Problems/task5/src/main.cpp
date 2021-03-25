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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> q(n);
        for (int i = 0; i < n; ++i) {
            cin >> q[i];
        }
        vector<int> mn(n), mx(n);
        set<int> a;
        set<int, greater<>> ag;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            if (q[i] != last) {
                mn[i] = mx[i] = q[i];
                for (int j = last + 1; j < q[i]; ++j) {
                    a.insert(j);
                    ag.insert(j);
                }
                last = q[i];
            } else {
                mn[i] = *a.begin();
                a.erase(a.begin());
                mx[i] = *ag.begin();
                ag.erase(ag.begin());
            }
        }
        print(mn);
        print(mx);
    }
    return 0;
}
