/* Author: izhang05
 * Time: 08-11-2021 01:24:41
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxs = 24;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int dp[1 << maxs];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        set<int> l;
        for (int j = 0; j < 3; ++j) {
            l.insert(s[j] - 'a');
        }
        for (auto &j : l) {
            ++dp[1 << j];
        }
        vector<int> letters(l.begin(), l.end());
        if (letters.size() >= 2) {
            if (letters.size() == 2) {
                int cur = (1 << letters[0]) + (1 << letters[1]);
                --dp[cur];
            } else {
                for (int j = 0; j < 3; ++j) {
                    int cur = (1 << letters[j]) + (1 << letters[(j + 1) % 3]);
                    --dp[cur];
                }
                int cur = (1 << letters[0]) + (1 << letters[1]) + (1 << letters[2]);
                ++dp[cur];
            }
        }
    }
    for (int i = 0; i < maxs; ++i) {
        for (int mask = 0; mask < (1 << maxs); ++mask) {
            if (mask & (1 << i)) {
                dp[mask] += dp[mask ^ (1 << i)];
            }
        }
    }
    long long sol = 0;
    for (int i : dp) {
        sol ^= i * i;
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
