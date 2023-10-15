/* Author: izhang
 * Time: 10-15-2023 00:45:01
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 5e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[mxn][3], new_dp[mxn][3]; // dp[pos][#taken][(took last, didn't decrease last, decreased last)]

void test_case() {
    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = -inf;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a.push_back(-inf);
    dp[0][1] = 0;
    dp[1][0] = max(0, a[2] - a[1] + 1);
    for (int i = 2; i <= n; ++i) {
        memset(new_dp, 0x3f, sizeof(new_dp));
        new_dp[0][1] = 0;
        for (int j = 1; j <= i; ++j) {
            // take hill i
            new_dp[j][0] = min(max(0, a[i - 1] - a[i] + 1) + dp[j - 1][1] + max(0, a[i + 1] - a[i] + 1),
                               max(0, (a[i - 2] - 1) - a[i] + 1) + dp[j - 1][2] + max(0, a[i + 1] - a[i] + 1));

            //don't take hill i
            new_dp[j][1] = min(dp[j][1], dp[j][2]);
            if (a[i] < a[i - 1]) {
                new_dp[j][1] = min(new_dp[j][1], dp[j][0]);
            } else {
                new_dp[j][2] = dp[j][0];
            }
        }
        swap(dp, new_dp);
    }
    for (int i = 1; i <= (n + 1) / 2; ++i) {
        cout << min({dp[i][0], dp[i][1], dp[i][2]}) << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

///* Author: izhang
// * Time: 10-15-2023 00:45:01
//**/
//#include <bits/stdc++.h>
//
//using namespace std;
//
//#if defined LOCAL || defined DEBUG
//#include <debug.h>
//#else
//struct dbg {
//    template<class c>
//    dbg &operator<<(const c &) { return *this; }
//};
//#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//#endif
//
////#define DEBUG
//void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
//#endif
//}
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 5e3 + 5;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//long long dp[mxn][mxn][3]; // dp[pos][#taken][(took last, didn't decrease last, decreased last)]
//
//void test_case() {
//    memset(dp, 0x3f, sizeof(dp));
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    a[0] = -inf;
//    for (int i = 1; i <= n; ++i) {
//        cin >> a[i];
//    }
//    a.push_back(-inf);
//    dp[1][0][1] = 0;
//    dp[1][1][0] = max(0, a[2] - a[1] + 1);
//    for (int i = 2; i <= n; ++i) {
//        dp[i][0][1] = 0;
//        for (int j = 1; j <= i; ++j) {
//            // take hill i
//            dp[i][j][0] = min(max(0, a[i - 1] - a[i] + 1) + dp[i - 1][j - 1][1] + max(0, a[i + 1] - a[i] + 1),
//                              max(0, (a[i - 2] - 1) - a[i] + 1) + dp[i - 1][j - 1][2] + max(0, a[i + 1] - a[i] + 1));
//
//            //don't take hill i
//            dp[i][j][1] = min(
//                    dp[i - 1][j][1],
//                    dp[i - 1][j][2]);
//            if (a[i] < a[i - 1]) {
//                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0]);
//            } else {
//                dp[i][j][2] = dp[i - 1][j][0];
//            }
//        }
//    }
//
//    for (int i = 1; i <= (n + 1) / 2; ++i) {
//        cout << min({dp[n][i][0], dp[n][i][1], dp[n][i][2]}) << " ";
//    }
//    cout << "\n";
//}
//
//int main() {
//    setIO("1");
//
//    int test_case_number = 1;
//    while (test_case_number--) {
//        test_case();
//    }
//    return 0;
//}
