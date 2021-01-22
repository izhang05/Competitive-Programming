/*
ID: izhang01
TASK: cowjump
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowjump.in", "r", stdin);
    freopen("cowjump.out", "w", stdout);
}

struct point {
    long long x, y;
    void operator-=(const point &rhs) {
        x -= rhs.x;
        y -= rhs.y;
    }
    point operator-(const point &rhs) const {
        return point{x - rhs.x, y - rhs.y};
    }
    bool operator<(const point &rhs) const {
        if (x == rhs.x) {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
    long long operator*(const point &rhs) const {
        return (long long) x * rhs.y - (long long) y * rhs.x;
    }
    long long triangle(const point &b, const point &c) const {
        return (b - *this) * (c - *this);
    }
};


bool intersect(pair<point, point> a, pair<point, point> b) {
    point p1 = a.first, p2 = a.second, p3 = b.first, p4 = b.second;
    for (int rep = 0; rep < 2; ++rep) {
        if ((p2 - p1) * (p4 - p3) == 0) {
            // collinear or parallel
            if (p1.triangle(p2, p3) != 0) {
                // parallel
                return false;
            } else {
                // collinear
                for (int rep1 = 0; rep1 < 2; ++rep1) {
                    if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
                        return false;
                    }
                    swap(p1, p3);
                    swap(p2, p4);
                }
            }
            return true;
        }
        long long sign1 = (p2 - p1) * (p3 - p1), sign2 = (p2 - p1) * (p4 - p1);
        if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
            return false;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    return true;
}

int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<point, point>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.x >> a[i].first.y >> a[i].second.x >> a[i].second.y;
        if (a[i].second < a[i].first) {
            swap(a[i].first, a[i].second);
        }
    }
    sort(a.begin(), a.end());
    auto cmp = [](pair<point, point> a, pair<point, point> b) {
        return a.first * b.first <= 0;
    };
    set<pair<point, point>, decltype(cmp)> cur(cmp); // none of the segments in cur intersect
    for (int i = 0; i < n; ++i) {
        auto it = cur.lower_bound(a[i]);
        if (it != cur.end()) {
            if (intersect(a[i], *it)) {

            }
        }
    }
    return 0;
}
