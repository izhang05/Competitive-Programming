/* Author: izhang
 * Time: 01-18-2022 22:55:17
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;

const long long INFL = 0x3f3f3f3f3f3f3f3f;

int grid[maxn][maxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (grid[a][b]) {
            cout << "NO"
                 << "\n";
            return;
        }
        ++grid[a][b];
        for (auto &j : {-1, 0, 1}) {
            for (auto &k : {-1, 0, 1}) {
                if (!(j == 0 && k == 0)) {
                    if (grid[a + j][b + k]) {
                        cout << "NO"
                             << "\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "YES"
         << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
