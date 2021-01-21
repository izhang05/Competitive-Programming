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
#ifdef DEBUG
    freopen("1.in", "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    setIO();
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> sol(n), ways(n);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        j = max(j, i);
        while (j + 1 < n && a[j + 1] - a[i] <= d) {
            ++j;
            ways[j] = n - j - 1 + j - i;
        }
        if (!ways[i]) {
            ways[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << i << " " << ways[i] << "\n";
    }
    cout << "\n";
    sol[0] = 1;
    for (int i = 1; i < n; ++i) {
        sol[i] = sol[i - 1] * ways[i];
        sol[i] %= mod;
        cout << i << " " << sol[i] << "\n";
    }
    cout << sol[n - 1] << "\n";
    return 0;
}
