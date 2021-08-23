/* Author: izhang05
 * Time: 08-23-2021 18:50:06
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}

struct color {
    int n;
    vector<long long> b;
};
const int maxn = 205;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<color> a(3);
long long dp[maxn][maxn][maxn];

long long f(int x, int y, int z) {
    if (dp[x][y][z] != -1) {
        return dp[x][y][z];
    }
    long long &cur = dp[x][y][z];
    if (x - 1 >= 0 && y - 1 >= 0) {
        cur = max(cur, f(x - 1, y - 1, z) + a[0].b[x - 1] * a[1].b[y - 1]);
    }
    if (x - 1 >= 0 && z - 1 >= 0) {
        cur = max(cur, f(x - 1, y, z - 1) + a[0].b[x - 1] * a[2].b[z - 1]);
    }
    if (y - 1 >= 0 && z - 1 >= 0) {
        cur = max(cur, f(x, y - 1, z - 1) + a[1].b[y - 1] * a[2].b[z - 1]);
    }
    return cur;
}

int main() {
    setIO("");
    for (int i = 0; i < 3; ++i) {
        cin >> a[i].n;
    }
    for (int i = 0; i < 3; ++i) {
        a[i].b.resize(a[i].n);
        for (auto &j : a[i].b) {
            cin >> j;
        }
        sort(a[i].b.begin(), a[i].b.end());
        reverse(a[i].b.begin(), a[i].b.end());
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    long long sol = 0;
    for (int i = 0; i <= a[0].n; ++i) {
        for (int j = 0; j <= a[1].n; ++j) {
            for (int k = 0; k <= a[2].n; ++k) {
                sol = max(sol, f(i, j, k));
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
