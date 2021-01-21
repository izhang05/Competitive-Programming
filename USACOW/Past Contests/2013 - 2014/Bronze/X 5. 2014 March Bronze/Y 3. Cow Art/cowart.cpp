/*
ID: izhang01
TASK: cowart
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowart.in", "r", stdin);
    freopen("cowart.out", "w", stdout);
}

const int maxn = 100;

vector<char> grid[maxn];
vector<int> adj[maxn * maxn];
bool visited[maxn * maxn];


void dfs(int n) {
    visited[n] = true;
    for (int i : adj[n]) {
        if (!visited[i]) {
            dfs(i);
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
            grid[i].push_back(s[j]);
        }
    }
    for (int i = 1; i < n; ++i) {
        if (grid[0][i - 1] == grid[0][i]) {
            adj[i - 1].push_back(i);
            adj[i].push_back(i - 1);
        }
    }
    for (int i = 1; i < n; ++i) {
        if (grid[i - 1][0] == grid[i][0]) {
            adj[(i - 1) * n].push_back(i * n);
            adj[i * n].push_back((i - 1) * n);
        }
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == grid[i - 1][j]) {
                adj[(i - 1) * n + j].push_back(i * n + j);
                adj[i * n + j].push_back((i - 1) * n + j);
            }
            if (grid[i][j] == grid[i][j - 1]) {
                adj[i * n + j].push_back(i * n + j - 1);
                adj[i * n + j - 1].push_back(i * n + j);
            }
        }
    }
    for (int i = 0; i < n * n; ++i) {
        visited[i] = false;
    }
    int sol = 0;
    for (int i = 0; i < n * n; ++i) {
        if (!visited[i]) {
            ++sol;
            dfs(i);
        }
    }
    cout << sol << " ";

    adj->clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'G') {
                grid[i][j] = 'R';
            }
        }
    }
//    for (auto i : grid) {
//        if (i.size() == 0) {
//            break;
//        }
//        for (auto j : i) {
//            cout << j;
//        }
//        cout << "\n";
//    }

    for (int i = 1; i < n; ++i) {
        if (grid[0][i - 1] == grid[0][i]) {
            adj[i - 1].push_back(i);
            adj[i].push_back(i - 1);
        }
    }
    for (int i = 1; i < n; ++i) {
        if (grid[i - 1][0] == grid[i][0]) {
            adj[(i - 1) * n].push_back(i * n);
            adj[i * n].push_back((i - 1) * n);
        }
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == grid[i - 1][j]) {
                adj[(i - 1) * n + j].push_back(i * n + j);
                adj[i * n + j].push_back((i - 1) * n + j);
            }
            if (grid[i][j] == grid[i][j - 1]) {
                adj[i * n + j].push_back(i * n + j - 1);
                adj[i * n + j - 1].push_back(i * n + j);
            }
        }
    }
    for (int i = 0; i < n * n; ++i) {
        visited[i] = false;
    }
    sol = 0;
    for (int i = 0; i < n * n; ++i) {
        if (!visited[i]) {
            ++sol;
            dfs(i);
        }
    }
    cout << sol << "\n";
    return 0;
}
