#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("1.in", "r", stdin);
}
const int maxn = 1e5 + 1;
vector<int> adj[maxn];
double prob[maxn];
int dist[maxn];
double sol = 0;

void dfs(int n, int d, double p) {
    dist[n] = d;
    prob[n] = p;
    int num_adj = adj[n].size();
    if (n != 0) {
        --num_adj;
    }
    if (adj[n].size() == 1 && n != 0) {
        sol += p * d;
    }
    for (int i : adj[n]) {
        if (dist[i] == -1) {
            dfs(i, d + 1, p / num_adj);
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
        dist[i] = -1;
    }
    dist[n - 1] = -1;
    dfs(0, 0, 1);
    cout << setprecision(18) << sol << "\n";
    return 0;
}