#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > grid(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
        vector<vector<int> > sol(n, vector<int> (m));
        sol[0][0] = 2;
        for (int i = 1; i < m - 1; ++i) {
            sol[0][i] = 3;
        }
        sol[0][m - 1] = 2;
        for (int i = 1; i < n - 1; ++i) {
            sol[i][0] = 3;
            for (int j = 1; j < m - 1; ++j) {
                sol[i][j] = 4;
            }
            sol[i][m - 1] = 3;
        }
        sol[n - 1][0] = 2;
        for (int i = 1; i < m - 1; ++i) {
            sol[n - 1][i] = 3;
        }
        sol[n - 1][m - 1] = 2;
        bool pos = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > sol[i][j]) {
                    pos = false;
                    cout << "NO" << "\n";
                    break;
                }
            }
            if (!pos) {
                break;
            }
        }
        if (pos) {
            cout << "YES" << "\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << sol[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
