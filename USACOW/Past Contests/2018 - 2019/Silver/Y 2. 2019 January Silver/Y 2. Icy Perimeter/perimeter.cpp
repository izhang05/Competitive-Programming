/*
ID: izhang01
TASK: perimeter
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
}

const int maxn = 1000;
vector<vector<int> > adj(maxn * maxn);
bool visited[maxn * maxn];
pair<int, int> sol;
int perim, area;

void dfs(int n) {
    ++area;
    perim += 4 - (int) adj[n].size();
    visited[n] = true;
    for (int j : adj[n]) {
        if (!visited[j]) {
            dfs(j);
        }
    }
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<vector<char> > grid(n, vector<char>(n));
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j];
        }
    }
    for (int i = 1; i < n; ++i) {
        if (grid[0][i] == '#' && grid[0][i - 1] == '#') {
            adj[i].push_back(i - 1);
            adj[i - 1].push_back(i);
        }
    }
    for (int i = 1; i < n; ++i) {
        if (grid[i][0] == '#' && grid[i - 1][0] == '#') {
            adj[i * n].push_back((i - 1) * n);
            adj[(i - 1) * n].push_back(i * n);
        }
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == '#') {
                if (grid[i - 1][j] == '#') {
                    adj[i * n + j].push_back((i - 1) * n + j);
                    adj[(i - 1) * n + j].push_back(i * n + j);
                }
                if (grid[i][j - 1] == '#') {
                    adj[i * n + j].push_back(i * n + j - 1);
                    adj[i * n + j - 1].push_back(i * n + j);
                }
            }
        }
    }
    for (int i = 0; i < n * n; ++i) {
        if (!visited[i]) {
            perim = 0, area = 0;
            dfs(i);
            if (area > sol.first) {
                sol.first = area;
                sol.second = perim;
            } else if (area == sol.first) {
                if (perim < sol.second) {
                    sol.second = perim;
                }
            }
        }
    }
    cout << sol.first << " " << sol.second << "\n";
    return 0;
}
