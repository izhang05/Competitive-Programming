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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long d[maxn];
bool vis[maxn];
vector<int> adj[maxn];
vector<long long> dp[maxn][3];

vector<long long> ad(vector<long long> a, vector<long long> b) {
    vector<long long> res(a.size() + b.size() - 1, INFL);
    for (int i = 0; i < (int) a.size(); ++i) {
        for (int j = 0; j < (int) b.size(); ++j) {
            res[i + j] = min(res[i + j], a[i] + b[j]);
        }
    }
    return res;
}

vector<long long> mn(vector<long long> a, vector<long long> b) {
    while (a.size() < b.size()) {
        a.push_back(INFL);
    }
    for (int i = 0; i < b.size(); ++i) {
        a[i] = min(a[i], b[i]);
    }
    return a;
}


void dfs(int c, int p) {
    vis[c] = true;
    dp[c][0] = {0};
    dp[c][1] = {INFL, d[c]};
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            dp[c][0] = ad(dp[c][0], mn(dp[i][0], dp[i][2]));
            dp[c][2] = mn(ad(dp[c][2], mn(mn(dp[i][0], dp[i][1]), dp[i][2])), ad(dp[c][1], mn(dp[i][1], dp[i][2])));
            dp[c][1] = ad(dp[c][1], dp[i][0]);
        }
    }
}


int main() {
    setIO("3");

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<long long> res = {0};
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(0, -1);
            res = ad(res, mn(dp[i][0], dp[i][2]));
        }
    }

    int q;
    cin >> q;
    vector<pair<long long, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first;
        queries[i].second = i;
    }
    sort(queries.begin(), queries.end());
    reverse(queries.begin(), queries.end());
    vector<int> sol(q);
    int j = 0;
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        cout << i << ":\n";
        for (int k = 0; k <(int) dp[i][0].size(); ++k) {
            cout << k << " " << dp[i][0][k] << "\n";
        }
        cout << "\n";
        for (int k = 0; k < (int)dp[i][1].size(); ++k) {
            cout << k << " " << dp[i][1][k] << "\n";
        }
        cout << "\n";
    }
#endif
    for (int i = n - 1; i >= 0; --i) {
#ifdef DEBUG
        cout << i << " " << dp[0][0][i] << "\n";
#endif
        while (j < q && res[i] <= queries[j].first) {
            sol[queries[j].second] = i;
            ++j;
        }
    }
    for (auto &i : sol) {
        cout << i << "\n";
    }
    return 0;
}
