#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("1.in", "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;

int sol = 0;
vector<int> adj[maxn];
int dp[maxn];

void dfs(int node, int p) {
    int child = 0;
    pair<int, int> best;
    for (int i : adj[node]) {
        if (i != p) {
            dfs(i, node);
            ++child;
            if (dp[i] > best.second) {
                best.second = dp[i];
                if (best.second > best.first) {
                    swap(best.second, best.first);
                }
            }
        }
    }
    if (!child) { // leaf node
        dp[node] = 1;
    } else {
        dp[node] = max(adj[node].size(), best.first - 1 + adj[node].size() - 1);
        sol = max(sol, best.first - 1 + (int) adj[node].size() - 1);
    }
    sol = max({sol, best.first - 1 + best.second - 1 + (int) adj[node].size() - 2});
}


int main() {
    setIO();
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << sol << "\n";
    return 0;
}
