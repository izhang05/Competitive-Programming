/*
ID: izhang01
TASK: painting
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("painting.in", "r", stdin);
    freopen("painting.out", "w", stdout);
}

struct point {
    int x, y;
    bool operator<(const point &rhs) const {
        return this->x < rhs.x;
    }
    bool operator<=(const point &rhs) const {
        return this->x <= rhs.x;
    }
};


int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<point, point>> points(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> points[2 * i].first.x >> points[2 * i].first.y >> points[2 * i].second.x >> points[2 * i].second.y;
        points[2 * i + 1] = make_pair(points[2 * i].second, points[2 * i].first);
    }
    sort(points.begin(), points.end());
    set<pair<int, int>> cur;
    int sol = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (points[i].first <= points[i].second) {
            bool outside = false;
            auto it = cur.lower_bound(make_pair(points[i].first.y, 0));
            if (it != cur.end()) {
                if (it->second == 0) {
                    outside = true;
                }
            } else {
                outside = true;
            }
            if (outside) {
                ++sol;
                cur.insert(make_pair(points[i].first.y, 0));
                cur.insert(make_pair(points[i].second.y, 1));
            }
        } else {
            try {
                cur.erase({points[i].second.y, 0});
                cur.erase({points[i].first.y, 1});
            } catch (...) {}
        }
    }
    assert(cur.empty());
    cout << sol << "\n";
    return 0;
}
