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
    cout << setprecision(18) << fixed;
#ifdef LOCAL
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 9;


int main() {
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    setIO();
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long sol = 1;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        while (a[r] - a[l] > d) {
            ++l;
        }
        sol = (sol * (r - l + 1)) % mod;
    }
    cout << sol << "\n";
#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count()
         << " seconds" << endl;
#endif
    return 0;
}
