/* Author: izhang
 * Time: 05-21-2022 14:00:05
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[maxn];
long long dp[maxn][maxn]; // dp[i][j] = min cost to reach node i with d = j
int par[maxn], depth[maxn];

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (depth[xroot] > depth[yroot]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        par[xroot] = yroot;
        depth[yroot] = max(depth[yroot], depth[xroot] + 1);
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

void test_case() {
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }
    --t;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
        merge(a, b);
    }
    if (get(0) != get(t)) {
        cout << -1 << "\n";
        return;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    vector<pair<int, int>> states;
    states.emplace_back(0, 0);
    for (int _ = 0; _ <= n; ++_) {
        vector<pair<int, int>> n_states;
        for (auto &i : states) {
            for (auto &j : adj[i.first]) {
                pair<int, int> nxt = {j.first, i.second};
                if (j.second) {
                    ++nxt.second;
                }
                long long cost = dp[i.first][i.second] + j.second * i.second;
                if (dp[nxt.first][nxt.second] > cost) {
                    dp[nxt.first][nxt.second] = cost;
                    n_states.push_back(nxt);
                }
            }
        }
        swap(n_states, states);
    }
    long long sol = INFL;
    for (int i = 0; i < maxn; ++i) {
        sol = min(sol, dp[t][i]);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
