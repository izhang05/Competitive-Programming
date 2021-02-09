/*
ID: izhang01
TASK: mountains
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n;
    cin >> n;
    set<int> nums;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());
    set<pair<int, int>> blocked;
    pair<int, int> pre = points[0];
    for (int i = 1; i < n; ++i) {
        if (pre.second - (points[i].first - pre.first) >= points[i].second) {
            blocked.insert(points[i]);
        } else {
            pre = points[i];
        }
    }

    pre = points[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if (pre.second - (pre.first - points[i].first) >= points[i].second) {
            blocked.insert(points[i]);
        } else {
            pre = points[i];
        }
    }
    cout << n - blocked.size() << "\n";
    return 0;
}
