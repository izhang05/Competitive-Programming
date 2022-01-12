/* Author: izhang
 * Time: 01-10-2022 10:58:13
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
unordered_map<string, pair<pair<int, int>, int>> occ;
bool dp[maxn];
pair<pair<int, int>, int> take[maxn];

void test_case() {
    occ.clear();
    int n, m;
    cin >> n >> m;
    vector<string> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m - 1; ++j) {
            string cur;
            cur.push_back(a[i][j]);
            cur.push_back(a[i][j + 1]);
            occ[cur] = {{j + 1, j + 2}, i + 1};
            if (j + 2 < m) {
                cur.push_back(a[i][j + 2]);
                occ[cur] = {{j + 1, j + 3}, i + 1};
            }
        }
    }
    string s;
    cin >> s;
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 2; i <= m; ++i) {
        if (dp[i - 2]) {
            string cur;
            cur.push_back(s[i - 2]);
            cur.push_back(s[i - 1]);
            if (occ.find(cur) != occ.end()) {
                take[i] = occ[cur];
                dp[i] = true;
            }
        }
        if (i >= 3 && !dp[i] && dp[i - 3]) {
            string cur;
            cur.push_back(s[i - 3]);
            cur.push_back(s[i - 2]);
            cur.push_back(s[i - 1]);
            if (occ.find(cur) != occ.end()) {
                take[i] = occ[cur];
                dp[i] = true;
            }
        }
    }
    if (dp[m]) {
        vector<pair<pair<int, int>, int>> sol;
        int cur = m;
        while (cur != 0) {
            sol.push_back(take[cur]);
            cur = cur - (take[cur].first.second - take[cur].first.first + 1);
        }
        reverse(sol.begin(), sol.end());
        cout << sol.size() << "\n";
        for (auto &i : sol) {
            cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
        }

    } else {
        cout << -1 << "\n";
    }
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
