/* Author: izhang
 * Time: 01-22-2022 09:35:03
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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int n;
bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}
int grid[maxn][maxn], cnt[maxn][maxn];

void test_case() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            cnt[i][j] = 0;
        }
    }
    int sol = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (cnt[i - 1][j] % 2 == 0) {
                sol ^= grid[i][j];
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (valid(nx, ny)) {
                        ++cnt[nx][ny];
                    }
                }
            }
        }
    }
    cout << sol << "\n";
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
