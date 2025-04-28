#include<bits/stdc++.h>

using namespace std;

const int mxn = 1e3 + 5;

bool star[mxn][mxn];
char grid[mxn][mxn];

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    swap(a, b);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            star[i][j] = false;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'B') {
                star[i][j] = true;
                if (i - a < 0 || j - b < 0) {
                    cout << -1 << "\n";
                    return;
                }
                star[i - a][j - b] = true;
            }
            if (grid[i][j] == 'G') {
                if (i - a < 0 || j - b < 0 || !star[i - a][j - b]) {
                    star[i][j] = true;
                }
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sol += star[i][j];
            if (star[i][j] && grid[i][j] == 'W') {
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}