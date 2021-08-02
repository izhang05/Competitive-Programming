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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, k = 450, maxn = 2e5 + 5;
int pre[3][maxn][3];

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < 3; ++l) {
                pre[i][j][l] = pre[i][max(0, j - 1)][l];
            }
            if (s[j] == i + 'a') {
                ++pre[i][j][j % 3];
            }
        }
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        vector<int> order{0, 1, 2};
        int sol = r - l + 1;
        do {
            int cur = 0;
            for (int i = 0; i < 3; ++i) {
                cur += pre[order[i]][r][i];
                if (l) {
                    cur -= pre[order[i]][l - 1][i];
                }
            }
            sol = min(sol, r - l + 1 - cur);
        } while (next_permutation(order.begin(), order.end()));
        cout << sol << "\n";
    }
    return 0;
}
