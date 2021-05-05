/*
ID: izhang01
TASK: movie
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);
    freopen("movie.out", "w", stderr);
}
//#define DEBUG

struct movie {
    int d, n;
    vector<int> a;
};

const int maxn = 20, inf = 1e9;
pair<int, int> dp[1 << maxn];

int main() {
    setIO();
    int n, l;
    cin >> n >> l;
    vector<movie> m(n);
    for (int i = 0; i < (1 << n); ++i) {
        dp[i] = {inf, 0};
    }
    for (int i = 0; i < n; ++i) {
        cin >> m[i].d >> m[i].n;
        m[i].a.resize(m[i].n);
        for (int j = 0; j < m[i].n; ++j) {
            cin >> m[i].a[j];
        }
        if (m[i].a[0] == 0) {
            dp[1 << i] = {1, -m[i].d};
        }
    }
    for (int mask = 1; mask < (1 << n); ++mask) {
        if (dp[mask].first == inf) {
            continue;
        }
#ifdef DEBUG
        cout << mask << " " << dp[mask].first << " " << -dp[mask].second << "\n";
#endif
        for (int j = 0; j < n; ++j) {
            if (!(mask & (1 << j))) {
                auto it = upper_bound(m[j].a.begin(), m[j].a.end(), -dp[mask].second);
                if (it != m[j].a.begin()) {
                    --it;
#ifdef DEBUG
                    cout << j << " " << *it << " " << -dp[mask].second << "\n";
#endif
                    if (*it <= -dp[mask].second) {
                        dp[mask | (1 << j)] = min(dp[mask | (1 << j)], {dp[mask].first + 1, -*it - m[j].d});
                    }
                }
            }
        }
    }
    int sol = inf;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (-dp[mask].second >= l) {
            sol = min(sol, dp[mask].first);
        }
    }
    cout << (sol == inf ? -1 : sol) << "\n";
    return 0;
}
