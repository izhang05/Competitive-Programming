/* Author: izhang
 * Time: 08-27-2023 01:35:11
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
vector<int> adj[mxn];
int sz[mxn];
long long sol = 0;

int dfs1(int c, int p) {
    sz[c] = 1;
    for (auto &i : adj[c]) {
        if (i != p) {
            sz[c] += dfs1(i, c);
        }
    }
    return sz[c];
}

void dfs2(int c, int p) {
    vector<int> cur;
    int sum = 0;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
            cur.push_back(sz[i]);
            sum += sz[i];
        }
    }
    int n = int(cur.size());
    dbg() << "cur: " << cur;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, false)); // bool dp[i][j] = pos to form subset of sum j with first i elements
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            dp[i][j] |= dp[i - 1][j];
            if (dp[i - 1][j] && j + cur[i - 1] <= sum) {
                dp[i][j + cur[i - 1]] = true;
            }
        }
    }
    dbg() << dp;
    int cur_mx = 0;
    for (int i = 0; i <= sum; ++i) {
        if (dp[n][i]) {
            cur_mx = max(cur_mx, i * (sum - i));
        }
    }
    sol += cur_mx;
}

void test_case() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs1(0, -1);
    dfs2(0, -1);
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
