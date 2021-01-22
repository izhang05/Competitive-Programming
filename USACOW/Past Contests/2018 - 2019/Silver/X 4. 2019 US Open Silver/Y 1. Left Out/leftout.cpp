/*
ID: izhang01
TASK: leftout
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("leftout.in", "r", stdin);
    freopen("leftout.out", "w", stdout);
}
const int maxn = 1e3 + 5;
bool grid[maxn][maxn];
bool flip_col[maxn], flip_row[maxn];

bool state(int i, int j) {
    return grid[i][j] ^ flip_row[i] ^ flip_col[j];
}

int main() {
    setIO();
    int n;
    cin >> n;
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c;
            if (c == 'R') {
                grid[i][j] = true;
            }
        }
    }
    if (n == 2) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ++count;
                }
            }
        }
        if (count % 2 == 0) {
            cout << -1 << "\n";
        } else {
            cout << 1 << " " << 1 << "\n";
        }
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (grid[0][i]) {
            flip_col[i] = true;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (grid[i][0] ^ flip_col[0]) {
            flip_row[i] = true;
        }
    }
    if (state(1, 1) && state(1, 2) && state(2, 1) && state(2, 2)) {
        cout << 1 << " " << 1 << "\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (state(1, i) && state(2, i)) {
            cout << 1 << " " << i + 1 << "\n";
            return 0;
        }
        if (state(i, 1) && state(i, 2)) {
            cout << i + 1 << " " << 1 << "\n";
            return 0;
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (state(i, j)) {
                ++count;
            }
        }
    }
    if (count > 1) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (state(i, j)) {
                cout << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
