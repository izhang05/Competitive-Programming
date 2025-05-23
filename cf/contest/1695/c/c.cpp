/* Author: izhang
 * Time: 01-02-2024 15:29:12
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
int grid[mxn][mxn], mn[mxn][mxn], mx[mxn][mxn];

void test_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    if ((n + m) % 2 == 0) {
        cout << "NO"
             << "\n";
        return;
    }
    mn[0][0] = mx[0][0] = grid[0][0];
    for (int i = 1; i < n; ++i) {
        mn[i][0] = mx[i][0] = grid[i][0] + mn[i - 1][0];
    }
    for (int i = 0; i < m; ++i) {
        mn[0][i] = mx[0][i] = grid[0][i] + mn[0][i - 1];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            mn[i][j] = grid[i][j] + min(mn[i - 1][j], mn[i][j - 1]);
            mx[i][j] = grid[i][j] + max(mx[i - 1][j], mx[i][j - 1]);
        }
    }
    cout << (mn[n - 1][m - 1] <= 0 && mx[n - 1][m - 1] >= 0 ? "YES" : "NO") << "\n";
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
