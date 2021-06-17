#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
vector<int> adj[maxn];
int in_deg[maxn];
int dp[maxn][26];

int main() {
    setIO("b");

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        ++in_deg[b];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (!in_deg[i]) {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ++dp[cur][s[cur] - 'a'];
        for (auto &i : adj[cur]) {
            if (--in_deg[i] == 0) {
                q.push(i);
            }
            for (int j = 0; j < 26; ++j) {
                dp[i][j] = max(dp[i][j], dp[cur][j]);
            }
        }
        ++cnt;
    }
    if (cnt != n) {
        cout << -1 << "\n";
        return 0;
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            sol = max(sol, dp[i][j]);
        }
    }
    cout << sol << "\n";
    return 0;
}
