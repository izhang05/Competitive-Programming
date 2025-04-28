#include <bits/stdc++.h>

using namespace std;

const int mxn = 5e3 + 5;
vector<pair<int, long long>> adj[mxn];
long long dist[mxn][mxn], dp[mxn][mxn];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b, s, r;
    cin >> n >> b >> s >> r;
    for (int i = 0; i < r; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        --u, --v;
        adj[u].emplace_back(v, l);
    }
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < n; ++i) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
        q.push({0, i});
        dist[i][i] = 0;
        while (!q.empty()) {
            pair<long long, int> cur = q.top();
            q.pop();
            if (dist[i][cur.second] != cur.first) {
                continue;
            }
            for (auto &j: adj[cur.second]) {
                if (dist[i][j.first] > dist[i][cur.second] + j.second) {
                    dist[i][j.first] = dist[i][cur.second] + j.second;
                    q.push({dist[i][j.first], j.first});
                }
            }
        }
    }
    vector<long long> val(b);
    for (int i = 0; i < b; ++i) {
        val[i] = dist[i][b] + dist[b][i];
    }
    sort(val.begin(), val.end());
    memset(dp, 0x3f, sizeof(dp));
//    for (auto &i: val) {
//        cout << i << " ";
//    }
//    cout << "\n";
    dp[0][0] = 0;
    for (int i = 1; i <= b; ++i) {
        for (int j = 1; j <= s; ++j) {
            long long sum = 0;
            for (int k = 0; k < 5 + i / j ; ++k) {
                int l = i - k;
                if (l <= 0) {
                    continue;
                }
                sum += val[l - 1];
//                cout << i << " " << j << " " << k << " " << sum << " " << dp[l - 1][j - 1] << "\n";
                dp[i][j] = min(dp[i][j], dp[l - 1][j - 1] + (k) * sum);
            }
//            cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }
    cout << dp[b][s] << "\n";
}