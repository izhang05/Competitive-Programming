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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e3 + 1;
long long dp[maxn][maxn];
int n, a[maxn];

long long sol(int l, int r) {
    long long &cur = dp[l][r];
    if (cur || l == r) {
        return cur;
    }
    if ((l - r) % 2 != n % 2) { // player 1's turn
        cur = max(sol(l + 1, r) + a[l], sol(l, r - 1) + a[r]);
    } else {
        cur = min(sol(l + 1, r), sol(l, r - 1));
    }
    return cur;
}

int main() {
    setIO();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            dp[i][i] = a[i];
        }
    }
    cout << sol(0, n - 1) << "\n";
    return 0;
}
