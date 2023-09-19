/* Author: izhang
 * Time: 09-17-2023 15:15:01
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 5e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[mxn], radj[mxn];
long long dist[2][mxn], dp[mxn][mxn];

void test_case() {
    int n, b, s, r;
    cin >> n >> b >> s >> r;
    for (int i = 0; i < r; ++i) {
        int node1, node2, l;
        cin >> node1 >> node2 >> l;
        --node1, --node2;
        adj[node1].emplace_back(node2, l);
        radj[node2].emplace_back(node1, l);
    }
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.emplace(0, b);
    dist[0][b] = 0;
    while (!q.empty()) {
        pair<long long, int> cur = q.top();
        q.pop();
        if (dist[0][cur.second] != cur.first) {
            continue;
        }
        for (auto &j : adj[cur.second]) {
            if (dist[0][j.first] > dist[0][cur.second] + j.second) {
                dist[0][j.first] = dist[0][cur.second] + j.second;
                q.emplace(dist[0][j.first], j.first);
            }
        }
    }
    q.emplace(0, b);
    dist[1][b] = 0;
    while (!q.empty()) {
        pair<long long, int> cur = q.top();
        q.pop();
        if (dist[1][cur.second] != cur.first) {
            continue;
        }
        for (auto &j : radj[cur.second]) {
            if (dist[1][j.first] > dist[1][cur.second] + j.second) {
                dist[1][j.first] = dist[1][cur.second] + j.second;
                q.emplace(dist[1][j.first], j.first);
            }
        }
    }

    vector<long long> val(b);
    for (int i = 0; i < b; ++i) {
        val[i] = dist[0][i] + dist[1][i];
    }
    sort(val.begin(), val.end());
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= b; ++i) {
        for (int j = 1; j <= s; ++j) {
            long long cur = val[i - 1];
            for (int k = 1; k <= i / j && i - k >= 0; ++k) {
                dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + (k - 1) * cur);
                if (i - k - 1 >= 0) {
                    cur += val[i - k - 1];
                }
            }
        }
    }
    cout << dp[b][s] << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
