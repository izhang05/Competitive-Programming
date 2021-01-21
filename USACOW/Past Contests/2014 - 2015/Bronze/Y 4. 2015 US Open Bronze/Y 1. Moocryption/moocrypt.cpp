/*
ID: izhang01
TASK: moocrypt
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("moocrypt.in", "r", stdin);
    freopen("moocrypt.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    map<pair<char, char>, int> occur;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + 2 < n) {
                char first = grid[i][j];
                if (grid[i + 1][j] == first) {
                    if (grid[i + 2][j] != first) {
                        pair<char, char> p = pair<char, char>{grid[i + 2][j], grid[i][j]};
//                        cout << p.first << " " << p.second << " " << i << " " << j << "\n";
                        if (!occur.count(p)) {
                            occur[p] = 1;
                        } else {
                            ++occur[p];
                        }
                    }
                } else {
                    if (grid[i + 1][j] == grid[i + 2][j]) {
                        pair<char, char> p = pair<char, char>{grid[i][j], grid[i + 1][j]};
//                        cout << p.first << " " << p.second << " " << i << " " << j << "\n";
                        if (!occur.count(p)) {
                            occur[p] = 1;
                        } else {
                            ++occur[p];
                        }
                    }
                }
            }
            if (j + 2 < m) {
                char first = grid[i][j];
                if (grid[i][j + 1] == first) {
                    if (grid[i][j + 2] != first) {
                        pair<char, char> p = pair<char, char>{grid[i][j + 2], grid[i][j]};
//                        cout << p.first << " " << p.second << " " << i << " " << j << "\n";
                        if (!occur.count(p)) {
                            occur[p] = 1;
                        } else {
                            ++occur[p];
                        }
                    }
                } else {
                    if (grid[i][j + 1] == grid[i][j + 2]) {
                        pair<char, char> p = pair<char, char>{grid[i][j], grid[i][j + 1]};
//                        cout << p.first << " " << p.second << " " << i << " " << j << "\n";
                        if (!occur.count(p)) {
                            occur[p] = 1;
                        } else {
                            ++occur[p];
                        }
                    }
                }
            }
            if (i + 2 < n && j + 2 < m) {
                char first = grid[i][j];
                if (grid[i + 1][j + 1] == first) {
                    if (grid[i + 2][j + 2] != first) {
                        pair<char, char> p = pair<char, char>{grid[i + 2][j + 2], grid[i][j]};
//                        cout << p.first << " " << p.second << " " << i << " " << j << "\n";
                        if (!occur.count(p)) {
                            occur[p] = 1;
                        } else {
                            ++occur[p];
                        }
                    }
                } else {
                    if (grid[i + 1][j + 1] == grid[i + 2][j + 2]) {
                        pair<char, char> p = pair<char, char>{grid[i][j], grid[i + 1][j + 1]};
//                        cout << p.first << " " << p.second << " " << i << " " << j << "\n";
                        if (!occur.count(p)) {
                            occur[p] = 1;
                        } else {
                            ++occur[p];
                        }
                    }
                }
            }
            if (i + 2 < n && j - 2 >= 0) {
                char first = grid[i][j];
                if (grid[i + 1][j - 1] == first) {
                    if (grid[i + 2][j - 2] != first) {
                        pair<char, char> p = pair<char, char>{grid[i + 2][j - 2], grid[i][j]};
//                        cout << p.first << " " << p.second << " " << i << " " << j << "\n";
                        if (!occur.count(p)) {
                            occur[p] = 1;
                        } else {
                            ++occur[p];
                        }
                    }
                } else {
                    if (grid[i + 1][j - 1] == grid[i + 2][j - 2]) {
                        pair<char, char> p = pair<char, char>{grid[i][j], grid[i + 1][j - 1]};
//                        cout << p.first << " " << p.second << " " << i << " " << j << "\n";
                        if (!occur.count(p)) {
                            occur[p] = 1;
                        } else {
                            ++occur[p];
                        }
                    }
                }
            }
        }
    }
    int sol = 0;
    for (auto const &j : occur) {
        sol = max(sol, j.second);
    }
    cout << sol << "\n";
    return 0;
}
