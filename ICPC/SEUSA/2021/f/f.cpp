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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 505;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int grid[mxn][mxn];
long long dp[mxn][mxn], mn_r[mxn], mn_c[mxn];

int dist(int x1, int y1, int x2, int y2) {
    return min((x1 - x2) * (x1 - x2), (y1 - y2) * (y1 - y2));
}

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> p(k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            --grid[i][j];
            p[grid[i][j]].emplace_back(i, j);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    memset(mn_r, 0x3f, sizeof(mn_r));
    memset(mn_c, 0x3f, sizeof(mn_c));
    for (auto &i: p[0]) {
        dp[i.first][i.second] = 0;
    }
    for (auto &j: p[0]) {
        mn_r[j.first] = min(mn_r[j.first], dp[j.first][j.second]);
        mn_c[j.second] = min(mn_c[j.second], dp[j.first][j.second]);
    }
    for (int i = 1; i < k; ++i) {
        for (auto &j: p[i]) {
            long long &cur = dp[j.first][j.second];
            if ((int) p[i - 1].size() < n) {
                for (auto &l: p[i - 1]) {
                    cur = min(cur, dp[l.first][l.second] + dist(j.first, j.second, l.first, l.second));
                }
            } else {
                for (int l = 0; l < n; ++l) {
                    cur = min(cur, mn_r[l] + (j.first - l) * (j.first - l));
                    cur = min(cur, mn_c[l] + (j.second - l) * (j.second - l));
                }
            }
        }
        memset(mn_r, 0x3f, sizeof(mn_r));
        memset(mn_c, 0x3f, sizeof(mn_c));
        for (auto &j: p[i]) {
            mn_r[j.first] = min(mn_r[j.first], dp[j.first][j.second]);
            mn_c[j.second] = min(mn_c[j.second], dp[j.first][j.second]);
        }
    }
    long long sol = INFL;
    for (auto &i: p[k - 1]) {
        sol = min(sol, dp[i.first][i.second]);
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
