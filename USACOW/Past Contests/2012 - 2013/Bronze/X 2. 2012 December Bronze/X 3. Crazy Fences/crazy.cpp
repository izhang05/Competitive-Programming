/*
ID: izhang01
TASK: crazy
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crazy.in", "r", stdin);
    freopen("crazy.out", "w", stdout);
}

struct point {
    int x, y;
};
struct segment {
    point f, s;
};

bool operator<(point p1, point p2) {
    return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
}

const int maxn = 2000;
vector<segment> fence;
bool is_fence[maxn][maxn];
bool is_cow[maxn][maxn];
vector<pair<int, int> > cows;
bool visited[maxn][maxn];
int max_x, max_y, cur, sol;

void start_dfs(int x, int y) {
    visited[node][dist] = true;
    cur += is_cow[node][dist];
    if (node != 0) {
        if (!visited[node - 1][dist] && !is_fence[node - 1][dist]) {
            start_dfs(node - 1, dist);
        }
    }
    if (dist != 0) {
        if (!visited[node][dist - 1] && !is_fence[node][dist - 1]) {
            start_dfs(node, dist - 1);
        }
    }
    if (node != max_x) {
        if (!visited[node + 1][dist] && !is_fence[node + 1][dist]) {
            start_dfs(node + 1, dist);
        }
    }
    if (dist != max_y) {
        if (!visited[node][dist + 1] && !is_fence[node][dist + 1]) {
            start_dfs(node, dist + 1);
        }
    }
}

int main() {
    setIO();
    int n, c;
    cin >> n >> c;
    fence.resize(n);
    cows.resize(c);
    set<int> x, y;
    for (int i = 0; i < n; ++i) {
        cin >> fence[i].f.x >> fence[i].f.y >> fence[i].s.x >> fence[i].s.y;
        x.insert(fence[i].f.x);
        x.insert(fence[i].s.x);
        y.insert(fence[i].f.y);
        y.insert(fence[i].s.y);
    }
    for (int i = 0; i < c; ++i) {
        cin >> cows[i].first >> cows[i].second;
        x.insert(cows[i].first);
        y.insert(cows[i].second);
    }
    map<int, int> x_ind, y_ind;
    int ind = 0;
    for (int i : x) {
        x_ind[i] = ind;
        ++ind;
    }
    max_x = ind;
    ind = 0;
    for (int i : y) {
        y_ind[i] = ind;
        ++ind;
    }
    max_y = ind;
    for (int i = 0; i < n; ++i) {
        fence[i].f.x = x_ind[fence[i].f.x];
        fence[i].s.x = x_ind[fence[i].s.x];
        fence[i].f.y = y_ind[fence[i].f.y];
        fence[i].s.y = y_ind[fence[i].s.y];
    }
    set<pair<int, int> > end_points;
    for (segment i : fence) {
        if (i.f.x == i.s.x) {
            if (end_points.find(pair<int, int>{i.f.x, min(i.f.y, i.s.y)}) == end_points.end()) {
                end_points.insert(pair<int, int>{i.f.x, min(i.f.y, i.s.y)});
            } else {
                end_points.erase(pair<int, int>{i.f.x, min(i.f.y, i.s.y)});
                is_fence[i.f.x][min(i.f.y, i.s.y)] = true;
            }
            if (end_points.find(pair<int, int>{i.f.x, max(i.f.y, i.s.y)}) == end_points.end()) {
                end_points.insert(pair<int, int>{i.f.x, max(i.f.y, i.s.y)});
            } else {
                end_points.erase(pair<int, int>{i.f.x, max(i.f.y, i.s.y)});
                is_fence[i.f.x][max(i.f.y, i.s.y)] = true;
            }

            for (int j = min(i.f.y, i.s.y) + 1; j < max(i.f.y, i.s.y); ++j) {
                is_fence[i.f.x][j] = true;
            }
        } else {
            if (end_points.find(pair<int, int>{min(i.f.x, i.s.x), i.f.y}) == end_points.end()) {
                end_points.insert(pair<int, int>{min(i.f.x, i.s.x), i.f.y});
            } else {
                end_points.erase(pair<int, int>{min(i.f.x, i.s.x), i.f.y});
                is_fence[min(i.f.x, i.s.x)][i.f.y] = true;
            }
            if (end_points.find(pair<int, int>{max(i.f.x, i.s.x), i.f.y}) == end_points.end()) {
                end_points.insert(pair<int, int>{max(i.f.x, i.s.x), i.f.y});
            } else {
                end_points.erase(pair<int, int>{max(i.f.x, i.s.x), i.f.y});
                is_fence[max(i.f.x, i.s.x)][i.f.y] = true;
            }

            for (int j = min(i.f.x, i.s.x) + 1; j < max(i.f.x, i.s.x); ++j) {
                is_fence[j][i.f.y] = true;
            }
        }
    }

    for (int i = 0; i < c; ++i) {
        cows[i].first = x_ind[cows[i].first];
        cows[i].second = y_ind[cows[i].second];
        is_cow[cows[i].first][cows[i].second] = true;
    }
    for (pair<int, int> i : cows) {
        if (!visited[i.first][i.second]) {
            cur = 0;
            start_dfs(i.first, i.second);
            sol = max(sol, cur);
        }
    }
    cout << sol << "\n";
    return 0;
}
