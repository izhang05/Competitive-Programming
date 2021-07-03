/* Author: izhang05
 * Time: 07-02-2021 21:35:27
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxk = 20;

bool avail[1 << maxk];
int dp[1 << maxk];

int main() {
    setIO("2");

    string s;
    cin >> s;
    int n = (int) s.size();
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = i; j < i + 26 && j < n; ++j) {
            if (cur & (1 << (s[j] - 'a'))) {
                break;
            }
            cur |= 1 << (s[j] - 'a');
            avail[cur] = true;
        }
    }
    for (int i = 0; i < (1 << maxk); ++i) {
        if (avail[i]) {
            dp[i] = __builtin_popcount(i);
        }
        for (int j = 0; j < maxk; ++j) {
            if (i & (1 << j)) {
                dp[i] = max(dp[i], dp[i ^ (1 << j)]);
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < (1 << maxk); ++i) {
        if (avail[i]) {
            sol = max(sol, __builtin_popcount(i) + dp[i ^ ((1 << maxk) - 1)]);
        }
    }
    cout << sol << "\n";
    return 0;
}
