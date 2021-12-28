/* Author: izhang05
 * Time: 12-28-2021 15:57:21
**/
#include <bits/stdc++.h>

using namespace std;

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 255;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int dp[maxn][maxn][maxn];

void test_case() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> occ(26), nxt(n + 2, vector<int>(26));
    for (int i = 0; i < n; ++i) {
        occ[s[i] - 'a'].push_back(i + 1);
    }
    for (int i = 0; i < 26; ++i) {
        occ[i].push_back(n + 1);
        int cur = 0;
        for (int j = 0; j < n + 1; ++j) {
            if (occ[i][cur] <= j) {
                ++cur;
            }
            nxt[j][i] = occ[i][cur];
        }
        nxt[n + 1][i] = n + 1;
    }

    vector<string> a(3);
    memset(dp, 0x3f, sizeof(dp));
    for (auto &i : dp) {
        for (auto &j : i) {
            for (auto &k : j) {
                k = n + 1;
            }
        }
    }
    dp[0][0][0] = 0;
    while (q--) {
        char t;
        int ind;
        cin >> t >> ind;
        --ind;
        if (t == '+') {
            char c;
            cin >> c;
            a[ind].push_back(c);
            int mx0 = a[0].size(), mx1 = a[1].size(), mx2 = a[2].size();
            int mn0 = ind == 0 ? mx0 : 0, mn1 = ind == 1 ? mx1 : 0, mn2 = ind == 2 ? mx2 : 0;
            for (int i = mn0; i <= mx0; ++i) {
                for (int j = mn1; j <= mx1; ++j) {
                    for (int k = mn2; k <= mx2; ++k) {
                        int &cur = dp[i][j][k];
                        cur = n + 1;
                        if (i) {
                            cur = min(cur, nxt[dp[i - 1][j][k]][a[0][i - 1] - 'a']);
                        }
                        if (j) {
                            cur = min(cur, nxt[dp[i][j - 1][k]][a[1][j - 1] - 'a']);
                        }
                        if (k) {
                            cur = min(cur, nxt[dp[i][j][k - 1]][a[2][k - 1] - 'a']);
                        }
                    }
                }
            }
        } else {
            a[ind].pop_back();
        }
        cout << (dp[a[0].size()][a[1].size()][a[2].size()] <= n ? "YES" : "NO") << "\n";
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
