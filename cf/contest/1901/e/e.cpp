/* Author: izhang
 * Time: 02-04-2024 20:03:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 5e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[mxn];
int deg[mxn], root;
long long a[mxn], dp[mxn][3];
// dp[v][1] = best for subtree v if v has exactly 1 child, dp[v][2] = exactly 2 children, dp[v][0] = otherwise

void dfs(int c, int p) {
    dp[c][0] = a[c];
    long long best = -INFL;
    vector<long long> cur;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            cur.push_back(max({dp[i][1] - a[i], dp[i][2], dp[i][0]}));
            best = max(best, cur.back());
        }
    }
    dp[c][1] = best + a[c];
    if (cur.size() > 1) {
        sort(cur.begin(), cur.end());
        reverse(cur.begin(), cur.end());
        long long cur_val_2 = cur[0] + cur[1], cur_val_0 = 0;
        for (int i = 0; i < int(cur.size()); ++i) {
            if (i >= 3 && cur[i] < 0) {
                break;
            }
            cur_val_0 += cur[i];
        }
        dp[c][2] = a[c] + cur_val_2;
        if (int(cur.size()) >= 3) {
            dp[c][0] = max({a[c], a[c] + cur_val_0});
        }
    }
}

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        dp[i][0] = dp[i][1] = dp[i][2] = -INFL;
        cin >> a[i];
        deg[i] = 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
        ++deg[node1], ++deg[node2];
    }
    if (n == 2) {
        cout << max({0ll, max(a[0], a[1]), a[0] + a[1]}) << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (deg[i] != 1) {
            root = i;
        }
    }
    dfs(root, -1);
    long long sol = 0;
    dbg() << root;
    for (int i = 0; i < n; ++i) {
        dbg() << dp[i][0] << " " << dp[i][1] << " " << dp[i][2];
        sol = max(sol, dp[i][1]);
        sol = max(sol, dp[i][2] - a[i]);
        sol = max(sol, dp[i][0]);
    }
    cout << sol << "\n";
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
