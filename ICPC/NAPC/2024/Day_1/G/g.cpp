#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mxn = 1e5 + 5, mxk = 12;

long long dp[mxn][mxk][mxk][2];
const long long inf = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    for (int i = n - 1; i >= 0; --i) {
        for (int a_pick = k; a_pick >= 0; --a_pick) {
//            if (a_pick + i >= n) {
//                continue;
//            }
            for (int b_pick = k; b_pick >= 0; --b_pick) {
//                if (b_pick + i )
                int b_banned = i - b_pick, a_banned = i + 1 - a_pick;
                // b picks a new one
                dp[i][a_pick][b_pick][1] = inf;
                if (b_pick < k && b_pick + a_banned < n && b_pick + a_banned >= 0) {
                    dp[i][a_pick][b_pick][1] = dp[i + 1][a_pick][b_pick + 1][0] - b[b_pick + a_banned];
                }
                // b ban
                dp[i][a_pick][b_pick][1] = min(dp[i][a_pick][b_pick][1], dp[i + 1][a_pick][b_pick][0]);

                // a picks a new one
//                cout << dp[0][0][0][0] << "\n";
                dp[i][a_pick][b_pick][0] = -inf;
                if (a_pick < k && a_pick + b_banned < n && a_pick + b_banned >= 0) {
                    dp[i][a_pick][b_pick][0] = dp[i][a_pick + 1][b_pick][1] + a[a_pick + b_banned];
                }
//                cout << dp[0][0][0][0] << "\n";
                // a bans highest
                dp[i][a_pick][b_pick][0] = max(dp[i][a_pick][b_pick][0], dp[i][a_pick][b_pick][1]);
            }
        }
    }
//    cout << dp[0][1][0][1] << "\n";
//    cout << dp[0][0][0][1] << "\n";
    cout << dp[0][0][0][0] << "\n";
}