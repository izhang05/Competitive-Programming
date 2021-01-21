#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
void print(T a) {
    for (auto i : a) {
        cout << i;
    }
    cout << "\n";
}

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("Y 7.in", "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
int monster_dist[maxn][maxn], sol[maxn][maxn], n, m;
bool blocked[maxn][maxn];
pair<pair<int, int>, char> parent[maxn][maxn];

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool edge(int x, int y) {
    return x == 0 || y == 0 || x == n - 1 || y == m - 1;
}

int main() {
    setIO();
    cin >> n >> m;
    pair<int, int> start;
    memset(sol, 0x3f, sizeof(sol));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            monster_dist[i][j] = inf;
            char a;
            cin >> a;
            if (a == 'M') {
                q.push({i, j});
                monster_dist[i][j] = 0;
            } else if (a == 'A') {
                start = {i, j};
                sol[i][j] = 0;
            } else if (a == '#') {
                blocked[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = cur.first + dx[i], y = cur.second + dy[i];
            if (valid(x, y) && !blocked[x][y] && monster_dist[x][y] == inf) {
                q.push({x, y});
                monster_dist[x][y] = monster_dist[cur.first][cur.second] + 1;
            }
        }
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << (monster_dist[i][j] == inf ? 9 : monster_dist[i][j]) << "\t";
//        }
//        cout << "\n";
//    }
    assert(q.empty());
    q.push(start);
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        int dist = sol[cur.first][cur.second];
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = cur.first + dx[i], y = cur.second + dy[i];
            if (valid(x, y) && !blocked[x][y] && monster_dist[x][y] > dist + 1 && sol[x][y] == inf) {
                q.push({x, y});
                sol[x][y] = dist + 1;
                parent[x][y] = {cur, dir[i]};
            }
        }
    }
//    cout << "\n";
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << (sol[i][j] == inf ? -1 : sol[i][j]) << "\t";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (edge(i, j) && sol[i][j] != inf) {
                cout << "YES"
                     << "\n";
                cout << sol[i][j] << "\n";
                pair<int, int> loc{i, j};
                vector<char> d;
                while (loc != start) {
                    d.push_back(parent[loc.first][loc.second].second);
                    loc = parent[loc.first][loc.second].first;
                }
                reverse(d.begin(), d.end());
                print(d);
                return 0;
            }
        }
    }
    cout << "NO"
         << "\n";
    return 0;
}
