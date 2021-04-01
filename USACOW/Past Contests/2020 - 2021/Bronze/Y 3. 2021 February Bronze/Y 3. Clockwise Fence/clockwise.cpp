#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//#define DEBUG
const int maxn = 500;
bool fence[maxn][maxn], visited[maxn][maxn];
map<char, int> dir{{'S', 0}, {'E', 1}, {'N', 2}, {'W', 3}};

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < maxn && y < maxn && !fence[x][y];
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny) && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    setIO();
    int t;
    cin >> t;
    while (t--) {
        memset(fence, false, sizeof(fence));
        memset(visited, false, sizeof(visited));
        string s;
        cin >> s;
        int n = s.size();
        pair<int, int> pos{250, 250};
        fence[pos.first][pos.second] = true;
        for (int i = 0; i < n; ++i) {
            int d = dir[s[i]];
            for (int j = 0; j < 2; ++j) {
                pos = {pos.first + dx[d], pos.second + dy[d]};
                fence[pos.first][pos.second] = true;
            }
        }
        dfs(0, 0);
        int x = 250, y = 250;
        if (s[0] == 'N') {
            if (visited[x - 1][y + 1]) {
                cout << "CCW"
                     << "\n";
            } else {
                cout << "CW"
                     << "\n";
            }

        } else if (s[0] == 'W') {
            if (visited[x - 1][y - 1]) {
                cout << "CCW"
                     << "\n";
            } else {
                cout << "CW"
                     << "\n";
            }

        } else if (s[0] == 'E') {
            if (visited[x - 1][y + 1]) {
                cout << "CW"
                     << "\n";
            } else {
                cout << "CCW"
                     << "\n";
            }
        } else if (s[0] == 'S') {
            if (visited[x + 1][y - 1]) {
                cout << "CCW"
                     << "\n";
            } else {
                cout << "CW"
                     << "\n";
            }
        }
    }


    return 0;
}
