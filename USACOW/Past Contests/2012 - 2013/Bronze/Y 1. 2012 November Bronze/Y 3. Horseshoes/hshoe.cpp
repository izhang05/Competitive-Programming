/*
ID: izhang01
TASK: hshoe
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hshoe.in", "r", stdin);
    freopen("hshoe.out", "w", stdout);
}

const int maxn = 5;
char grid[maxn][maxn];
bool visited[maxn][maxn];
vector<pair<int, int> > adj[maxn][maxn];
int sol;

void dfs(int x, int y, char cur, int len, int remain) {
    if (cur == ')' && remain == 0) {
        sol = max(sol, len * 2);
//        for (int i = 0; i < 4; ++i) {
//            for (int j = 0; j < 4; ++j) {
//                if (visited[i][j]) {
//                    cout << i << " " << j << "\n";
//                }
//            }
//        }
//        cout << len << "\n";
//        cout << "\n";
        return;
    }
    for (pair<int, int> i : adj[x][y]) {
        if (!visited[i.first][i.second]) {
            visited[i.first][i.second] = true;
            if (cur == '(') {
                if (grid[i.first][i.second] == '(') {
                    dfs(i.first, i.second, cur, len + 1, remain);
                } else {
                    dfs(i.first, i.second, ')', len, len - 1);
                }
            } else {
                if (grid[i.first][i.second] == '(') {
                    visited[i.first][i.second] = false;
                    continue;
                } else {
                    dfs(i.first, i.second, cur, len, remain - 1);
                }
            }
            visited[i.first][i.second] = false;
        }
    }
}


int main() {
    setIO();
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j];
        }
    }

    for (int i = 1; i < n; ++i) {
        adj[0][i].emplace_back(0, i - 1);
        adj[0][i - 1].emplace_back(0, i);
    }
    for (int i = 1; i < n; ++i) {
        adj[i][0].emplace_back(i - 1, 0);
        adj[i - 1][0].emplace_back(i, 0);
        for (int j = 1; j < n; ++j) {
            adj[i][j].emplace_back(i - 1, j);
            adj[i - 1][j].emplace_back(i, j);
            adj[i][j].emplace_back(i, j - 1);
            adj[i][j - 1].emplace_back(i, j);
        }
    }
    if (grid[0][0] == ')') {
        cout << 0 << "\n";
        return 0;
    }
    visited[0][0] = true;
    dfs(0, 0, '(', 1, 0);
    cout << sol << "\n";

    return 0;
}
