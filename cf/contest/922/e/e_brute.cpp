#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

const int MAXM = 10005;
const int MAXN = 1005;

ll dp[MAXN][MAXM];
ll c[MAXN], cost[MAXN];

int main()
{
    ll n, W, B, X;
    ll m = 0;
    cin >> n >> W >> B >> X;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        m += c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXM; j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = W;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            ll max_mana = W + j * B;
            for (int k = 0; k <= min((ll)j, c[i]); k++) {
                if (dp[i-1][j-k] == -1) {
                    continue;
                }
                ll new_mana = min(W + (j - k) * B, dp[i-1][j-k] + X) - cost[i] * k;
                if (new_mana < 0) {
                    continue;
                }
                dp[i][j] = max(dp[i][j], min(max_mana, new_mana));
                ans = max(ans, j);
                max_mana += B;
            }
        }
    }

    /*
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%4lld ", dp[i][j]);
        }
        puts("");
    }
    */

    cout << ans << endl;

    return 0;
}