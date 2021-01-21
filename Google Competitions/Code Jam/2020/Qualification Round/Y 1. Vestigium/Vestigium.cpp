#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int grid[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        k += grid[i][i];
    }
    cout << k << " ";
    int r = 0;
    for (int i = 0; i < n; ++i) {
        unordered_set<int> s;
        for (int j = 0; j < n; ++j) {
            if (s.find(grid[i][j]) == s.end()) {
                s.insert(grid[i][j]);
            } else {
                ++r;
                break;
            }
        }
    }
    cout << r << " ";
    int c = 0;
    for (int i = 0; i < n; ++i) {
        unordered_set<int> s;
        for (int j = 0; j < n; ++j) {
            if (s.find(grid[j][i]) == s.end()) {
                s.insert(grid[j][i]);
            } else {
                ++c;
                break;
            }
        }
    }
    cout << c << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
