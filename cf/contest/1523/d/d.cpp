/* Author: izhang
 * Time: 01-20-2022 18:04:08
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, maxm = 65;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool grid[maxn][maxm];
int cnt[maxm];

void test_case() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = s[j] - '0';
            cnt[j] += grid[i][j];
        }
    }

}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
