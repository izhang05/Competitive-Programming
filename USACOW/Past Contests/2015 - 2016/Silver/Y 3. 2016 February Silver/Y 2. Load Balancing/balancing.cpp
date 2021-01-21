/*
ID: izhang01
TASK: balancing
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    set<int> x, y;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
        x.insert(points[i].first);
        y.insert(points[i].second);
    }
    sort(points.begin(), points.end());
    map<int, int> xc, yc;
    map<int, vector<int>> row_p, col_p;
    int ind = 0;

    for (int i : x) {
        col_p[ind] = {};
        xc[i] = ind++;
    }

    ind = 0;
    for (int i: y) {
        row_p[ind] = {};
        yc[i] = ind++;
    }
    for (int i = 0; i < n; ++i) {
        col_p[xc[points[i].first]].push_back(yc[points[i].second]);
        row_p[yc[points[i].second]].push_back(xc[points[i].first]);
    }
    int sol = 1e9, bot_lef, bot_rig, top_lef, top_rig;
    for (auto i : xc) {
        bot_lef = bot_rig = top_lef = top_rig = 0;
        for (auto j : yc) {
            for (int k : row_p[j.second]) {
                if (k <= i.second) {
                    ++top_lef;
                } else {
                    ++top_rig;
                }
            }
        }
        for (auto j : yc) {
            for (int k : row_p[j.second]) {
                if (k <= i.second) {
                    ++bot_lef;
                    --top_lef;
                } else {
                    ++bot_rig;
                    --top_rig;
                }
            }
            sol = min(sol, max({bot_lef, bot_rig, top_lef, top_rig}));
        }
    }
    cout << sol << "\n";
    return 0;
}
