#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    setIO();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Tree<int> tr;
        long long sol = 0;
        int a;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            sol += i - (long long) tr.order_of_key(a);
            tr.insert(a);
        }
        cout << sol << "\n";
    }
    return 0;
}
