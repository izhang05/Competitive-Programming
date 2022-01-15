/* Author: izhang
 * Time: 01-15-2022 09:35:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 55;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
char grid[maxn][maxn];

void test_case() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    --r, --c;
    bool none = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'B') {
                none = false;
            }
        }
    }
    if (grid[r][c] == 'B') {
        cout << 0 << "\n";
        return;
    }
    if (none) {
        cout << -1 << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (grid[i][c] == 'B') {
            cout << 1 << "\n";
            return;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (grid[r][i] == 'B') {
            cout << 1 << "\n";
            return;
        }
    }
    cout << 2 << "\n";
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
