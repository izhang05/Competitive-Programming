/*
ID: izhang01
TASK: tttt
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
}


int main() {
    setIO();
    int n = 3;
    char grid[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    set<set<char> > one, two;
    for (int i = 0; i < n; ++i) { // horizontal
        set<char> cows;
        for (int j = 0; j < n; ++j) {
            cows.insert(grid[i][j]);
        }
        if (cows.size() == 1) {
            one.insert(cows);
        } else if (cows.size() == 2) {
            two.insert(cows);
        }
    }
    for (int i = 0; i < n; ++i) { // vertical
        set<char> cows;
        for (int j = 0; j < n; ++j) {
            cows.insert(grid[j][i]);
        }
        if (cows.size() == 1) {
            one.insert(cows);
        } else if (cows.size() == 2) {
            two.insert(cows);
        }
    }
    set<char> cows;
    for (int i = 0; i < n; ++i) {
        cows.insert(grid[i][i]);
    }
    if (cows.size() == 1) {
        one.insert(cows);
    } else if (cows.size() == 2) {
        two.insert(cows);
    }
    cows.clear();
    cows.insert(grid[0][2]);
    cows.insert(grid[1][1]);
    cows.insert(grid[2][0]);
    if (cows.size() == 1) {
        one.insert(cows);
    } else if (cows.size() == 2) {
        two.insert(cows);
    }
    cout << one.size() << "\n";
    cout << two.size() << "\n";
    return 0;
}
