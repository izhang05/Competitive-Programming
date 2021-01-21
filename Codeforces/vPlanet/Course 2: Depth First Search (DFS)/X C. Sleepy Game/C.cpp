#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1e5;
vector<int> adj[maxn];
bool visited[maxn];
int state = -1; // 0 = lose, 1 = tie, 2 = win
stack<int> path;

void dfs(int n, int count) {
    for (int i : adj[n]) {
        if (state == 2) {
            return;
        }
        if (!visited[i]) {
            visited[i] = true;
            path.push(i);
            dfs(i, count + 1);
            visited[i] = false;
            if (state == 2) {
                return;
            }
            path.pop();
        } else {
            assert(state <= 1);
            state = 1;
        }
    }
    if (adj[n].empty()) {
        if (count % 2 == 1) {
            state = 2;
        } else {
            state = max(state, 0);
        }
    }
}

int main() {
    setIO();
    int n, m, c, a;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        for (int j = 0; j < c; ++j) {
            cin >> a;
            adj[i].push_back(a - 1);
        }
    }
    int s;
    cin >> s;
    --s;
    visited[s] = true;
    path.push(s);
    dfs(s, 0);
    if (state == 0) {
        cout << "Lose" << "\n";
    } else if (state == 1) {
        cout << "Draw" << "\n";
    } else if (state == 2) {
        cout << "Win" << "\n";
        stack<int> sol;
        while (!path.empty()) {
            sol.push(path.top() + 1);
            path.pop();
        }
        cout << sol.top();
        sol.pop();
        while (!sol.empty()) {
            cout << " " << sol.top();
            sol.pop();
        }
        cout << "\n";
    } else {
        assert(false);
    }
    return 0;
}
