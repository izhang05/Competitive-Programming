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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2505;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[maxn];
long long dp[maxn], new_dp[maxn];
bool reach[maxn], reach_root[maxn];
vector<int> adj_rev[maxn];

int main() {
    setIO("10");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj_rev[b].push_back(a);
    }
    for (int i = 1; i < n; ++i) {
        dp[i] = new_dp[i] = -INFL;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto &k : adj[j]) {
                new_dp[k.first] = max(new_dp[k.first], dp[j] + k.second);
            }
        }
        copy(begin(new_dp), end(new_dp), begin(dp));
    }
    reach[n - 1] = true;
    queue<int> q;
    q.push(n - 1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i : adj_rev[cur]) {
            if (!reach[i]) {
                q.push(i);
                reach[i] = true;
            }
        }
    }
    reach_root[0] = true;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i : adj[cur]) {
            if (!reach_root[i.first]) {
                q.push(i.first);
                reach_root[i.first] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto &k : adj[j]) {
                if (new_dp[k.first] < dp[j] + k.second) {
                    if (reach[k.first] && reach_root[k.first]) {
                        cout << -1 << "\n";
                        return 0;
                    }
                }
                new_dp[k.first] = max(new_dp[k.first], dp[j] + k.second);
            }
        }
        copy(begin(new_dp), end(new_dp), begin(dp));
    }
    cout << dp[n - 1] << "\n";
    return 0;
}
