///*
//ID: izhang01
//TASK: lazy
//LANG: C++11
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("lazy.in", "r", stdin);
//    freopen("lazy.out", "w", stdout);
//}
//const int maxn = 4e2 + 5;
//int grid[maxn][maxn], n, k;
//bool visited[maxn][maxn];
//const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//
//bool valid(pair<int, int> x) {
//    return x.first >= 0 && x.first < n && x.second >= 0 && x.second < n;
//}
//
//int dist(pair<int, int> x, pair<int, int> y) {
//    return abs(x.first - y.first) + abs(x.second - y.second);
//}
//
//int main() {
//    setIO();
//    cin >> n >> k;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cin >> grid[i][j];
//        }
//    }
//    queue<pair<int, pair<int, int>>> q;
//    int sol = 0;
//    for (int col = 0; col < n; ++col) {
//        int cur_sol = grid[col][0];
//        memset(visited, false, sizeof(visited));
//        q.push({k, {col, 0}});
//        visited[col][0] = true;
//        vector<pair<int, int>> left, right;
//        while (!q.empty()) {
//            pair<int, pair<int, int>> cur = q.front();
//            q.pop();
//            if (cur.second.second == 0) {
//                right.push_back(cur.second);
//            }
//            if (!cur.first) {
//                left.push_back(cur.second);
//                continue;
//            }
//            for (int i = 0; i < 4; ++i) {
//                pair<int, int> next = {cur.second.first + dx[i], cur.second.second + dy[i]};
//                if (valid(next) && !visited[next.first][next.second]) {
//                    visited[next.first][next.second] = true;
//                    cur_sol += grid[next.first][next.second];
//                    q.push({cur.first - 1, next});
//                }
//            }
//        }
//        sol = max(sol, cur_sol);
//        for (int row = 0; row < n - 1; ++row) {
//            vector<pair<int, int>> next_left, next_right;
//            for (pair<int, int> i : left) {
//                pair<int, int> next = {i.first, i.second + 1};
//                if (valid(next)) {
//                    cur_sol += grid[next.first][next.second];
//                    next_left.push_back(next);
//                }
//            }
//            for (pair<int, int> i : right) {
//                if (dist(i, {col, row}) == k) {
//                    next_right.emplace_back(i.first, i.second + 1);
//                    cur_sol -= grid[i.first][i.second];
//                } else {
//                    next_right.emplace_back(i.first, i.second);
//                }
//            }
//            swap(left, next_left);
//            swap(right, next_right);
//            sol = max(sol, cur_sol);
//        }
//    }
//    cout << sol << "\n";
//    return 0;
//}

/*
ID: izhang01
TASK: lazy
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
}
const int maxn = 4e2 + 5;
int grid[maxn][maxn], n, k;
bool visited[maxn][maxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(pair<int, int> x) {
    return x.first >= 0 && x.first < n && x.second >= 0 && x.second < n;
}

int dist(pair<int, int> x, pair<int, int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int main() {
    setIO();
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    queue<pair<int, pair<int, int>>> q;
    int sol = 0;
    vector<pair<int, int>> up, down;

    q.push({k, {0, 0}});
    visited[0][0] = true;
    int col_sol = 0;
    while (!q.empty()) {
        pair<int, pair<int, int>> cur = q.front();
        q.pop();
        if (cur.second.first == 0) {
            down.push_back(cur.second);
        }
        if (!cur.first) {
            up.push_back(cur.second);
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            pair<int, int> next = {cur.second.first + dx[i], cur.second.second + dy[i]};
            if (valid(next) && !visited[next.first][next.second]) {
                visited[next.first][next.second] = true;
                col_sol += grid[next.first][next.second];
                q.push({cur.first - 1, next});
            }
        }
    }
    for (int col = 0; col < n; ++col) {
        int cur_sol = col_sol;
        vector<pair<int, int>> left, right;
        for (pair<int, int> i : down) {

        }
        sol = max(sol, cur_sol);
        for (int row = 0; row < n - 1; ++row) {
            vector<pair<int, int>> next_left, next_right;
            for (pair<int, int> i : left) {
                pair<int, int> next = {i.first, i.second + 1};
                if (valid(next)) {
                    cur_sol += grid[next.first][next.second];
                    next_left.push_back(next);
                }
            }
            for (pair<int, int> i : right) {
                if (dist(i, {col, row}) == k) {
                    next_right.emplace_back(i.first, i.second + 1);
                    cur_sol -= grid[i.first][i.second];
                } else {
                    next_right.emplace_back(i.first, i.second);
                }
            }
            swap(left, next_left);
            swap(right, next_right);
            sol = max(sol, cur_sol);
        }
    }
    cout << sol << "\n";
    return 0;
}