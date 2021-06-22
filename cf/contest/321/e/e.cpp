/* Author: izhang05
 * Time: 06-21-2021 23:10:00
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}

int readInt() {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else
        result = ch - '0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 4005, maxk = 805;
int a[maxn][maxn];
int dp[maxn][maxk];

int cost(int x, int y) {
    return a[y][y] - a[y][x - 1] - a[x - 1][y] + a[x - 1][x - 1];
}

void solve(int g, int i, int j, int l, int r) {
    if (i > j) {
        return;
    }
    int mid = (i + j) / 2, best_ind = l;
    for (int k = l; k <= min(r, mid); ++k) {
        int val = dp[k - 1][g - 1] + cost(k, mid);
        if (val < dp[mid][g]) {
            dp[mid][g] = val;
            best_ind = k;
        }
    }
    solve(g, i, mid - 1, l, best_ind);
    solve(g, mid + 1, j, best_ind, r);
}

int main() {
    setIO("1");
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = (int) readInt() + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
        solve(i, 1, n, 1, n);
    }
    //    for (int i = 1; i <= k; ++i) {
    //        for (int j = 1; j <= n; ++j) {
    //            for (int l = 1; l <= j; ++l) {
    //                dp[j][i] = min(dp[j][i], dp[l - 1][i - 1] + cost(l, j));
    //            }
    //        }
    //    }
    cout << *min_element(dp[n] + 1, dp[n] + k + 1) / 2 << "\n";
    return 0;
}
