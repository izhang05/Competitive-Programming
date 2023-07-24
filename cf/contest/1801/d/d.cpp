/* Author: izhang
 * Time: 06-02-2023 16:00:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f, mxn = 805;
vector<pair<int, int>> adj[mxn];
long long w[mxn];
pair<long long, long long> dist[mxn][mxn]; // dist[cur node][node with max] = <#perf, money>

void test_case() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        cin >> w[i];
        for (int j = 0; j < n; ++j) {
            dist[i][j] = {INFL, INFL};
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b, s;
        cin >> a >> b >> s;
        adj[a - 1].emplace_back(b - 1, s);
    }
    dist[0][0] = {0, -p};
    priority_queue<pair<pair<long long, long long>, pair<int, int>>, vector<pair<pair<long long, long long>, pair<int, int>>>, greater<>> q;
    q.push({{0, -p}, {0, 0}});
    while (!q.empty()) {
        auto [cur_d, node] = q.top();
        q.pop();
        if (dist[node.first][node.second] != cur_d) {
            continue;
        }
        cur_d.second = -cur_d.second;
        for (auto &i : adj[node.first]) {
            pair<long long, long long> nxt_d = cur_d;
            if (i.second > nxt_d.second) {
                long long to_add = (i.second - nxt_d.second + w[node.second] - 1) / w[node.second];
                nxt_d.first += to_add;
                nxt_d.second += to_add * w[node.second];
            }
            nxt_d.second -= i.second;
            assert(nxt_d.second >= 0);
            pair<int, int> nxt_node = {i.first, node.second};
            if (w[i.first] > w[node.second]) {
                nxt_node.second = i.first;
            }
            nxt_d.second = -nxt_d.second;
            if (dist[nxt_node.first][nxt_node.second] > nxt_d) {
                dist[nxt_node.first][nxt_node.second] = nxt_d;
                q.emplace(nxt_d, nxt_node);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dbg() << i << " " << j << " " << dist[i][j];
        }
    }
    long long sol = INFL;
    for (int i = 0; i < n; ++i) {
        sol = min(sol, dist[n - 1][i].first);
    }
    cout << (sol == INFL ? -1 : sol) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
        dbg();
    }
    return 0;
}
