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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int points(int a, int b) {
    int d = abs(a - b);
    if (d <= 15) {
        return 7;
    }
    if (d <= 23) {
        return 6;
    }
    if (d <= 43) {
        return 4;
    }
    if (d <= 102) {
        return 2;
    }
    return 0;
}

int dp[2][mxn];

void test_case() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[1][j] = dp[0][j];
            if (j != 0) {
                dp[1][j] = max(dp[1][j], dp[0][j - 1] + points(a[j - 1], b[i]));
                dp[1][j] = max(dp[1][j], dp[1][j - 1]);
            }
        }
        swap(dp[0], dp[1]);
    }
    int sol = 0;
    for (int i = 0; i <= n; ++i) {
        sol = max(sol, dp[0][i]);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
