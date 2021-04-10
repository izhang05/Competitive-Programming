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
//#define DEBUG
const int maxn = 45, mod = 1e9 + 7;
int dp[maxn][maxn][maxn];

long long fact[maxn];

const double eps = 1e-5;

double triarea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool in(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
    double a = triarea(x1, y1, x2, y2, x3, y3);
    double a1 = triarea(x, y, x2, y2, x3, y3);
    double a2 = triarea(x1, y1, x, y, x3, y3);
    double a3 = triarea(x1, y1, x2, y2, x, y);
    return abs(a - (a1 + a2 + a3)) <= eps;
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
    bool operator==(const point &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    long long operator*(const point &rhs) const {
        return (long long) x * rhs.y - (long long) y * rhs.x;
    }
    long long triangle(const point &b, const point &c) const {
        return (b - *this) * (c - *this);
    }
    long long distsq(const point &rhs) {
        return (x - rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y);
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


int main() {
    setIO();
    fact[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }


    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int cur = 0;
                for (int l = 0; l < n; ++l) {
                    if (l != i && l != j && l != k) {
                        if (in(a[i].first, a[i].second, a[j].first, a[j].second, a[k].first, a[k].second, a[l].first, a[l].second)) {
                            ++cur;
                        }
                    }
                }
                dp[i][j][k] = 6 * fact[cur];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (!dp[i][j][k]) {
                    continue;
                }
                for (int l = 0; l < n; ++l) {
                    if (!in(a[i].first, a[i].second, a[j].first, a[j].second, a[k].first, a[k].second, a[l].first, a[l].second)) {
                        vector<point> p;
                        p.push_back(point{a[i].first, a[i].second});
                        p.push_back(point{a[j].first, a[j].second});
                        p.push_back(point{a[k].first, a[k].second});
                        vector<pair<point, point>> segments;
                        for (int i1 = 0; i1 < 3; ++i1) {
                            segments.emplace_back(p[i1], p[(i1 + 1) % 3]);
                        }
                        int conn = 0;
                        for (auto &j2 : p) {
                            bool cur = true;
                            for (auto k2 : segments) {
                                if (k2.first == j2 || k2.second == j2) {
                                    continue;
                                }
                                if (intersect(point{a[l].first, a[l].second}, j2, k2.first, k2.second)) {
                                    cur = false;
                                    break;
                                }
                            }
                            if (cur) {
                                ++conn;
                            } else {
                                break;
                            }
                        }
                        if (conn == 3) {
                            vector<int> d;
                            for (int i1 = 0; i1 < 3; ++i1) {
                                d.push_back(p[i1].distsq(point{a[l].first, a[l].second}));
                            }
                            vector<int> next{j, k, l};
                            for (int i1 = 0; i1 < 3; ++i1) {
                                if (d[i1] == *min_element(d.begin(), d.end())) {
                                    next.erase(next.begin() + i1);
                                    break;
                                }
                            }
                            next.push_back(l);
                            sort(next.begin(), next.end());
                            int cur = 0;
                            for (int m = 0; m < n; ++m) {
                                if (m != i && m != j && m != k && m != l) {
                                    if (in(a[next[0]].first, a[next[0]].second, a[next[1]].first, a[next[1]].second, a[next[2]].first, a[next[2]].second, a[m].first, a[m].second)) {
                                        if (!in(a[i].first, a[i].second, a[j].first, a[j].second, a[k].first, a[k].second, a[m].first, a[m].second)) {
                                            ++cur;
                                        }
                                    }
                                }
                            }
                            dp[next[0]][next[1]][next[2]] += (dp[i][j][k] * fact[cur]) % mod;
                            dp[next[0]][next[1]][next[2]] %= mod;
                        }
                    }
                }
            }
        }
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                cout << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
            }
        }
    }
#endif
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                bool pos = true;
                for (int l = 0; l < n; ++l) {
                    if (l != i && l != j && l != k) {
                        if (!in(a[i].first, a[i].second, a[j].first, a[j].second, a[k].first, a[k].second, a[l].first, a[l].second)) {
                            pos = false;
                            break;
                        }
                    }
                }
                if (pos) {
#ifdef DEBUG
                    cout << i << " " << j << " " << k << "\n";
#endif
                    cout << dp[i][j][k] << "\n";
                    return 0;
                }
            }
        }
    }
    cout << 0 << "\n";
    return 0;
}



//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
//    freopen("1.out", "w", stderr);
//#endif
//}
//#define DEBUG
//const int maxn = 45, mod = 1e9 + 7;
//int dp[maxn][maxn][maxn][maxn][maxn][maxn][maxn][2];
//
//long long fact[maxn];
//
//const double eps = 1e-5;
//
//double triarea(int x1, int y1, int x2, int y2, int x3, int y3) {
//    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
//}
//
//bool in(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
//    double a = triarea(x1, y1, x2, y2, x3, y3);
//    double a1 = triarea(x, y, x2, y2, x3, y3);
//    double a2 = triarea(x1, y1, x, y, x3, y3);
//    double a3 = triarea(x1, y1, x2, y2, x, y);
//    return abs(a - (a1 + a2 + a3)) <= eps;
//}
//
//struct point {
//    long long x, y;
//    void operator-=(const point &rhs) {
//        x -= rhs.x;
//        y -= rhs.y;
//    }
//    point operator-(const point &rhs) const {
//        return point{x - rhs.x, y - rhs.y};
//    }
//    bool operator==(const point &rhs) const {
//        return x == rhs.x && y == rhs.y;
//    }
//    long long operator*(const point &rhs) const {
//        return (long long) x * rhs.y - (long long) y * rhs.x;
//    }
//    long long triangle(const point &b, const point &c) const {
//        return (b - *this) * (c - *this);
//    }
//    long long distsq(const point &rhs) {
//        return (x - rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y);
//    }
//};
//
//bool intersect(point p1, point p2, point p3, point p4) {
//    for (int rep = 0; rep < 2; ++rep) {
//        if ((p2 - p1) * (p4 - p3) == 0) {
//            // collinear or parallel
//            if (p1.triangle(p2, p3) != 0) {
//                // parallel
//                return false;
//            } else {
//                // collinear
//                for (int rep1 = 0; rep1 < 2; ++rep1) {
//                    if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
//                        return false;
//                    }
//                    swap(p1, p3);
//                    swap(p2, p4);
//                }
//            }
//            return true;
//        }
//        long long sign1 = (p2 - p1) * (p3 - p1), sign2 = (p2 - p1) * (p4 - p1);
//        if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
//            return false;
//        }
//        swap(p1, p3);
//        swap(p2, p4);
//    }
//    return true;
//}
//
//
//int main() {
//    setIO();
//    fact[0] = 1;
//    for (int i = 1; i < maxn; ++i) {
//        fact[i] = (fact[i - 1] * i) % mod;
//    }
//    int n;
//    cin >> n;
//    vector<pair<int, int>> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i].first >> a[i].second;
//    }
//    for (int j = 0; j < n; ++j) {
//        for (int k = j + 1; k < n; ++k) {
//            for (int l = k + 1; l < n; ++l) {
//                int i = 3;
//                int cur = 0;
//                for (int m = 0; m < n; ++m) {
//                    if (m != j && m != k && m != l) {
//                        if (in(a[j].first, a[j].second, a[k].first, a[k].second, a[l].first, a[l].second, a[m].first, a[m].second)) {
//                            ++cur;
//                        }
//                    }
//                }
//                dp[i + cur][j][k][l][j][k][l][0] = (6 * fact[cur]) % mod;
//#ifdef DEBUG
//                cout << dp[i + cur][j][k][l][j][k][l][0] << "\n";
//#endif
//            }
//        }
//    }
//    for (int i = 3; i <= n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            for (int k = j + 1; k < n; ++k) {
//                for (int l = k + 1; l < n; ++l) {
//                    for (int j1 = 0; j1 < n; ++j1) {
//                        for (int k1 = j1 + 1; k1 < n; ++k1) {
//                            for (int l1 = k1 + 1; l1 < n; ++l1) {
//                                if (dp[i][j][k][l][j1][k1][l1][1]) {
//                                    int cur = 0;
//                                    for (int m = 0; m < n; ++m) {
//                                        if (m != j && m != k && m != l && m != j1 && m != k1 && m != l1) {
//                                            if (in(a[j].first, a[j].second, a[k].first, a[k].second, a[l].first, a[l].second, a[m].first, a[m].second)) {
//                                                if (!in(a[j1].first, a[j1].second, a[k1].first, a[k1].second, a[l1].first, a[l1].second, a[m].first, a[m].second)) {
//                                                    ++cur;
//                                                }
//                                            }
//                                        }
//                                    }
//                                    dp[i + cur][j][k][l][j1][k1][l1][0] += (dp[i][j][k][l][j1][k1][l1][1] * fact[cur]) % mod;
//                                    dp[i + cur][j][k][l][j1][k1][l1][0] %= mod;
//                                }
//                                if (dp[i][j][k][l][j1][k1][l1][0]) {
//                                    for (int m = 0; m < n; ++m) {
//                                        if (m != j && m != k && m != l) {
//                                            if (in(a[j].first, a[j].second, a[k].first, a[k].second, a[l].first, a[l].second, a[m].first, a[m].second)) {
//                                                continue;
//                                            }
//                                            vector<point> p;
//                                            p.push_back(point{a[j].first, a[j].second});
//                                            p.push_back(point{a[k].first, a[k].second});
//                                            p.push_back(point{a[l].first, a[l].second});
//                                            vector<pair<point, point>> segments;
//                                            for (int i1 = 0; i1 < 3; ++i1) {
//                                                segments.emplace_back(p[i1], p[(i1 + 1) % 3]);
//                                            }
//                                            int conn = 0;
//                                            for (auto &j2 : p) {
//                                                bool cur = true;
//                                                for (auto k2 : segments) {
//                                                    if (k2.first == j2 || k2.second == j2) {
//                                                        continue;
//                                                    }
//                                                    if (intersect(point{a[m].first, a[m].second}, j2, k2.first, k2.second)) {
//                                                        cur = false;
//                                                        break;
//                                                    }
//                                                }
//                                                if (cur) {
//                                                    ++conn;
//                                                } else {
//                                                    break;
//                                                }
//                                            }
//                                            if (conn == 3) {
//                                                vector<int> d;
//                                                for (int i1 = 0; i1 < 3; ++i1) {
//                                                    d.push_back(p[i1].distsq(point{a[m].first, a[m].second}));
//                                                }
//                                                vector<int> next{j, k, l};
//                                                for (int i1 = 0; i1 < 3; ++i1) {
//                                                    if (d[i1] == *min_element(d.begin(), d.end())) {
//                                                        next.erase(next.begin() + i1);
//                                                        break;
//                                                    }
//                                                }
//                                                next.push_back(m);
//                                                sort(next.begin(), next.end());
//                                                dp[i + 1][next[0]][next[1]][next[2]][j][k][l][1] += dp[i][j][k][l][j1][k1][l1][0];
//                                                dp[i + 1][next[0]][next[1]][next[2]][j][k][l][1] %= mod;
//                                            }
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    long long sol = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            for (int k = 0; k < n; ++k) {
//                for (int l = 0; l < n; ++l) {
//                    for (int m = 0; m < n; ++m) {
//                        for (int i1 = 0; i1 < n; ++i1) {
////                            for (int k1 = 0; k1 < 2; ++k1) {
////
//#ifdef DEBUG
//                            if (dp[n][i][j][k][l][m][i1][0])
//                                cout << i << " " << j << " " << k << " " << l << " " << m << " " << i1 << " " << 0 << " " << dp[n][i][j][k][l][m][i1][0] << "\n";
//#endif
//                            sol += dp[n][i][j][k][l][m][i1][0];
//                            sol %= mod;
//                            //                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    cout << sol << "\n";
//    return 0;
//}
