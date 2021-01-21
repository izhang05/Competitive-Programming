///*
//ID: izhang01
//TASK: cowrun
//LANG: C++11
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("cowrun.in", "r", stdin);
//    freopen("cowrun.out", "w", stdout);
//}
//const int maxn = 1001;
//const long long inf = 1e18;
//long long dp[maxn][maxn][2], t[maxn][maxn][2];
//vector<int> a;
//int n;
//
//void check(int expected, int i, int j, int k) {
//    if (expected != dp[i][j][k]) {
//        cout << i << " " << j << " " << k << ": Expected: " << expected << ". Actual: " << dp[i][j][k] << "\n";
//    } else {
//        cout << "Good: " << i << " " << j << " " << k << "\n";
//    }
//}
//
//
//long long sol(int l, int r, int d) {
//    if (dp[l][r][d]) {
//        return dp[l][r][d];
//    }
//    if (l == r) {
//        return dp[l][r][d] = abs(a[l]);
//    }
//    long long &res = dp[l][r][d];
//    res = inf;
//    if (d == 0) {
//        res = min(res, 2 * sol(l + 1, r, 0) + abs(a[l + 1] - a[l]));
//        res = min(res, 2 * sol(l + 1, r, 1) + abs(a[r] - a[l]));
//    } else {
//        res = min(res, 2 * sol(l, r - 1, 0) + abs(a[r] - a[l]));
//        res = min(res, 2 * sol(l, r - 1, 1) + abs(a[r] - a[r - 1]));
//    }
//    return res;
//}
//
//int main() {
//    setIO();
//    cin >> n;
//    a.resize(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    sort(a.begin(), a.end());
//    sol(0, 3, 0);
//    sol(0, 3, 1);
//    check(12, 0, 0, 0);
//    check(12, 0, 0, 1);
//    check(2, 1, 1, 0);
//    check(2, 1, 1, 1);
//    check(14, 0, 1, 0);
//    check(34, 0, 1, 1);
//    check(9, 1, 2, 1);
//    check(11, 1, 2, 0);
//    check(20, 1, 3, 1);
//    check(50, 0, 3, 0);
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = i; j < n; ++j) {
//            for (int k = 0; k < 2; ++k) {
//                cout << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
//            }
//        }
//    }
//    return 0;
//}


#include <bits/stdc++.h>
using namespace std;

FILE *fin = fopen("cowrun.in", "r");
FILE *fout = fopen("cowrun.out", "w");

const int MAXN = 1005;

int N;

int cows[MAXN];
int best[MAXN][MAXN][2];
void check(int expected, int i, int j, int k) {
    if (expected != best[i][j][k]) {
        cout << i << " " << j << " " << k << ": Expected: " << expected << ". Actual: " << best[i][j][k] << "\n";
    } else {
        cout << "Good: " << i << " " << j << " " << k << "\n";
    }
}

int main() {
    memset(best, 63, sizeof(best));

    fscanf(fin, "%d", &N);

    for (int i = 1; i <= N; i++)
        fscanf(fin, "%d", cows + i);

    cows[++N] = 0;
    sort(cows + 1, cows + N + 1);
    for (int i = 1; i <= N; i++)
        if (cows[i] == 0)
            best[i][1][0] = 0;

    for (int len = 1; len < N; len++) {
        int ccount = N - len;
        for (int i = 1; i + len <= N + 1; i++) {
            best[i - 1][len + 1][0] = min(best[i - 1][len + 1][0], best[i][len][0] + ccount * (cows[i] - cows[i - 1]));
            best[i - 1][len + 1][0] = min(best[i - 1][len + 1][0], best[i][len][1] + ccount * (cows[i + len - 1] - cows[i - 1]));
            best[i][len + 1][1] = min(best[i][len + 1][1], best[i][len][0] + ccount * (cows[i + len] - cows[i]));
            best[i][len + 1][1] = min(best[i][len + 1][1], best[i][len][1] + ccount * (cows[i + len] - cows[i + len - 1]));
        }
    }
    fprintf(fout, "%d\n", min(best[1][N][0], best[1][N][1]));
    cout << best[3][1][0] << "\n";
    cout << best[3][2][0] << "\n";
//    check(12, 1, 1, 0);
//    check(12, 1, 1, 1);
//    check(2, 2, 1, 0);
//    check(2, 2, 1, 1);
//    check(14, 1, 2, 0);
//    check(34, 1, 2, 1);
//    check(9, 1, 2, 1);
//    check(11, 1, 2, 0);
//    check(20, 1, 3, 1);
//    check(50, 0, 3, 0);

    return 0;
}