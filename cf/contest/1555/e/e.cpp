/* Author: izhang05
 * Time: 07-30-2021 10:35:04
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
set<pair<int, int>> dp[maxn];
vector<pair<int, int>> endp[maxn];

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
        endp[a[i].first.second].emplace_back(a[i].first.first, a[i].second);
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        return left.first.second == right.first.second ? left.first.first < right.first.first : left.first.second < right.first.second;
    });
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        if (a[i].first.first == 1) {
            dp[a[i].first.second].insert({a[i].second, a[i].second});
        }
    }
    for (int i = 1; i < m; ++i) {
        for (auto &j : endp[i]) {
            for (auto &k : dp[j.first]) {
                pair<int, int> cur = k;
                if (j.second > cur.second) {
                    cur.second=cur.second;
                } else if (j.second < cur.first) {
                    cur.first = j.second;
                }
                dp[i].insert(cur);
            }
        }
    }
    int sol = inf;
    for (auto &i : dp[m]) {
        sol = min(sol, i.second - i.first);
    }
    cout << sol << "\n";
    return 0;
}
