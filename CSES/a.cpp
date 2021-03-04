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
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    setIO();

    long long n, m, k;
    cin >> n >> m >> k;
    if (k <= n - 1) {
        cout << k + 1 << " " << 1 << "\n";
        return 0;
    }
    k -= n - 1;
    cout << n - (k - 1) / (m - 1) << " ";
    long long sol = (k) % (m - 1);
    if (sol == 0) {
        sol += m - 1;
    }
    if ((k - 1) / (m - 1) % 2 == 0) {
        cout << 1 + sol << "\n";
    } else {
        cout << m - sol + 1 << "\n";
    }

#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
