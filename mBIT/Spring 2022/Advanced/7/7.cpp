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
long long dp[maxn][maxn];


void test_case() {
    int n, m;
    cin >> n >> m;
    map<int, vector<pair<int, int>>> ticket;
    for (int i = 0; i < n; ++i) {
        int t, e, c;
        cin >> t >> e >> c;
        ticket[e].emplace_back(t, c);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[m][0] = 0;
    for (int i = m; i >= 1; --i) {
        for (auto &k: ticket[i]) {
            for (int j = m + 1; j >= 0; --j) {
                if (dp[i][j] == INFL) {
                    continue;
                }
                int nxt = j + k.first;
                nxt = min(nxt, m + 1);
                dp[i][nxt] = min(dp[i][nxt], dp[i][j] + k.second);
            }
        }
        for (int j = 1; j <= m + 1; ++j) {
            dbg() << i << " " << j << " " << dp[i][j];
            dp[i - 1][j - 1] = min(dp[i - 1][j - 1], dp[i][j]);
        }
    }
    long long sol = INFL;
    for (int i = 0; i <= m + 1; ++i) {
        sol = min(sol, dp[0][i]);
    }
    cout << (sol == INFL ? -1 : sol) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
