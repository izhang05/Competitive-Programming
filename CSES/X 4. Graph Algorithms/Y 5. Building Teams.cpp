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
int state[maxn];
bool pos = true;

void dfs(int n, int color) {
    state[n] = color;
    for (int i : adj[n]) {
        if (state[i] == 0) {
            dfs(i, 3 - color);
            if (!pos) {
                return;
            }
        } else if (state[i] != 3 - color) {
            pos = false;
            return;
        }
    }
}


int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        if (state[i] == 0) {
            dfs(i, 1);
            if (!pos) {
                break;
            }
        }
    }
    if (!pos) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        for (int i = 0; i < n; ++i) {
            cout << state[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
