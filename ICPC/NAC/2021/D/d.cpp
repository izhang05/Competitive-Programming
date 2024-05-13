#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mxn = 55, mxk = 20;
long long dp[mxn][mxk][mxn][mxn]; // dp[ind][# taken][2nd last][last]

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int l = j; l < n; ++l) {
                dp[l][2][i][j] = 1;
            }
        }
    }
    long long sol = 0;
    for (int l = 3; l <= k; ++l) {
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                //take
                if (j < i) {
                    for (int m = 0; m < j; ++m) {
                        if (a[m] + a[j] >= a[i]) {
                            dp[i][l][j][i] += dp[i - 1][l - 1][m][j];
                        }
                    }
                }
                //don't take
                for (int m = j + 1; m <= i; ++m) {
                    // don't take
                    dp[i][l][j][m] += dp[i - 1][l][j][m];
                }
            }
        }
    }
//    }
    for (int j = 0; j < n; ++j) {
        for (int l = j + 1; l < n; ++l) {
            sol += dp[n - 1][k][j][l];
        }
    }
    cout << sol << "\n";
}