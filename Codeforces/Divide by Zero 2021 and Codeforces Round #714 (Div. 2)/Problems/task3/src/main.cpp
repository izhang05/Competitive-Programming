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
long long dp[10][maxn];

long long solve(int n, int m) {
    if (dp[n][m]) {
        return dp[n][m];
    }
    if (n != 9) {
        return dp[n][m] = solve(n + 1, m - 1);
    } else {
        return dp[n][m] = (solve(0, m - 1) + solve(1, m - 1)) % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    for (auto &i : dp) {
        i[0] = 1;
    }
    while (t--) {
        int n, m;
        cin >> n >> m;
        long long sol = 0;
        while (n) {
            sol += solve(n % 10, m);
            n /= 10;
            sol %= mod;
        }
        cout << sol << "\n";
    }
    return 0;
}
