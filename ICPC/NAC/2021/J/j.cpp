#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mxk = 105, inf = 0x3f3f3f3f;
long long dp[mxk][26];
int cost[26][26];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            cost[i][j] = inf;
        }
    }
    for (int i = 0; i < n; ++i) {
        string s;
        int x;
        cin >> s >> x;
        int a = s[0] - 'a', b = s[1] - 'a';
        cost[a][b] = x;
    }
    if (k == 2) {
        int sol = inf;
        for (int i = 0; i < 26; ++i) {
            sol = min(sol, cost[i][i]);
        }
        cout << (sol == inf ? -1 : sol) << "\n";
        return 0;
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < 26; ++i) {
        dp[1][i] = 0;
    }
    for (int i = 2; i <= (k - 1) / 2; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int l = 0; l < 26; ++l) {
                dp[i][j] = min(dp[i][j], dp[i - 1][l] + cost[j][l] + cost[l][j]);
            }
        }
    }
    if (k % 2 == 1) {
        long long sol = inf;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                sol = min(sol, dp[k / 2][j] + cost[i][j] + cost[j][i]);
            }
        }
        cout << (sol == inf ? -1 : sol) << "\n";
    } else {
        long long sol = inf;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                sol = min(sol, dp[k / 2 - 1][j] + cost[i][j] + cost[j][i] + cost[i][i]);
            }
        }
        cout << (sol == inf ? -1 : sol) << "\n";
    }
}