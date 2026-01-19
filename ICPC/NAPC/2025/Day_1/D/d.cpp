#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<pair<int, int>> path;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                path.emplace_back(i, j);
            }
        } else {
            for (int j = n - 1; j >= 0; --j) {
                path.emplace_back(i, j);
            }
        }
    }
    int inc = 0, dec = 0;
    for (int i = 1; i < n * n; ++i) {
        if (grid[path[i].first][path[i].second] > grid[path[i - 1].first][path[i - 1].second]) {
            ++inc;
        } else {
            ++dec;
        }
    }
    if (inc > dec) {
        reverse(path.begin(), path.end());
    }
    for (int i = 0; i < n * n; ++i) {
        cout << grid[path[i].first][path[i].second] << " ";
    }
    cout << "\n";
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}
