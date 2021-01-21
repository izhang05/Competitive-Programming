/*
ID: izhang01
TASK: marathon
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    int n;
    cin >> n;
    long long total = 0;
    vector<pair<int, int> > points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    pair<int, int> pre = points[0];
    int save = 0;
    for (int i = 1; i < n; ++i) {
        total += abs(points[i].first - pre.first) + abs(points[i].second - pre.second);
        pre = points[i];
    }
    pre = points[0];
    for (int i = 1; i < n - 1; ++i) {
        int orig = abs(points[i].first - pre.first) + abs(points[i].second - pre.second) +
                   abs(points[i].first - points[i + 1].first) + abs(points[i].second - points[i + 1].second);
        save = max(save, orig - (abs(pre.first - points[i + 1].first) + abs(pre.second - points[i + 1].second)));
        pre = points[i];
    }
    cout << total - save << "\n";
    return 0;
}
