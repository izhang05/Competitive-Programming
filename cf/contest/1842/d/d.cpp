/* Author: izhang
 * Time: 08-27-2023 00:56:59
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[mxn];
long long dist[mxn][mxn];

void test_case() {
    int n, m;
    cin >> n >> m;
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
        dist[a][b] = dist[b][a] = w;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    if (dist[0][n - 1] == INFL) {
        cout << "inf"
             << "\n";
        return;
    }
    vector<pair<long long, int>> d(n);
    for (int i = 0; i < n; ++i) {
        d[i] = {dist[0][i], i};
    }
    sort(d.begin(), d.end());
    dbg() << d;
    long long t = 0;
    vector<pair<string, long long>> sol;
    string cur_s(n, '0');
    for (int i = 0; i < n - 1; ++i) {
        cur_s[d[i].second] = '1';
        sol.emplace_back(cur_s, d[i + 1].first - d[i].first);
        if (d[i + 1].second == n - 1) {
            break;
        }
    }
    for (auto &i : sol) {
        t += i.second;
    }
    cout << t << " " << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i.first << " " << i.second << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
