/* Author: izhang05
 * Time: 10-22-2021 19:37:11
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[maxn][maxn];

void solve() {
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int len = 0; len < 2 * n; ++len) {
        for (int l = 0; l < min(n, len + 1); ++l) {
            int r = len - l;
            if (r<0||r)
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
