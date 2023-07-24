#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int mod = 1e9 + 7, maxn = 305;
const long long inf = 1e18;

long double dp[maxn][maxn][maxn], p[maxn][maxn][maxn];


int main() {
    setIO("J");
    int n;
    cin >> n;
    vector<int> orig(3);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++orig[a - 1];
    }
    p[orig[0]][orig[1]][orig[2]] = 1;
    for (int c = n; c >= 0; --c) {
        for (int b = n; b >= 0; --b) {
            for (int a = n; a >= 0; --a) {
                if (a == 0 && b == 0 && c == 0) {
                    continue;
                }
                if (a + b + c > n) {
                    continue;
                }
                long double pwaste = (long double) (n - (a + b + c)) / n;
                long double evwaste = pwaste / (1 - pwaste) + 1;
                dp[a][b][c] += evwaste * p[a][b][c];
                if (a > 0) {
                    long double pn = ((long double) a) / (a + b + c);
                    p[a - 1][b][c] += p[a][b][c] * pn;
                    dp[a - 1][b][c] += dp[a][b][c] * pn;
                }
                if (b > 0) {
                    long double pn = (long double) b / (a + b + c);
                    p[a + 1][b - 1][c] += p[a][b][c] * pn;
                    dp[a + 1][b - 1][c] += dp[a][b][c] * pn;
                }
                if (c > 0) {
                    long double pn = (long double) c / (a + b + c);
                    p[a][b + 1][c - 1] += p[a][b][c] * pn;
                    dp[a][b + 1][c - 1] += dp[a][b][c] * pn;
                }
            }
        }
    }
    cout << fixed << setprecision(15) << dp[0][0][0] << "\n";
    return 0;
}
