#include<bits/stdc++.h>
using namespace std;

const int mxn = 1e3 + 5;
int n;

const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
map<char, int> dir{{'L', 0}, {'R', 1}, {'U', 2}, {'D', 3}};

int ind(int x, int y) {
    return (x * n) + y;
}

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

char grid[mxn][mxn]{0};
vector<int> adj[mxn * mxn];
bool vis[mxn * mxn];
int res = 0;

void dfs(int v) {
    ++res;
    vis[v] = true;
    for (int c: adj[v]) {
        if (!vis[c]) {
            dfs(c);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int q;
    cin >> n >> q;
    vector<pair<int, int> > que;
    while (q--) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        --x, --y;
        que.emplace_back(x, y);
        grid[x][y] = c;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) {
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (valid(nx, ny)) {
                        adj[ind(nx, ny)].push_back(ind(i, j));
                    } else {
                        adj[n * n].push_back(ind(i, j));
                    }
                }
            } else {
                int nx = i + dx[dir[grid[i][j]]], ny = j + dy[dir[grid[i][j]]];
                if (valid(nx, ny)) {
                    adj[ind(nx, ny)].push_back(ind(i, j));
                } else {
                    adj[n * n].push_back(ind(i, j));
                }
            }
        }
    }
    dfs(n * n);
    vector<int> sol{n * n - (res - 1)};
    reverse(que.begin(), que.end());
    for (auto &i: que) {
        bool new_vis = false;
        for (int j = 0; j < 4; ++j) {
            int nx = i.first + dx[j], ny = i.second + dy[j];
            if (valid(nx, ny)) {
                if (vis[ind(nx, ny)]) {
                    new_vis = true;
                }
                adj[ind(nx, ny)].push_back(ind(i.first, i.second));
            } else {
                new_vis = true;
                adj[n * n].push_back(ind(i.first, i.second));
            }
        }
        if (new_vis && !vis[ind(i.first,i.second)]) {
            dfs(ind(i.first, i.second));
        }
        sol.push_back(n * n - (res - 1));
    }
    sol.pop_back();
    reverse(sol.begin(), sol.end());
    for (int i: sol) {
        cout << i << "\n";
    }
}
