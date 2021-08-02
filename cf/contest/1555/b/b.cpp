/* Author: izhang05
 * Time: 07-30-2021 10:35:04
**/
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
const long double eps = 1e-6;
long double dist(pair<int, int> x, pair<int, int> y) {
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

int w, h;
long double solve(pair<pair<int, int>, pair<int, int>> table, pair<pair<int, int>, pair<int, int>> move) {
    pair<int, int> orig = move.first;
    long double cur = 1e18;
    if (move.first.first >= table.second.first || move.first.second >= table.second.second) {
        return 0;
    }
    int diff = min(table.second.first - move.first.first, w - move.second.first);
    move.first.first += diff;
    if (move.first.first < table.second.first) {
    } else {
        cur = move.first.first - orig.first;
    }
    move.first = orig;
    diff = min(table.second.second - move.first.second, h - move.second.second);
    move.first.second += diff;
    if (move.first.second < table.second.second) {
    } else {
        cur = min(cur, (long double) move.first.second - orig.second);
    }
    return cur;
}

int main() {
    //    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        cin >> w >> h;
        pair<pair<int, int>, pair<int, int>> table;
        cin >> table.first.first >> table.first.second >> table.second.first >> table.second.second;
        if (table.first.first < w - table.second.first) {
            int tmp = table.first.first;
            table.first.first = w - table.second.first;
            table.second.first = w - tmp;
        }
        if (table.first.second < h - table.second.second) {
            int tmp = table.first.second;
            table.first.second = h - table.second.second;
            table.second.second = h - tmp;
        }
        pair<int, int> add;
        cin >> add.first >> add.second;
        long double sol = solve({{0, 0}, add}, table);
        if (abs(sol - 1e18) < eps) {
            cout << -1 << "\n";
        } else {
            cout << fixed << setprecision(16) << sol << "\n";
        }
    }
    return 0;
}
