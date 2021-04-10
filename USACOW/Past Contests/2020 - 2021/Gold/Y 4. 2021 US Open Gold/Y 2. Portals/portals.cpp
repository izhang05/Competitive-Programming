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
//#define DEBUG

const int maxn = 1e5;
vector<int> adj[4 * maxn];
bool visited[4 * maxn];
int cost[maxn];
bool used[maxn][4][4];

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;

int parent[4 * maxn];

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot != yroot) {
        parent[xroot] = yroot;
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

void dfs(int c) {
    visited[c] = true;
    for (auto i : adj[c]) {
        if (!visited[i]) {
            if (i % 4 == 0 || i % 4 == 1) {
                if (!same(i, i / 4 + 2) && !used[i / 4][i % 4][2]) {
                    q.push({cost[i / 4], {i, (i / 4) * 4 + 2}});
                    used[i / 4][i % 4][2] = true;
                }
                if (!same(i, i / 4 + 3) && !used[i / 4][i % 4][3]) {
                    q.push({cost[i / 4], {i, (i / 4) * 4 + 3}});
                    used[i / 4][i % 4][3] = true;
                }
            } else {
                if (!same(i, i / 4) && !used[i / 4][0][i % 4]) {
                    q.push({cost[i / 4], {i, (i / 4) * 4}});
                    used[i / 4][0][i % 4] = true;
                }
                if (!same(i, i / 4 + 1) && !used[i / 4][1][i % 4]) {
                    q.push({cost[i / 4], {i, (i / 4) * 4 + 1}});
                    used[i / 4][1][i % 4] = true;
                }
            }
            merge(i, c);
            dfs(i);
        }
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    map<int, vector<int>> con;
    for (int i = 0; i < 4 * n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
#ifdef DEBUG
        cout << i << " " << cost[i] << "\n";
#endif
        for (int j = 0; j < 4; ++j) {
            int a;
            cin >> a;
            con[a].push_back(4 * i + j);
        }
    }
    for (int i = 0; i < 4 * n; i += 2) {
        adj[i].push_back(i + 1);
        adj[i + 1].push_back(i);
    }
    for (auto i : con) {
        adj[i.second[0]].push_back(i.second[1]);
        adj[i.second[1]].push_back(i.second[0]);
    }
#ifdef DEBUG
    for (int i = 0; i < 4 * n; ++i) {
        for (auto j : adj[i]) {
            cout << i << " " << j << "\n";
        }
    }
    cout << "\n";
#endif
    int sol = 0, comps = 0;
    for (int i = 0; i < 4 * n; ++i) {
        if (!visited[i]) {
            dfs(i);
            ++comps;
        }
    }
#ifdef DEBUG
    cout << q.size() << "\n";
#endif
    while (comps > 1 && !q.empty()) {
        pair<int, pair<int, int>> cur = q.top();
        q.pop();
#ifdef DEBUG
        cout << cur.first << " " << cur.second.first << " " << cur.second.second << " " << sol << " " << comps << "\n";
#endif
        if (get(cur.second.first) == get(cur.second.second)) {
            continue;
        }
        merge(cur.second.first, cur.second.second);
        sol += cur.first;
        --comps;
    }
    //    int sol = -1;
    //    for (int i = 0; i < 4 * n; ++i) {
    //        if (!visited[i]) {
    //            dfs(i);
    //            ++sol;
    //        }
    //    }
    cout << sol << "\n";
    return 0;
}
