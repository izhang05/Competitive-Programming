//#include <bits/stdc++.h>
//
//using namespace std;
//
////#define DEBUG
//void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen(("in" + name + ".txt").c_str(), "r", stdin);
////    freopen("out.txt", "w", stdout);
////    freopen("out.txt", "w", stderr);
//#endif
//}
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e2 + 5;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//long long dp[maxn][maxn][2]; // dp[l][r][cnt outside][hi?]
//long long ways[maxn][maxn][2];
//long long f[maxn];
//
//void add(long long &a, long long b) {
//    a += b % mod;
//    if (a > mod) {
//        a -= mod;
//    }
//}
//
//int main() {
//    setIO("8");
//    f[0] = 1;
//    for (int i = 1; i < maxn; ++i) {
//        f[i] = (f[i - 1] * i) % mod;
//    }
//    int n, x;
//    cin >> n >> x;
//    ways[0][n + 1][0] = 1;
//    for (int len = n + 1; len >= 0; --len) {
//        for (int l = 0, r = l + len; r <= n + 1; ++l, ++r) {
//            for (int i = 0; i < 2; ++i) {
//                long long cur = dp[l][r][i], cur_w = ways[l][r][i];
//                if (!cur_w && !cur) {
//                    continue;
//                }
//#ifdef DEBUG
//                cout << l << " " << r << " " << cnt << " " << i << " = " << cur << " " << cur_w << "\n";
//#endif
//                for (int mid = l + 1; mid < r; ++mid) {
//                    if (mid > x) {
//                        int perm = f[r - mid - 1];
//                        add(dp[l][mid][1], cur * perm);
//                        add(ways[l][mid][1], cur_w * perm);
//                    } else {
//                        int perm = f[mid - l - 1];
//                        add(ways[mid][r][0], cur_w * perm);
//                        if (i) {
//                            add(dp[mid][r][0], cur * perm + cur_w*perm);
//                        } else {
//                            add(dp[mid][r][0], cur * perm);
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    cout << (dp[x][x + 1][0] + dp[x][x + 1][1]) % mod << "\n";
//    return 0;
//}


#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 65;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[maxn][maxn][maxn][2]; // dp[l][r][cnt outside][hi?]
long long ways[maxn][maxn][maxn][2];

void add(long long &a, long long b) {
    a += b % mod;
    if (a > mod) {
        a -= mod;
    }
}

int main() {
    setIO("8");
    int n, x;
    cin >> n >> x;
    dp[0][n + 1][0][0] = 0;
    ways[0][n + 1][0][0] = 1;
    for (int len = n + 1; len >= 0; --len) {
        for (int l = 0, r = l + len; r <= n + 1; ++l, ++r) {
            for (int cnt = n; cnt >= 0; --cnt) {
                for (int i = 0; i < 2; ++i) {
                    long long cur = dp[l][r][cnt][i], cur_w = ways[l][r][cnt][i];
                    if (!cur_w && !cur) {
                        continue;
                    }
#ifdef DEBUG
                    cout << l << " " << r << " " << cnt << " " << i << " = " << cur << " " << cur_w << "\n";
#endif
                    // take from outside range
                    if (cnt) {
                        add(dp[l][r][cnt - 1][i], cur * cnt);
                        add(ways[l][r][cnt - 1][i], (cnt * cur_w) % mod);
                    }
                    for (int mid = l + 1; mid < r; ++mid) {
#ifdef DEBUG
//                        cout << l << " " << mid << " " << r << " " << cur << "\n";
#endif
                        if (mid > x) {
                            int new_cnt = cnt + r - mid - 1;
                            add(dp[l][mid][new_cnt][1], cur);
                            add(ways[l][mid][new_cnt][1], cur_w);
                            //                            cout << dp[l][mid][cnt + r - mid][1] << "\n";
                        } else {
                            int new_cnt = cnt + mid - l - 1;
                            //                            dp[mid][r][new_cnt][0] = max(dp[mid][r][new_cnt][0], 0ll);
                            add(ways[mid][r][new_cnt][0], cur_w);
                            if (i) {
                                add(dp[mid][r][new_cnt][0], cur + cur_w);
                            } else {
                                add(dp[mid][r][new_cnt][0], cur);
                            }
                            //                            cout << dp[mid][r][cnt + mid - l][0] << "\n";
                        }
                    }
                }
            }
        }
    }

    cout << (dp[x][x + 1][0][0] + dp[x][x + 1][0][1]) % mod << "\n";
    return 0;
}
