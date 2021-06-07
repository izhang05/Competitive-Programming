#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
int dp[maxn], mxdp[26];

int main() {
    setIO("c");
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - 'a';
        dp[i] = 1;
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = a[i] + 1; j < 26; ++j) {
            dp[i] = max(dp[i], mxdp[j] + 1);
        }
        mxdp[a[i]] = max(mxdp[a[i]], dp[i]);
        sol = max(sol, dp[i]);
    }
    if (sol <= 2) {
        cout << "YES"
             << "\n";
        for (int i = 0; i < n; ++i) {
            cout << dp[i] - 1;
        }
        cout << "\n";
    } else {
        cout << "NO"
             << "\n";
    }
    return 0;
}
