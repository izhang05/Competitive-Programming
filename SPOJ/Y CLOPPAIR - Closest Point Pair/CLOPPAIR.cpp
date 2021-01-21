#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("solution.out", "w", stdout);
    freopen("2.in", "r", stdin);
#endif
}

const double inf = 1e18;


int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first.second >> p[i].first.first; // y value first
        p[i].second = i;
    }
    sort(p.begin(), p.end(), [](pair<pair<int, int>, int> left, pair<pair<int, int>, int> right) {
        return left.first.second == right.first.second ? left.first.first < right.first.first : left.first.second <
                                                                                                right.first.second;
    });
    pair<double, pair<int, int>> sol;
    sol.first = inf;
    set<pair<pair<int, int>, int>> cur;
    cur.insert(p[0]);
    int i = 0;
    for (int j = 1; j < n; ++j) {
        while (i < j && p[j].first.second - p[i].first.second > sol.first) {
            cur.erase(p[i++]);
        }
        for (auto it = cur.lower_bound(make_pair(make_pair(p[j].first.first - sol.first, p[i].first.second - sol.first),
                                                 0)); // every point in cur that is between p[j].first - sol and p[j].first + sol
             it != cur.end() && p[j].first.first + sol.first >= it->first.first; ++it) {
            double cur_sol = sqrt(
                    pow(p[j].first.first - it->first.first, 2) + pow(p[j].first.second - it->first.second, 2));
            if (cur_sol < sol.first) {
                sol.first = cur_sol;
                sol.second = make_pair(min(p[j].second, it->second), max(p[j].second, it->second));
            }
        }
        cur.insert(p[j]);
    }
    cout << fixed << setprecision(6) << sol.second.first << " " << sol.second.second << " " << sol.first << "\n";
    return 0;
}
