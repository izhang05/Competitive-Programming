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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
//freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    setIO();
    int n;
    cin >> n;
    long long sol = 0;
    vector<int> h(n), w(n);
    long long len = 0;
    long long last = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        len += w[i];
        if (h[i] == 2) {
            last += w[i];
        } else {
            if (last) {
                sol += ((long long) last * (last + 1)) % mod;
                last = 0;
            }
        }
    }
    if (last) {
        sol += ((long long) last * (last + 1)) % mod;
    }
    len %= mod;
    sol += (((long long) len * (len + 1)) / 2) % mod;
    cout << sol % mod << "\n";
    return 0;
}
