/* Author: izhang05
 * Time: 09-15-2021 14:00:08
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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '2') {
            ++cnt;
        }
    }
    if (cnt > 0 && cnt <= 2) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = 'X';
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    grid[i][j] = '=';
                }
            }
        } else {
            bool found = false;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    if (!found) {
                        if (s[j] == '2' && grid[i][j] == 'X') {
                            grid[i][j] = '+';
                            grid[j][i] = '-';
                            found = true;
                        } else if (grid[i][j] == 'X') {
                            grid[i][j] = '=';
                        }
                    } else if (grid[i][j] == 'X') {
                        grid[i][j] = '=';
                    }
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
