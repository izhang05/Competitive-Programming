/* Author: izhang
 * Time: 09-18-2023 20:13:56
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 505;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int dp[mxn][mxn][2];

int f(int a, int b, int c) {
    if (dp[a][b][c] != -1) {
        return dp[a][b][c];
    }
    if (c == 0) {
        for (int i = 1; i < a; ++i) {
            if (!f(i, b, 1)) {
                return dp[a][b][c] = true;
            }
        }
    } else if (c == 1) {
        for (int i = 1; i < b; ++i) {
            if (!f(a, i, 0)) {
                return dp[a][b][c] = true;
            }
        }
    }
    return dp[a][b][c] = false;
}

void test_case() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    swap(n, m);
    cout << s << " ";
    if (s == "Harry") {
        cout << (f(n, m, 0) ? "can" : "cannot");
    } else {
        cout << (f(n, m, 1) ? "can" : "cannot");
    }
    cout << " win" << "\n";
}

int main() {
    setIO("1");
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = dp[1][1][0] = dp[1][1][1] = 0;

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 2; ++k) {
                cout << dp[i][j][k] << "";
            }
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
