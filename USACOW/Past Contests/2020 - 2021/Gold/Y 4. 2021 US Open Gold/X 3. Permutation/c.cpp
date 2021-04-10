#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
#define double long double

//#define DEBUG

struct point {
    long long x, y;
    void operator-=(const point &rhs) {
        x -= rhs.x;
        y -= rhs.y;
    }
    point operator-(const point &rhs) const {
        return point{x - rhs.x, y - rhs.y};
    }
    bool operator==(const point &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    long long operator*(const point &rhs) const {
        return (long long) x * rhs.y - (long long) y * rhs.x;
    }
    long long triangle(const point &b, const point &c) const {
        return (b - *this) * (c - *this);
    }
};

bool intersect(point p1, point p2, point p3, point p4) {
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

const int mod = 1e9 + 7;
//const double eps = 1e-9;
//
//bool eq(double a, double b) {
//    return abs(a - b) <= eps;
//}
//
//bool in(pair<int, int> a, vector<pair<pair<double, double>, pair<pair<int, int>, pair<int, int>>>> b) {
//    int num = 0;
//    for (int i = 0; i < 3; ++i) {
//        if (a.first >= b[i].second.first.first && a.first <= b[i].second.second.first) {
//            pair<double, int> cur = b[i].first;
//            double inter = cur.first * a.first + cur.second;
//            pair<int, int> ys{b[i].second.first.second, b[i].second.second.second};
//            if (eq(inter, ys.first) || eq(inter, ys.second)) {
//                ++num;
//            } else if (inter >= min(ys.first, ys.second) && inter <= max(ys.first, ys.second)) {
//                num += 2;
//            }
//        }
//    }
//#ifdef DEBUG
//    cout << num << "\n";
//#endif
//    return num >= 4;
//}

int main() {
    setIO();
    int n;
    cin >> n;
    vector<point> a(n);
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        order[i] = i;
    }
    long long sol = 0;
    do {
        vector<point> p;
        vector<pair<point, point>> segments;
        for (int i = 0; i < 3; ++i) {
            segments.emplace_back(a[order[i]], a[order[(i + 1) % 3]]);
            p.push_back(a[order[i]]);
        }
        bool pos = true;
        for (int i = 3; i < n; ++i) {
            vector<point> conn;
            for (auto &j : p) {
                bool cur = true;
                for (auto k : segments) {
                    if (k.first == j || k.second == j) {
                        continue;
                    }
                    if (intersect(a[order[i]], j, k.first, k.second)) {
#ifdef DEBUG
                        cout << a[order[i]].x << " " << a[order[i]].y << " " << j.x << " " << j.y << " " << k.first.x << " " << k.first.y << " " << k.second.x << " " << k.second.y << "\n";
#endif
                        cur = false;
                        break;
                    }
                }
                if (cur) {
                    conn.push_back(j);
                    if (conn.size() > 3) {
                        break;
                    }
                }
            }
            if (conn.size() != 3) {
                pos = false;
                break;
            }
            for (auto j : conn) {
                segments.emplace_back(j, a[order[i]]);
            }
            p.push_back(a[order[i]]);
        }
        if (pos) {
#ifdef DEBUG
            for (auto i : order) {
                cout << i << " ";
            }
            cout << "\n";
#endif
            ++sol;
            sol %= mod;
        }
        //        pair<int, int> cur = a[order[i]], nex = a[((order[i]) + 1) % 3];
        //        double slope = (double) (cur.second - nex.second) / (double) (cur.first - nex.first);
        //        double inter = slope * -cur.first + cur.second;
        //        lines[i].first = {slope, inter};
        //        cout << slope << " " << inter << "\n";
        //        lines[i].second = {min(cur, nex), max(cur, nex)};
    } while (next_permutation(order.begin(), order.end()));
    cout << sol << "\n";
    return 0;
}
