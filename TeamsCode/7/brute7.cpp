#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
//    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e3 + 5;

int grid[maxn][maxn];

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }
        int sol = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = i; k < n; ++k) {
                    for (int l = j; l < n; ++l) {
                        bool good = true;
                        for (int col = j; col <= l && good; ++col) {
                            int last = grid[i][col];
                            for (int m = i + 1; m <= k && good; ++m) {
                                if (grid[m][col] != last) {
                                    good = false;
                                }
                            }
                        }
                        if (good) {
                            sol = max(sol, (k - i + 1) * (l - j + 1));
                        }
                    }
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
