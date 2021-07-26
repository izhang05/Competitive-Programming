/* Author: izhang05
 * Time: 07-25-2021 10:36:09
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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
        }
    }
    int cur = 0;
    for (int i = 1; i < n; ++i) {
        int win = 0;
        for (int j = 0; j < 5; ++j) {
            if (a[i][j] < a[cur][j]) {
                ++win;
            }
        }
        if (win >= 3) {
            cur = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i != cur) {
            int win = 0;
            for (int j = 0; j < 5; ++j) {
                if (a[i][j] < a[cur][j]) {
                    ++win;
                }
            }
            if (win >= 3) {
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << cur + 1 << "\n";
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
