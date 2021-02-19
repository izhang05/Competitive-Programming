#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

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
        cout << i << " ";
    }
    cout << "\n";
}

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 4001;
int dist[maxn][maxn], n, m;
char grid[maxn][maxn];

bool pos(pair<int, int> x) {
    return x.first >= 0 && x.second >= 0 && x.first < n && x.second < m;
}


int main() {
    setIO();
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            dist[i][j] = 1e9;
        }
    }
    dist[0][0] = 0;
    deque<pair<int, pair<int, int>>> q;
    q.push_front(make_pair(0, make_pair(0, 0)));
    while (!q.empty()) {
        int d = q.front().first;
        pair<int, int> l = q.front().second;
        q.pop_front();
        for (int i = 0; i < 4; ++i) {
            pair<int, int> next = make_pair(l.first + dx[i], +l.second + dy[i]);
            if (pos(next) && grid[next.first][next.second] != '.') {
                if (grid[l.first][l.second] == grid[next.first][next.second] && dist[next.first][next.second] > d) {
                    q.push_front(make_pair(dist[next.first][next.second] = d, next));
                } else {
                    if (dist[next.first][next.second] > d + 1) {
                        q.emplace_back(dist[next.first][next.second] = d + 1, next);
                    }
                }
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dist[i][j] != 1e9) {
                sol = max(sol, dist[i][j]);
            }
        }
    }
    cout << sol + 1 << "\n";
    return 0;
}
