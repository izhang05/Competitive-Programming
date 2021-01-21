/*
ID: izhang01
TASK: split
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
}

const long long inf = 1e18;

int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    set<long long> x;
    multiset<long long> y;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
        x.insert(points[i].first);
        y.insert(points[i].second);
    }
    map<int, vector<int>> col_p;
    for (int i = 0; i < n; ++i) {
        col_p[points[i].first].push_back(points[i].second);
    }
    long long orig = (*x.rbegin() - *x.begin()) *
                     (*y.rbegin() - *y.begin()), sol = orig, left = *x.begin(), top = 0, bottom = inf;
    for (auto it = x.begin(); next(it) != x.end(); ++it) {
        long long right = *it;
        for (long long i : col_p[right]) {
            top = max(top, i);
            bottom = min(bottom, i);
            y.erase(y.find(i));
        }
        sol = min(sol,
                  (right - left) * (top - bottom) + (*x.rbegin() - *next(it)) * (*y.rbegin() - *y.begin()));
//        cout << sol << " " << (right - left) * (top - bottom) + (*x.rbegin() - *next(it)) * (*y.rbegin() - *y.begin()) << "\n";
    }
    cout << orig << "\n";
    cout << orig - sol << "\n";
    return 0;
}
