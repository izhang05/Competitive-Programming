#include <bits/stdc++.h>

using namespace std;

const long double INF = 1e18;

int n;

vector<pair<int, int>> arr;

long double dist(int a, int b, long double ang){
    long double l = sqrtl(1ll * (arr[b].second - arr[a].second) * (arr[b].second - arr[a].second) +
            1ll * (arr[b].first - arr[a].first) * (arr[b].first - arr[a].first));

    long double t = atan((long double)(arr[b].second - arr[a].second) / (arr[b].first - arr[a].first));

    return l * (abs(sin(t-ang)) + abs(cos(t-ang)));
}

long double solve(long double ang){
    vector<vector<long double>> dp(1 << n, vector(n, INF));

    for(int i = 0; i < n; i++) dp[1 << i][i] = 0;

    for(int m = 1; m < (1 << n); m++){
        for(int i = 0; i < n; i++){
            if((m >> i) & 1){
                for(int j = 0; j < n; j++){
                    if((m >> j) & 1) continue;

                    dp[m | (1 << j)][j] = min(dp[m | (1 << j)][j], dp[m][i] + dist(i, j, ang));
                }
            }
        }
    }

    long double ans = INF;

    for(int i = 0; i < n; i++) ans = min(ans, dp[(1 << n) - 1][i]);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n;

    arr.assign(n, {});

    for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

//    pair<long double, long double> ans = {INF, INF};

//    for(long double ang = 0; ang < 90; ang += 0.01){
//        ans = min(ans, {solve(ang), ang});
//    }

//    cout << setprecision(16) << fixed << ans.first << "\n"
//    << ans.second << "\n";

    pair<long double, long double> ans2 = {INF, INF};

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            long double ang = atan((long double)(arr[j].second - arr[i].second) / (arr[j].first - arr[i].first));

            ans2 = min(ans2, {solve(ang), ang});
        }
    }

    cout << setprecision(16) << fixed << ans2.first << "\n";

//    return 0;
}

