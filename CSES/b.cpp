#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    freopen("b.out", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;

int sub[maxn], depth[maxn];
vector<int> adj[maxn];

void dfs(int c, int p, int d) {
    sub[c] = 1;
    depth[c] = d;
    for (auto i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
            sub[c] += sub[i];
        }
    }
}

int main() {
    setIO();

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, 1);
    vector<int> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = sub[i] - depth[i];
#ifdef DEBUG
        cout << nodes[i] << "\n";
#endif
    }
    sort(nodes.begin(), nodes.end());
    reverse(nodes.begin(), nodes.end());
    long long sol = 0;
    for (int i = 0; i < n - k; ++i) {
        sol += nodes[i];
    }
    cout << sol << "\n";
    return 0;
}
