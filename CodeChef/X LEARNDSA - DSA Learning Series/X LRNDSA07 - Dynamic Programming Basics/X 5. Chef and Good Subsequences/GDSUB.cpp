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
//freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxk = 1010;

int dp[maxn][maxk], pre[maxn][maxk];

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][1] = 1;
        pre[i][1] = i + 1;
    }
    sort(a.begin(), a.end());
    int sol = 1;
    for (int i = 1; i < n; ++i) {
        int lo = 0, hi = i - 1, mid, res = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (a[mid] != a[i]) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (res != -1) {
            for (int j = 2; j < k + 1; ++j) {
                dp[i][j] += pre[res][j - 1];
                pre[i][j] = pre[i - 1][j] + dp[i][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k + 1; ++j) {
            cout << dp[i][j] << " ";
            sol += dp[i][j];
        }
        cout << "\n";
    }
    cout << sol << "\n";
    return 0;
}
