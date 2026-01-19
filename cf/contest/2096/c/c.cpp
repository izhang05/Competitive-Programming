/* Author: izhang
 * Time: 06-20-2025 15:42:15
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int n;
long long dp[mxn][2];

long long solve(const vector<int> &eq, const vector<int> &pl, const vector<int> &mn, const vector<int> &a) {
    for (int i = 0; i < n; ++i) {
        dp[i][0] = dp[i][1] = INFL;
    }
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for (int i = 1; i < n; ++i) {
        if (!eq[i - 1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);
        }
        if (!pl[i - 1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (!mn[i - 1]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);
        }
    }
    return min(dp[n - 1][0], dp[n - 1][1]);
}

void test_case() {
    cin >> n;
    vector<vector<int>> h(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> h[i][j];
        }
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> eq(n - 1), pl(n - 1), mn(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (h[i][j] == h[i + 1][j]) {
                eq[i] = true;
            }
            if (h[i][j] + 1 == h[i + 1][j]) {
                pl[i] = true;
            }
            if (h[i][j] - 1 == h[i + 1][j]) {
                mn[i] = true;
            }
        }
    }
    long long sol = solve(eq, pl, mn, a);
    for (int j = 0; j < n - 1; ++j) {
        eq[j] = pl[j] = mn[j] = false;
        for (int i = 0; i < n; ++i) {
            if (h[i][j] == h[i][j + 1]) {
                eq[j] = true;
            }
            if (h[i][j] + 1 == h[i][j + 1]) {
                pl[j] = true;
            }
            if (h[i][j] - 1 == h[i][j + 1]) {
                mn[j] = true;
            }
        }
    }
    sol += solve(eq, pl, mn, b);
    cout << (sol >= INFL ? -1 : sol) << "\n";
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
