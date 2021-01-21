///*
//ID: izhang01
//TASK: cbarn2
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
//    freopen("cbarn2.in", "r", stdin);
//    freopen("cbarn2.out", "w", stdout);
//}
//
//const int maxn = 101, maxk = 7;
//long long dp[maxn][maxk][maxn]; // dp[loc][num_doors_used - 1][index of last door]
//
//int main() {
//    setIO();
//    int n, k;
//    long long sol = 1e18;
//    cin >> n >> k;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    for (int i = 0; i < n - k + 1; ++i) {
//        for (int j = 0; j < n; ++j) {
//            for (int l = 0; l < k; ++l) {
//                for (int m = 0; m < n; ++m) {
//                    dp[j][l][m] = 1e18;
//                }
//            }
//        }
//        dp[i][0][i] = 0;
//        for (int j = i; j < i + n; ++j) {
//            for (int l = 0; l < k; ++l) {
//                for (int m = i; m < n + i; ++m) {
//                    if (l < k) {
//                        dp[(j + 1) % n][l + 1][(j + 1) % n] = min(dp[(j + 1) % n][l + 1][(j + 1) % n], dp[j % n][l][m % n]);
//                    }
//                    dp[(j + 1) % n][l][m % n] = min(dp[(j + 1) % n][l][m % n], dp[j % n][l][m % n] + ((j + 1 - m + n) % n) * a[(j + 1) % n]);
//                }
//            }
//        }
//        long long cur = 1e18;
//        for (int j = 0; j < n; ++j) {
//            cur = min(cur, dp[(i - 1 + n) % n][k - 1][j]);
//        }
//        sol = min(sol, cur);
//    }
//    cout << sol << "\n";
//    return 0;
//}

/*
ID: izhang01
TASK: cbarn2
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
}

const int maxn = 101, maxk = 7;
int dp[maxn][maxk][maxn]; // dp[loc][num_doors_used - 1][index of last door]

int main() {
    setIO();
    int n, k, sol = 1e9;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - k + 1; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < k; ++l) {
                for (int m = 0; m < n; ++m) {
                    dp[j][l][m] = 1e9;
                }
            }
        }
        dp[0][0][0] = 0;
        for (int j = 0; j < n - 1; ++j) {
            for (int l = 0; l < k; ++l) {
                for (int m = 0; m <= j; ++m) {
                    if (l < k) {
                        dp[j + 1][l + 1][j + 1] = min(dp[j + 1][l + 1][j + 1], dp[j][l][m]);
                    }
                    dp[j + 1][l][m] = min(dp[j + 1][l][m], dp[j][l][m] + (j + 1 - m) * a[(j + 1 + i) % n]);
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            sol = min(sol, dp[n - 1][k - 1][j]);
        }
    }
    cout << sol << "\n";
    return 0;
}
