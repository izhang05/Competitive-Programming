#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1000;
bool blocked[maxn][maxn], visited[maxn][maxn];

int n, m;
bool solved = false;
pair<int, int> start, goal, parent[maxn][maxn];
char sol[maxn][maxn];


void bfs() {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    parent[start.first][start.second] = pair<int, int>{-1, -1};
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (goal.first == x && goal.second == y) {
            solved = true;
            return;
        }
        if (x > 0) {
            if (!blocked[x - 1][y] && !visited[x - 1][y]) {
                q.push(pair<int, int>{x - 1, y});
                sol[x - 1][y] = 'U';
                parent[x - 1][y] = pair<int, int>{x, y};
                visited[x - 1][y] = true;
            }
        }
        if (x < n - 1) {
            if (!blocked[x + 1][y] && !visited[x + 1][y]) {
                q.push(pair<int, int>{x + 1, y});
                sol[x + 1][y] = 'D';
                parent[x + 1][y] = pair<int, int>{x, y};
                visited[x + 1][y] = true;
            }
        }
        if (y > 0) {
            if (!blocked[x][y - 1] && !visited[x][y - 1]) {
                q.push(pair<int, int>{x, y - 1});
                sol[x][y - 1] = 'L';
                parent[x][y - 1] = pair<int, int>{x, y};
                visited[x][y - 1] = true;
            }
        }
        if (y < m - 1) {
            if (!blocked[x][y + 1] && !visited[x][y + 1]) {
                q.push(pair<int, int>{x, y + 1});
                sol[x][y + 1] = 'R';
                parent[x][y + 1] = pair<int, int>{x, y};
                visited[x][y + 1] = true;
            }
        }
    }
}

int main() {
    setIO();

    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '#') {
                blocked[i][j] = true;
            } else if (s[j] == 'A') {
                start = pair<int, int>{i, j};
            } else if (s[j] == 'B') {
                goal = pair<int, int>{i, j};
            }
        }
    }
    bfs();
    if (!solved) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
        stack<char> path;
        while (parent[goal.first][goal.second] != pair<int, int>{-1, -1}) {
            path.push(sol[goal.first][goal.second]);
            goal = parent[goal.first][goal.second];
        }
        cout << path.size() << "\n";
        while (!path.empty()) {
            cout << path.top();
            path.pop();
        }
        cout << "\n";
    }
    return 0;
}
