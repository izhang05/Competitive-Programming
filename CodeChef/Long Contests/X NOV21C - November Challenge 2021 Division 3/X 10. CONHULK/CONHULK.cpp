#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

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

    bool operator==(const point &rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool operator!=(const point &rhs) const {
        return !(*this == rhs);
    }

    long long norm() {
        return x * x + y * y;
    }
};

vector<long long> hullInd(const vector<point> &v) {
    int ind = int(min_element(v.begin(), v.end()) - begin(v));
    vector<long long> cand, C{ind};
    for (int i = 0; i < int(v.size()); ++i) {
        if (v[i] != v[ind]) cand.push_back(i);
    }
    sort(cand.begin(), cand.end(), [&](int a, int b) {
        // sort by angle, tiebreak by distance
        point x = v[a] - v[ind], y = v[b] - v[ind];
        long long t = x * y;
        return t != 0 ? t > 0 : x.norm() < y.norm();
    });
    for (auto &c : cand) {
        while (int(C.size()) > 1 && v[end(C)[-2]].triangle(v[C.back()], v[c]) <= 0) {
            C.pop_back();
        }
        C.push_back(c);
    }
    return C;
}

void solve() {
    int n;
    cin >> n;
    vector<point> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].x *= 2, a[i].y *= 2;
    }
    vector<point> b;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            b.push_back(point{(a[i].x + a[j].x) / 2, (a[i].y + a[j].y) / 2});
        }
    }
    cout << hullInd(b).size() << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
