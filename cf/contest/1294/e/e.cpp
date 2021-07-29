/* Author: izhang05
 * Time: 07-29-2021 15:08:47
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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
    }
    int sol = 0;
    for (int col = 0; col < m; ++col) {
        map<int, int> cnt;
        for (int row = 0; row < n; ++row) {
            if (a[row][col] % m == col && a[row][col] < n * m) {
                int ind = (a[row][col] - col) / m;
                ++cnt[(row - ind + n) % n];
            }
        }
        int cur = n;
        for (auto &i : cnt) {
            cur = min(cur, i.first + n - i.second);
        }
        sol += cur;
    }
    cout << sol << "\n";
    return 0;
}
