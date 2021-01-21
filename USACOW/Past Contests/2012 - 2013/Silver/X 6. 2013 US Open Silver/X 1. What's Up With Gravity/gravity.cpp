/*
ID: izhang01
TASK: gravity
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("gravity.in", "r", stdin);
    freopen("gravity.out", "w", stdout);
}
const int maxn = 500, inf = 0x3f3f3f3f;
int dist[maxn][maxn][2];
char grid[maxn][maxn];
set<int> points[maxn];

template<class T>
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    memset(dist, 0x3f, sizeof(dist));
    deque<pair<pair<int, int>, int>> q;
    pair<int, int> destination;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'C') {
                q.push_front(make_pair(make_pair(i, j), dist[i][j][0] = 0));
                grid[i][j] = '.';
            } else if (grid[i][j] == 'D') {
                destination = make_pair(i, j);
                grid[i][j] = '.';
            } else if (grid[i][j] == '#') {
                points[j].insert(i);
            }
        }
    }
    while (!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        q.pop_front();
        pair<int, int> cur_pos = cur.first;
        int cur_dir = cur.second, cur_dist = dist[cur_pos.first][cur_pos.second][cur_dir];
        cout << cur_pos.first << " " << cur_pos.second << " " << cur_dir << " " << cur_dist << "\n";
        auto it = points[cur_pos.second].lower_bound(cur_pos.first);
        if (cur_dir == 0) { // gravity goes down
            // flip gravity
            try {
                if (it != points[cur_pos.second].end() && it != points[cur_pos.second].begin()) { // exists cell above
                    if (dist[*prev(it) + 1][cur_pos.second][1] > cur_dist + 1) {
                        q.emplace_back(make_pair(*prev(it) + 1, cur_pos.second), dist[*prev(it) + 1][cur_pos.second][1] = cur_dist + 1);
                    }
                }
            } catch (...) {
            }
            // move right
            auto next_it = points[cur_pos.second + 1].lower_bound(cur_pos.first);
            if (next_it != points[cur_pos.second + 1].end() && *next_it != cur_pos.first) { // cell not occupied and exists occupied cell below
                if (dist[*next_it][cur_pos.second + 1][0] > cur_dist) {
                    q.emplace_back(make_pair(*next_it, cur_pos.second + 1), dist[*next_it][cur_pos.second + 1][0] = cur_dist);
                }
            }
            // move left
            if (cur_pos.second != 0) {
                next_it = points[cur_pos.second - 1].lower_bound(cur_pos.first);
                if (next_it != points[cur_pos.second - 1].end() && *next_it != cur_pos.first) { // cell not occupied and exists occupied cell below
                    if (dist[*next_it][cur_pos.second - 1][0] > cur_dist) {
                        q.emplace_back(make_pair(*next_it, cur_pos.second - 1), dist[*next_it][cur_pos.second - 1][0] = cur_dist);
                    }
                }
            }
        } else { // gravity goes up
            // flip gravity
            if (it != points[cur_pos.second].begin()) {
                if (dist[*prev(it)][cur_pos.second][0] > cur_dist + 1) {
                    q.emplace_back(make_pair(*prev(it), cur_pos.second), dist[*prev(it)][cur_pos.second][0] = cur_dist + 1);
                }
            }
            // move right
            auto next_it = points[cur_pos.second + 1].lower_bound(cur_pos.first);
            if (next_it != points[cur_pos.second + 1].end() && next(next_it) != points[cur_pos.second + 1].end() && *next_it != cur_pos.first) { // cell not occupied and exists occupied cell above
                if (dist[*next(next_it)][cur_pos.second + 1][1] > cur_dist) {
                    q.emplace_back(make_pair(*next(next_it), cur_pos.second + 1), dist[*next(next_it)][cur_pos.second + 1][1] = cur_dist);
                }
            }
            // move left
            if (cur_pos.second != 0) {
                next_it = points[cur_pos.second - 1].lower_bound(cur_pos.first);
                if (next_it != points[cur_pos.second - 1].end() && next(next_it) != points[cur_pos.second - 1].end() && *next_it != cur_pos.first) { // cell not occupied and exists occupied cell below
                    if (dist[*next(next_it)][cur_pos.second - 1][0] > cur_dist) {
                        q.emplace_back(make_pair(*next(next_it), cur_pos.second - 1), dist[*next(next_it)][cur_pos.second - 1][0] = cur_dist);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 2; ++k) {
                cout << i << " " << j << " " << k << " " << dist[i][j][k] << "\n";
            }
        }
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {

        print(points[i]);
    }
    cout << max(dist[destination.first][destination.second][0], dist[destination.first][destination.second][1]) << "\n";
    return 0;
}
