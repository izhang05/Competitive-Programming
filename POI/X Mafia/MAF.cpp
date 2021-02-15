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
    cin.exceptions(cin.failbit);
#ifdef LOCAL
    freopen("MAF.in", "r", stdin);
    freopen("MAF.out", "w", stdout);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
int out[maxn], deg[maxn];
vector<int> in[maxn];

int main() {
#ifdef LOCAL
    auto start_time = std::chrono::high_resolution_clock::now();
#endif
    setIO();
    int n;
    cin >> n;
    int a;
    for (int i = 1; i < n + 1; ++i) {
        cin >> a;
        out[i] = a;
        in[a].push_back(i);
    }


#ifdef LOCAL
    auto end_time = std::chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
