/*
ID: izhang01
TASK: planting
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
}

struct point {
    long long x, y;

    bool operator<(point const &rhs) {
        return this->x < rhs.x;
    }
};

int main() {
    setIO();
    long long sol = 0;
    int n;
    cin >> n;
    vector<pair<point, point>> p(n);
    set<point> start, end;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first.x >> p[i].first.y >> p[i].second.x >> p[i].second.y;
        p[i].first.x += 1e8, p[i].first.y += 1e8, p[i].second.x += 1e8, p[i].second.y += 1e8;
        p[i].second.x *= -1;
        p[i].second.y *= -1;
        start.insert(p[i].first);
        end.insert(p[i].second);
    }
    
    return 0;
}
