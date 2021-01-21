/*
ID: izhang01
TASK: moocast
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
}

const int maxn = 200;
int num_visited;
bool visited[maxn];
vector<vector<int> > adj(maxn);

double dist(int x1, int y1, int x2, int y2) {
    return pow((abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2)), 0.5);
}

void dfs(int n) {
    visited[n] = true;
    ++num_visited;
    for (int j : adj[n]) {
        if (!visited[j]) {
            dfs(j);
        }
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    int x, y, p;
    vector<vector<int> > cows(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> p;
        cows[i][0] = x, cows[i][1] = y, cows[i][2] = p;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist(cows[i][0], cows[i][1], cows[j][0], cows[j][1]) <= cows[i][2]) {
                adj[i].push_back(j);
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        num_visited = 0;
        for (int j = 0; j < n; ++j) {
            visited[j] = false;
        }
        dfs(i);
        sol = max(sol, num_visited);
    }
    cout << sol << "\n";
    return 0;
}
