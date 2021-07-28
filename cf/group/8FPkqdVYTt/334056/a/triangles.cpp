/* Author: izhang05
 * Time: 07-27-2021 23:41:13
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
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
    long long triangle(const point &b, const point &c) const { // positive iff a is to the left of line (b,c)
        return (b - *this) * (c - *this);
    }
};
const int maxn = 305;
bitset<maxn> b[maxn][maxn];

int main() {
    setIO("triangles");

    int n;
    cin >> n;
    vector<point> a(n);
    vector<int> sol(n - 2);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                for (int k = 0; k < n; ++k) {
                    if (a[k].triangle(a[i], a[j]) > 0) {
                        b[k][i][j] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                vector<int> t = {i, j, k};
                if (a[t[0]].triangle(a[t[1]], a[t[2]]) < 0) {
                    swap(t[1], t[2]);
                }
                auto cur = b[t[0]][t[1]] & b[t[1]][t[2]] & b[t[2]][t[0]];
                ++sol[cur.count()];
            }
        }
    }
    for (int i = 0; i < n - 2; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
