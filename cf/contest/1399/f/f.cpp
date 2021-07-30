/* Author: izhang05
 * Time: 07-29-2021 22:32:09
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e3 + 5;
int dp[2 * maxn][2 * maxn];
vector<int> endp[2 * maxn];

int solve(int l, int r) { // sol for [l,r]
    if (l > r) {
        return 0;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    dp[l][r] = solve(l + 1, r);
    for (auto &i : endp[l]) {
        if (i < r) {
            dp[l][r] = max(dp[l][r], solve(l, i) + solve(i + 1, r));
        }
    }
    if (find(endp[l].begin(), endp[l].end(), r) != endp[l].end()) {
        ++dp[l][r];
    }
    return dp[l][r];
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        set<int> nums;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
            nums.insert(a[i].first);
            nums.insert(a[i].second);
        }
        int in = 0;
        map<int, int> ind;
        for (auto &i : nums) {
            ind[i] = in++;
        }

        for (int i = 0; i < 2 * n + 3; ++i) {
            endp[i].clear();
            for (int j = 0; j < 2 * n + 3; ++j) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < n; ++i) {
            endp[ind[a[i].first]].push_back(ind[a[i].second]);
        }
        cout << solve(0, in) << "\n";
    }
    return 0;
}
