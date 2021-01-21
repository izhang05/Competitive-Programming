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
bool found = false;
vector<int> sol;

void dfs(int n) {
    sol.push_back(n);
    state[n] = 1;
    for (int i : adj[n]) {
        if (state[i] == 2) {
            dfs(i);
            if (found) {
                return;
            }
        } else if (state[i] == 1) {
            found = true;
            sol.push_back(i);
            return;
        }
    }
    state[n] = 2;
    sol.erase(find(sol.begin(), sol.end(), n));
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
    }
    for (int i = 0; i < n; ++i) {
        if (!state[i]) {
            sol.clear();
            dfs(i);
            if (found) {
                break;
            }
        }
    }
    if (found) {
        cout << sol.size() << "\n";
        for (int i : sol) {
            cout << i + 1 << " ";
        }
    } else {
        cout << "IMPOSSIBLE" << "\n";
    }
    return 0;
}
