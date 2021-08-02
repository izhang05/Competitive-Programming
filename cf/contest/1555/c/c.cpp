/* Author: izhang05
 * Time: 07-30-2021 10:35:04
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<vector<int>> a(2, vector<int>(m));
        vector<vector<int>> pre(2, vector<int>(m));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                pre[i][j] = pre[i][max(0, j - 1)] + a[i][j];
            }
        }
        int sol = inf;
        int up_rem = pre[0][m - 1] - a[0][0], down_rem = 0;
        for (int i = 0; i < m; ++i) {
            sol = min(sol, max(up_rem, down_rem));
            up_rem -= a[0][min(m - 1, i + 1)], down_rem += a[1][i];
        }
        cout << sol << "\n";
    }
    return 0;
}
