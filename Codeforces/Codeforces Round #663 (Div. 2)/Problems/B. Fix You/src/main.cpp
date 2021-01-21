#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        char grid[n][m];
        bool visited[n][m];
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                grid[i][j] = s[j];
                visited[i][j] = false;
            }
        }
        map<char, int> row{{'R', 0},
                           {'L', 0},
                           {'D', 1},
                           {'U', -1}};
        map<char, int> col{{'R', 1},
                           {'L', -1},
                           {'D', 0},
                           {'U', 0}};
        int sol = 0;
        queue<pair<int, int> > q;
        visited[n - 1][m - 1] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j]) {
                    q.push({i, j});
                    bool comp = true;
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        pair<int, int> next = {cur.first + row[grid[cur.first][cur.second]],
                                               cur.second + col[grid[cur.first][cur.second]]};
                        if (next.first < n && next.second < m && next.first >= 0 && next.second >= 0) {
                            if (visited[next.first][next.second]) {
                                comp = false;
                            } else {
                                q.push(next);
                                visited[next.first][next.second] = true;
                            }
                        }
                    }
                    if (comp) {
                        ++sol;
//                        cout << i << " " << j << "\n";
                    }
                }
            }
        }
        cout << sol << endl;
    }
    return 0;
}
