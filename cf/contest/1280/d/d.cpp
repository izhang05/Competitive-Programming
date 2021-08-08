/* Author: izhang05
 * Time: 08-08-2021 01:20:51
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int bee[maxn], wasp[maxn], n, m, diff[maxn];
vector<int> adj[maxn];
vector<pair<long long, long long>> dp[maxn];

vector<pair<long long, long long>> merge(vector<pair<long long, long long>> a, vector<pair<long long, long long>> b) {
    vector<pair<long long, long long>> res(a.size() + b.size(), {-INFL, -INFL});
    for (int i = 0; i < (int) a.size(); ++i) {
        for (int j = 0; j < (int) b.size(); ++j) {
            res[i + j] = max(res[i + j], {a[i].first + b[j].first, a[i].second + b[j].second});
            res[i + j + 1] = max(res[i + j + 1], {a[i].first + b[j].first + (b[j].second > 0), a[i].second});
        }
    }
    return res;
}

void dfs(int c, int p) {
    dp[c] = {{0, diff[c]}};
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            dp[c] = merge(dp[c], dp[i]);
        }
    }
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            dp[i].clear();
            cin >> bee[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> wasp[i];
            diff[i] = wasp[i] - bee[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0, -1);
#ifdef DEBUG
        for (int i = 0; i < n; ++i) {
            cout << i << ":\n";
            for (auto &j : dp[i]) {
                cout << j.first << " " << j.second << "\n";
            }
            cout << "\n";
        }
#endif
        long long sol = dp[0][m - 1].first + (dp[0][m - 1].second > 0);
        cout << sol << "\n";
    }
    return 0;
}
