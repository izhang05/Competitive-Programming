#include <bits/stdc++.h>

using namespace std;
int n, m, far[25][25], solution;
char grid[25][25];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            if (grid[i][j] == '1') {
                far[i][j] = j - 1;
            } else if (j == m - 1) {
                far[i][j] = j;
            } else {
                far[i][j] = far[i][j + 1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int dist = 1e9;
            for (int k = i; k < n && grid[k][j] == '0'; ++k) {
                dist = min(dist, far[k][j]);
                solution = max(solution, 2 * (k - i + 1 + dist - j + 1));
            }
        }
    }
    cout << solution << "\n";

    return 0;
}