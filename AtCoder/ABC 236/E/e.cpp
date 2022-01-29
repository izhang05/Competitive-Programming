/* Author: izhang
 * Time: 01-29-2022 16:37:41
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long double dp1[maxn][2];
long long dp[maxn][2];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less < T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
vector<int> a;

bool check1(long double x) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp1[i][j] = -INFL;
        }
    }
    dp1[0][1] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp1[i + 1][1] = max(dp1[i + 1][1], dp1[i][j] + a[i] - x);
            if (j == 1) {
                dp1[i + 1][0] = max(dp1[i + 1][0], dp1[i][j]);
            }
        }
    }
    return max(dp1[n][0], dp1[n][1]) >= 0;
}

bool check2(int x) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[i][j] = -inf;
        }
    }
    dp[0][1] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (dp[i][j] == -inf) {
                continue;
            }
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + (a[i] >= x ? 1 : -1));
            if (j == 1) {
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
            }
        }
    }
    return max(dp[n][0], dp[n][1]) > 0;
}

void test_case() {
    cin >> n;
    a.resize(n);
    indexed_set<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nums.insert(a[i]);
    }
    long double lo1 = 0, hi1 = 1e9, mid1, res1;

    while (hi1 - lo1 > 1e-7) {
        mid1 = (lo1 + hi1) / 2;
        if (check1(mid1)) {
            res1 = mid1;
            lo1 = mid1;
        } else {
            hi1 = mid1;
        }
    }
    cout << fixed << setprecision(16) << res1 << "\n";

    int lo = 0, hi = int(nums.size()) - 1, mid, res;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check2(*nums.find_by_order(mid))) {
            lo = mid + 1;
            res = *nums.find_by_order(mid);
        } else {
            hi = mid - 1;
        }
    }
    cout << res << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
