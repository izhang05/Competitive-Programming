#include <bits/stdc++.h>

using namespace std;

struct range {
    vector<int> x;
    int y;
    long long v;
};


struct fract {
    __int128 num, den;

    fract(long long x) {
        num = x, den = 1;
    }

    fract(__int128 x, __int128 y) {
        __int128 g = __gcd(abs(x), abs(y));
        if (x < 0 && y < 0) {
            x = abs(x), y = abs(y);
        }
        num = x / g, den = y / g;
    }

    bool operator<(const fract &other) const {
        return num * other.den < den * other.num;
    };

    bool operator==(const fract &other) const {
        return num * other.den == den * other.num;
    };

    bool operator!=(const fract &other) const {
        return num * other.den != den * other.num;
    };

    bool operator<=(const fract &other) const {
        return *this < other || *this == other;
    };

    bool operator>(const fract &other) const {
        return num * other.den > den * other.num;
    };

    bool operator>=(const fract &other) const {
        return *this > other || *this == other;
    };

    fract operator*(long long x) const {
        return fract(num * x, den);
    }

    fract operator+(const fract &other) const {
        __int128 l = lcm(den, other.den);
        return fract((num * l / den) + (other.num * l / other.den), l);
    }


};

fract slope(int x0, int y0, int x1, int y1) {
    return fract(y1 - y0, x1 - x0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<range> a(n);
    long long sol = 0;
    for (auto &i: a) {
        i.x.resize(2);
        cin >> i.x[0] >> i.x[1] >> i.y;
        sort(i.x.begin(), i.x.end());
        i.v = i.x[1] - i.x[0];
        sol = max(sol, i.v);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            long long cur = 0;
            for (int k = 0; k < n; ++k) {
                if (a[k].x[0] <= a[i].x[j] && a[k].x[1] >= a[i].x[j]) {
                    cur += a[k].v;
                }
            }
            sol = max(sol, cur);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            vector<pair<fract, int>> points;
            for (int k = 0; k < n; ++k) {
                if (i != k && a[i].y != a[k].y) {
                    for (int l = 0; l < 2; ++l) {
                        if (a[i].x[j] == a[k].x[l]) {
                            continue;
                        }
                        points.emplace_back(slope(a[i].x[j], a[i].y, a[k].x[l], a[k].y), k);
                    }
                }
            }
            if (points.empty()) {
                continue;
            }
            sort(points.begin(), points.end());
            long long cur_sol = a[i].v;
            set<int> cur{i};
            fract cur_slope = points[0].first;
            for (int k = 0; k < n; ++k) {
                if (a[i].y == a[k].y) {
                    continue;
                }
                if (cur_slope * (a[k].x[0] - a[i].x[j]) + fract(a[i].y) <= fract(a[k].y) &&
                    cur_slope * (a[k].x[1] - a[i].x[j]) + fract(a[i].y) >= fract(a[k].y)) {
                    cur_sol += a[k].v;
                    cur.insert(k);
                }
            }
            sol = max(sol, cur_sol);
            fract pre = cur_slope;
            set<int> to_erase;
            for (int k = 1; k < int(points.size()); ++k) {
                assert(points[k].first != fract(0));
                while (k < int(points.size()) && points[k].first == cur_slope) {
                    ++k;
                }
                if (points[k].first != pre) {
                    for (auto &l: to_erase) {
                        cur_sol -= a[l].v;
                        cur.erase(l);
                    }
                    to_erase.clear();
                }
                if (cur.find(points[k].second) == cur.end()) {
                    cout << "new " << (cur.find(points[k].second) == cur.end()) << "\n";
                    cur_sol += a[points[k].second].v;
                    cur.insert(points[k].second);
                } else {
                    cout << "already in" << "\n";
                    to_erase.insert(points[k].second);
                }
                cout << i << " " << j << " " << k << ": ";
                for (auto &l: cur) {
                    cout << l << " ";
                }
                cout << "\n";
                cout << "to_erase: ";
                for (auto &l: to_erase) {
                    cout << l << " ";
                }
                cout << "\n";
                cout <<points[k].second << " " << (cur.find(points[k].second) == cur.end()) << "\n";

                sol = max(sol, cur_sol);
                pre = points[k].first;
                cout << "slope: " << (long long) pre.num << " " << (long long) pre.den << "\n";
                cout << "\n";
            }
        }
    }
    cout << sol << "\n";
}