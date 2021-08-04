/* Author: izhang05
 * Time: 08-04-2021 12:10:48
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
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
long double dp[maxn][maxn][2]; // probability of princess winning[white mice][black mice][1=princess turn]
long double sol = 0;

long double solve(int w, int b, bool turn) {
    if (w < 0 || b < 0) {
        return 0;
    }
    if (dp[w][b][turn] != -1) {
        return dp[w][b][turn];
    }
    if (w == 0) {
        return dp[w][b][turn] = 0;
    }
    long double cnt = w + b;
    if (turn) {
        dp[w][b][turn] = w / cnt + (b / cnt) * solve(w, b - 1, !turn);
    } else {
        if (cnt == 1) {
            return dp[w][b][turn] = 0;
        }
        dp[w][b][turn] = (b / cnt) * (w / (cnt - 1)) * solve(w - 1, b - 1, !turn);
        dp[w][b][turn] += (b / cnt) * ((b - 1) / (cnt - 1)) * solve(w, b - 2, !turn);
    }
    return dp[w][b][turn];
}

int main() {
    setIO("1");
    int w, b;
    cin >> w >> b;
    for (auto &i : dp) {
        for (auto &j : i) {
            for (auto &k : j) {
                k = -1;
            }
        }
    }
    cout << fixed << setprecision(16) << solve(w, b, true) << "\n";

    return 0;
}
