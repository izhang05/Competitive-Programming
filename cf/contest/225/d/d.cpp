/* Author: izhang05
 * Time: 07-14-2021 16:22:45
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int inf = 0x3f3f3f3f, maxn = 16;
char grid[maxn][maxn];
set<long long> visited;

int n, m;

const long long mod = 1e9 + 7, p = 9973;

long long pw[20]; // Stores the powers of p modulo m1

void calc_pow() {
    pw[0] = 1;
    for (int i = 1; i < 20; ++i) {
        pw[i] = (pw[i - 1] * p) % mod;
    }
}

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    setIO("1");
    calc_pow();
    cin >> n >> m;
    deque<pair<int, int>> start;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] >= '1' && grid[i][j] <= '9') {
                int cur = grid[i][j] - '1';
                if ((int) start.size() <= cur) {
                    start.resize(cur + 1);
                }
                start[cur] = {i, j};
                grid[i][j] = '.';
            }
        }
    }
    int sol = inf, len = (int) start.size();
    queue<pair<deque<pair<int, int>>, pair<int, long long>>> q;
    long long hash = 0;
    for (int i = 0; i < len; ++i) {
#ifdef DEBUG
        cout << start[i].first << " " << start[i].second << " " << pw[2 * i] << " " << pw[2 * i + 1] << "\n";
#endif
        hash += start[i].first * pw[2 * i];
        hash %= mod;
#ifdef DEBUG
        cout << hash << "\n";
#endif
        hash += start[i].second * pw[2 * i + 1];
        hash %= mod;
#ifdef DEBUG
        cout << hash << "\n";
#endif
    }
    q.push({start, {0, hash}});
#ifdef DEBUG
    cout << hash << "\n";
#endif
    visited.insert(hash);
    while (!q.empty()) {
        deque<pair<int, int>> cur = q.front().first;
        int dist = q.front().second.first;
        long long cur_hash = q.front().second.second;
        cur_hash -= cur.back().first * pw[2 * len - 2];
        cur_hash %= mod;
        cur_hash -= (long long) cur.back().second * pw[2 * len - 1];
        cur_hash %= mod;
        cur_hash = (cur_hash + mod) % mod;
        cur_hash *= pw[2];
        cur_hash %= mod;
        q.pop();
        cur.pop_back();
        for (int i = 0; i < 4; ++i) {
            int nx = cur[0].first + dx[i], ny = cur[0].second + dy[i];
            if (valid(nx, ny)) {
                if (grid[nx][ny] == '@') {
                    sol = min(sol, dist + 1);
                } else if (grid[nx][ny] == '.' && find(cur.begin(), cur.end(), make_pair(nx, ny)) == cur.end()) {
                    deque<pair<int, int>> next(cur);
                    long long next_hash = cur_hash;
                    next_hash += nx + pw[1] * ny;
                    next_hash %= mod;
                    next.push_front({nx, ny});
                    if (visited.find(next_hash) == visited.end()) {
                        visited.insert(next_hash);
                        q.push({next, {dist + 1, next_hash}});
                    }
                }
            }
        }
    }
    cout << (sol == inf ? -1 : sol) << "\n";
    return 0;
}
