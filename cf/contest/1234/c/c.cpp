/* Author: izhang05
 * Time: 07-02-2021 21:35:27
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
    vector<vector<int>> grid(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j] - '0';
        }
    }
    pair<int, int> loc = {0, 0};
    while (true) {
        int cur = grid[loc.first][loc.second];
        if (cur <= 2) {
            ++loc.second;
            if (loc.second >= n) {
                if (loc.first == 0) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                }
                return;
            }
        } else {
            loc.first ^= 1;
            if (grid[loc.first][loc.second] <= 2) {
                cout << "NO"
                     << "\n";
                return;
            } else {
                ++loc.second;
                if (loc.second >= n) {
                    if (loc.first == 0) {
                        cout << "NO\n";
                    } else {
                        cout << "YES\n";
                    }
                    return;
                }
            }
        }
    }
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
