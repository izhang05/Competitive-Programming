#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mxn = 1e5 + 5;
vector<int> adj[mxn];
long long dp[mxn][2];
long long a[mxn], t[mxn];

void dfs(int u, int p) {
    // v = 0 = haven't scared anybody, 1 = scared off children
    for (auto &i: adj[u]) {
        if (i != p) {
            dfs(i, u);
        }
    }
    dp[u][0] = dp[u][1] = a[u];
    long long mx = 0;
    pair<long long, long long> mx21 = {-1e18, -1e18}, mx22 = mx21,
            mx31 = {-1e18, -1e18}, mx32 = mx31;

    for (auto &i: adj[u]) {
        if (i != p) {
            dp[u][1] += dp[i][0] - a[i];
            mx = max(mx, a[i]);
            pair<long long, long long> cur{dp[i][1] - (dp[i][0] - a[i]), i};
            if (cur > mx21) {
                mx21 = cur;
                if (mx21 > mx22) {
                    swap(mx21, mx22);
                }
            }
            if (t[i] == 3) {
                cur = {dp[i][0] - (dp[i][0] - a[i]), i};
                if (cur > mx31) {
                    mx31 = cur;
                    if (mx31 > mx32) {
                        swap(mx31, mx32);
                    }
                }
//                mx3 = max(mx3, {dp[i][0] - (dp[i][0] - a[i]), i});
            }
        }
    }
    dp[u][0] = dp[u][1] + mx;
    long long add = 0;
    if (mx32.second != mx22.second) {
        add = mx32.first + mx22.first;
    }
    add = max(add, mx31.first + mx22.first);
    add = max(add, mx32.first + mx21.first);
//            = mx3.first;
//    if (mx22.second == mx3.second) {
//        add += mx21.first;
//    } else {
//        add += mx22.first;
//    }
    dp[u][0] = max(dp[u][0], dp[u][1] + add);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        cin >> a[i];
        dp[i][0] = dp[i][1] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    cout << dp[0][0] << "\n";
//    for (int i = 0; i < n; ++i) {
//        cout << dp[i][0] << " " << dp[i][1] << "\n";
//    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        solve();
//        cout << "\n";
    }
}