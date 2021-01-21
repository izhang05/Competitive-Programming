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
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    setIO();

    int n, a, b, x;
    cin >> n >> a >> b;
    vector<long long> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        pre[i + 1] = pre[i] + x;
    }
    multiset<long long> cur;
    long long sol = -1e18;
    for (int i = a - 1; i < n; ++i) {
        cur.insert(pre[i - a + 1]);
        if (i - b >= 0) {
            cur.erase(cur.find(pre[i - b]));
        }
        sol = max(sol, pre[i + 1] - *cur.begin());
    }
    cout << sol << "\n";
    return 0;
}
