// O(nmk) - 9/16 test cases
//
///*
//ID: izhang01
//TASK: cowmbat
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
//    freopen("cowmbat.in", "r", stdin);
//    freopen("cowmbat.out", "w", stdout);
//}
//const int maxm = 26, maxn = 1e5 + 1, inf = 1e9;
//int dist[maxm][maxm], dp[maxn], pre[maxm][maxn];
//
//int main() {
//    setIO();
//    int n, m, k;
//    cin >> n >> m >> k;
//    string s;
//    cin >> s;
//    vector<int> orig(n);
//    for (int i = 0; i < n; ++i) {
//        orig[i] = s[i] - 'a';
//        dp[i] = inf;
//    }
//    int a;
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> a;
//            dist[i][j] = a;
//        }
//    }
//    for (int l = 0; l < m; ++l) {
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < m; ++j) {
//                dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
//            }
//        }
//    }
//
//    for (int i = 0; i < m; ++i) {
//        for (int j = 1; j < n + 1; ++j) {
//            pre[i][j] = pre[i][j - 1] + dist[orig[j - 1]][i];
//            dp[j - 1] = min(dp[j - 1], pre[i][j]);
//        }
//    }
//    for (int i = k - 1; i < n + 1; ++i) {
//        for (int j = i - k; j >= k - 1 && j >= i - 2 * k; --j) {
//            int res = inf;
//            for (int l = 0; l < m; ++l) {
//                res = min(res, pre[l][i + 1] - pre[l][j + 1]);
//            }
//            dp[i] = min(dp[i], dp[j] + res);
//        }
//    }
//    cout << dp[n - 1] << "\n";
//    return 0;
//}


/*
ID: izhang01
TASK: cowmbat
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
}
const int maxm = 26, maxn = 1e5 + 1;
int dist[maxm][maxm], dp[maxn][maxm], pre[maxn][maxm], sol[maxn];

int main() {
    setIO();
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    for (char &i : s) {
        i -= 'a';
    }
    memset(dp, 0x3f, sizeof(dp));
    memset(sol, 0x3f, sizeof(sol));
    int a;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a;
            dist[i][j] = a;
        }
    }
    for (int l = 0; l < m; ++l) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 0; j < m; ++j) {
            pre[i][j] = pre[i - 1][j] + dist[s[i - 1]][j];
        }
    }
    sol[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist[s[i - 1]][j]);
            if (i >= k) {
                dp[i][j] = min(dp[i][j], sol[i - k] + pre[i][j] - pre[i - k][j]);
            }
            sol[i] = min(sol[i], dp[i][j]);
        }
    }
    cout << sol[n] << "\n";
    return 0;
}
