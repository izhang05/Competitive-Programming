/* Author: izhang
 * Time: 01-27-2022 22:54:14
**/
#include <bits/stdc++.h>

using namespace std;

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 305;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool sol[maxn][maxn];

void test_case() {
    int n, k;
    cin >> n >> k;
    memset(sol, 0, sizeof(sol));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n && k; ++j, --k) {
            sol[j][(j + i) % n] = true;
        }
    }
    int mn_row = inf, mn_col = inf, mx_row = 0, mx_col = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            cur += sol[i][j];
        }
        mn_row = min(mn_row, cur);
        mx_row = max(mx_row, cur);
    }
    for (int j = 0; j < n; ++j) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += sol[i][j];
        }
        mn_col = min(mn_col, cur);
        mx_col = max(mx_col, cur);
    }
    cout << (mx_row - mn_row) * (mx_row - mn_row) + (mx_col - mn_col) * (mx_col - mn_col) << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << sol[i][j];
        }
        cout << "\n";
    }
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
