#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("curution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1e5;
bool visited[maxn];
vector<int> adj[maxn], cur, sol;
int n;

void dfs(int node) {
    if (cur.size() == n) {
        sol = cur;
        return;
    }
    for (int i : adj[node]) {
        if (!visited[i]) {
            visited[i] = true;
            cur.push_back(i);
            dfs(i);
            if (!sol.empty()) {
                return;
            }
            cur.erase(--cur.end());
            visited[i] = false;
        }
    }
}

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        sol.clear();
        for (unsigned int i = 0; i < n; ++i) {
            for (unsigned int j = i + 1; j < n; ++j) {
                if ((i + 1) & (j + 1)) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cur.clear();
            memset(visited, false, sizeof(visited));
            if (!sol.empty()) {
                break;
            }
            visited[i] = true;
            cur.push_back(i);
            dfs(i);
        }
        if (!sol.empty()) {
            for (int i : sol) {
                cout << i + 1 << " ";
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }

    }
    return 0;
}
