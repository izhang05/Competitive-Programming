#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
#define int long long

int dist(int a, int b, int x, int y) {
    return abs(x - a) + abs(y - b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n, m, i, j;
        cin >> n >> m >> i >> j;
        vector<pair<int, int>> corners;
        corners.emplace_back(1, 1);
        corners.emplace_back(n, 1);
        corners.emplace_back(1, m);
        corners.emplace_back(n, m);
        pair<int, pair<pair<int, int>, pair<int, int>>> sol;
        for (int k = 0; k < 4; ++k) {
            for (int l = 0; l < 4; ++l) {
                int cur = dist(i, j, corners[k].first, corners[k].second);
                cur += dist(corners[k].first, corners[k].second, corners[l].first, corners[l].second);
                cur += dist(corners[l].first, corners[l].second, i, j);
                sol = max(sol, {cur, {corners[k], corners[l]}});
            }
        }
        cout << sol.second.first.first << " " << sol.second.first.second << " " << sol.second.second.first << " "
             << sol.second.second.second << "\n";
    }
    return 0;
}
