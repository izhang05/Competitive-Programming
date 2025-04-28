/* Author: izhang
 * Time: 12-28-2024 11:02:18
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

map<int, int> dp[mxn], grid[mxn];
int mx[mxn];

void test_case() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        dp[i].clear();
        grid[i].clear();
        mx[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            ++grid[i][a];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto &j: grid[i]) {
            dp[i][j.first] = 0;
            if (i) {
                dp[i - 1][j.first] = 0;
            }
        }
        dp[i][-1] = 0;
    }
    for (int i = 1; i <= k; ++i) {
        dp[n - 1][i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        for (auto &j: dp[i]) {
            if (j.first != -1) {
                j.second = max(mx[i - 1], dp[i - 1][j.first] + grid[i - 1][-1]) + grid[i - 1][j.first];
                mx[i] = max(mx[i], j.second);
            }
        }
        for (auto &j: dp[i - 1]) {
            if (dp[i].find(j.first) == dp[i].end()) {
                dp[i][-1] = max(dp[i][-1], j.second + grid[i - 1][j.first] + grid[i - 1][-1]);
            }
        }

        mx[i] = max(mx[i], dp[i][-1]);
    }
    cout << mx[n - 1] << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
