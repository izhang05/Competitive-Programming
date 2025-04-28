#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m, ans;

vector<int> c, cap;

vector<vector<vector<int>>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    c.assign(n, 0);
    cap.assign(n, 0);

    cap[0] = m;

    for(int i = 1; i < n; i++) cap[i] = (cap[i - 1] * 2) / 3;

    for(int i = 0; i < n; i++) cin >> c[i];

    dp.assign(n + 1, vector(n + 1, vector(n + 1, -(int)1e9)));

    dp[0][0][0] = 0;

    for(int hour = 0; hour < n; hour++){
        for(int cur = 0; cur < n; cur++){
            for(int sleep = 0; sleep < n; sleep++){
                // eat

                dp[hour + 1][cur + 1][0] = max(dp[hour + 1][cur + 1][0], dp[hour][cur][sleep] + min(c[hour], cap[cur]));

                // sleep

                if(sleep == 1) dp[hour + 1][0][2] = max(dp[hour + 1][0][2], dp[hour][cur][sleep]);
                else dp[hour + 1][cur][sleep + 1] = max(dp[hour + 1][cur][sleep + 1], dp[hour][cur][sleep]);
            }
        }
    }

    for(int hour = 0; hour <= n; hour++){
        for(int cur = 0; cur <= n; cur++){
            for(int sleep = 0; sleep <= n; sleep++){
                ans = max(ans, dp[hour][cur][sleep]);
            }
        }
    }

    cout << ans;
}