#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int maxn = 2e5 + 1;
vector<int> adj[maxn];
long long dist[maxn], n, sub_size[maxn], sol[maxn], visited[maxn];

void bfs(int node) {
    for (int i = 0; i < n; ++i) {
        dist[i] = -1;
    }
    queue<pair<int, int> > q;
    q.push(make_pair(node, 0));
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        dist[cur.first] = cur.second;
        for (int i : adj[cur.first]) {
            if (dist[i] == -1) {
                q.push(make_pair(i, cur.second + 1));
            }
        }
    }
}

int farthest() {
    pair<int, int> res;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > res.first) {
            res.first = dist[i];
            res.second = i;
        }
    }
    return res.second;
}

void solve(int node) {
    for (int i : adj[node]) {
        if (sol[i] == 0) {
            sol[i] = sol[node] - sub_size[i] + (n - sub_size[i]);
            solve(i);
        }
    }
}

long long find_sub_size(int node, bool first) {
    if (adj[node].size() == 1 && !first) {
        sub_size[node] = 1;
        return 1;
    }
    long long &cur = sub_size[node];
    ++cur;
    for (int i : adj[node]) {
        if (sub_size[i] == 0) {
            cur += find_sub_size(i, false);
        }
    }
    return cur;
}


int main() {
    setIO();
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(0);
    int cur = farthest();
    find_sub_size(cur, true);
    long long f = 0;
    for (int i = 0; i < n; ++i) {
        f += sub_size[i] - 1;
    }
    sol[cur] = f;
    solve(cur);
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " ";
    }
    cout << "\n";
    return 0;
}
