/* Author: izhang05
 * Time: 08-16-2021 21:30:28
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<int> pi;
string s, t;
int m, nxt[maxn][26];
vector<int> prefix_function(string s) {
    int n = (int) s.length();
    pi.resize(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    for (int i = 0; i < m; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            if (t[i] == c) {
                nxt[i][c - 'a'] = i + 1;
            } else {
                nxt[i][c - 'a'] = nxt[pi[i]][c - 'a'];
            }
        }
    }
}

void solve() {
    cin >> s >> t;
    m = int(t.size());
    if (m > int(s.size())) {
        cout << 0 << "\n";
        return;
    }
    string cur = t + '\1' + s;
    int n = int(cur.size());
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i].resize(m + 1, -1);
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            if (dp[i][j] == -1) {
                continue;
            }
            int pre = j;
            while (j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
        }
    }
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
