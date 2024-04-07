#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxn = 2e3 + 5, mxk = 30;
long long dp[mxn][mxk], cost[mxn][mxn];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        indexed_set<pair<int, int>> cur;
        cur.insert({a[i], i});
        int pre = a[i];
        long long c = 0;
        for (int j = i + 1; j < n; ++j) {
            cur.insert({a[j], j});
            int cnt = int(cur.size());
            int med = cur.find_by_order(cnt / 2)->first;

            long long diff = med - pre;
            c += diff * (cnt / 2);
            c -= diff * (cnt - cnt / 2 - 1);
            c += abs(med - a[j]);
            cost[i][j] = c;
            pre = med;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int l = 0; l < i; ++l) {
                dp[i][j] = min(dp[i][j], dp[l][j - 1] + cost[l][i - 1]);
            }
        }
    }
    cout << dp[n][k] << "\n";
}