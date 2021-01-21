#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//    freopen("solution.out", "w", stdout);
    freopen("4.in", "r", stdin);
#endif
    int n, m, black = 0;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }
    int min_row = m - 1, max_row = 0, min_col = n - 1, max_col = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'B') {
                ++black;
                min_col = min(min_col, i);
                max_col = max(max_col, i);
                min_row = min(min_row, j);
                max_row = max(max_row, j);
            }
        }
    }
    int length = max_row - min_row + 1, height = max_col - min_col + 1;
    if (black == 0) {
        cout << 1 << "\n";
    } else if (length == height) {
        cout << length * height - black << "\n";
    } else if (length > height) {
        if (n >= length) {
            cout << length * length - black << "\n";
        } else {
            cout << -1 << "\n";
        }
    } else {
        if (m >= height) {
            cout << height * height - black << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
