//#include <bits/stdc++.h>
//
//using namespace std;
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//}
//const int maxn = 2e5;
//int dp[maxn][2];
//vector<int> adj[maxn];
//
//void sol(int n, int p) {
//    for (int i : adj[n]) {
//        if (i != p) {
//            sol(i, n);
//            dp[n][0] += max(dp[i][0], dp[i][1]);
//        }
//    }
//    for (int i : adj[n]) {
//        if (i != p) {
//            dp[n][1] = max(dp[n][1], dp[i][0] + 1 + dp[n][0] - max(dp[i][0], dp[i][1]));
//        }
//    }
//}
//
//int main() {
//    setIO();
//    int n;
//    cin >> n;
//    int a, b;
//    for (int i = 0; i < n - 1; ++i) {
//        cin >> a >> b;
//        --a, --b;
//        adj[a].push_back(b);
//        adj[b].push_back(a);
//    }
//    sol(0, -1);
//    cout << max(dp[0][0], dp[0][1]) << "\n";
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(cin.failbit);
#ifdef LOCAL
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
#endif
}
//#define DEBUG
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int parent[maxn], deg[maxn];
bool used[maxn];

void dfs(int c, int p) {
    deg[c] = adj[c].size();
    for (int i : adj[c]) {
        if (i != p) {
            parent[i] = c;
            dfs(i, c);
        }
    }
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
    queue<int> nodes;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            nodes.push(i);
        }
    }
    int sol = 0;
    while (!nodes.empty()) {
        int cur = nodes.front();
        nodes.pop();
        if (cur != 0 && !used[cur] && !used[parent[cur]]) {
            ++sol;
            used[parent[cur]] = used[cur] = true;
#ifdef DEBUG
            cout << cur + 1 << " " << parent[cur] + 1 << "\n";
#endif
        }
        if (--deg[parent[cur]] == 1) {
            nodes.push(parent[cur]);
        }
    }
    cout << sol << "\n";
    return 0;
}
