/* Author: izhang
 * Time: 05-17-2025 21:52:35
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[mxn];
long long dist[mxn][2];

void test_case() {
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        dist[i][0] = dist[i][1] = INFL;
    }
    vector<long long> a(l);
    long long sum = 0, mn_odd = INFL;
    for (int i = 0; i < l; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] % 2 == 1) {
            mn_odd = min(mn_odd, a[i]);
        }
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (auto &i: adj[cur.first]) {
            if (dist[i][cur.second ^ 1] > dist[cur.first][cur.second] + 1) {
                dist[i][cur.second ^ 1] = dist[cur.first][cur.second] + 1;
                q.push({i, cur.second ^ 1});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cout << 1;
            continue;
        }
        if (sum % 2 == 0) {
            if (sum >= dist[i][0] || sum - mn_odd >= dist[i][1]) {
                cout << 1;
                continue;
            }
        } else {
            if (sum >= dist[i][1] || sum - mn_odd >= dist[i][0]) {
                cout << 1;
                continue;
            }
        }
        cout << 0;
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
