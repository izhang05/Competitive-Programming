/* Author: izhang05
 * Time: 08-17-2021 10:59:55
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
const int inf = 0x3f3f3f3f, mod = 998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

const int maxn = 1e6 + 5;
long long dp[maxn], sum_dp[maxn];

void solve() {
    string s, l, r;
    cin >> s >> l >> r;
    int n = int(s.size()), x = int(l.size()), y = int(r.size());
    vector<int> a = z_function(l + '\2' + s), b = z_function(r + '\2' + s);
    dp[n] = sum_dp[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            if (l == "0") {
                dp[i] = dp[i + 1];
            } else {
                dp[i] = 0;
            }
            sum_dp[i] = (sum_dp[i + 1] + dp[i]) % mod;
            continue;
        }
        int left_bound = i + x, right_bound = i + y - 2;
        int z = a[i + x + 1];
        if (z == x || s[z + i] > l[z]) {
            --left_bound;
        }
        z = b[i + y + 1];
        if (z == y || s[z + i] < r[z]) {
            ++right_bound;
        }
        if (left_bound <= n) {
            dp[i] = (sum_dp[left_bound + 1] - (right_bound + 2 <= n ? sum_dp[right_bound + 2] : 0)) % mod;
        }
        dp[i] += mod;
        dp[i] %= mod;
        sum_dp[i] = (sum_dp[i + 1] + dp[i]) % mod;
    }
    cout << dp[0] << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
