/*
ID: izhang01
TASK: lifeguards
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int> > interval(n);
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        interval[i] = pair<int, int>{a, b - 1};
    }
    sort(interval.begin(), interval.end());
    int total = 0, pre_start = interval[0].first, pre_end = interval[0].second;
    for (int i = 0; i < n; ++i) {
        if (interval[i].first <= pre_end) {
            pre_end = max(interval[i].second, pre_end);
        } else {
            total += pre_end - pre_start + 1;
            pre_start = interval[i].first;
            pre_end = interval[i].second;
        }
    }
    total += pre_end - pre_start + 1;
    int sub = min(interval[0].second, interval[1].first) - interval[0].first;
    int maximum = interval[0].second;
    for (int i = 1; i < n - 1; ++i) {
        if (maximum > interval[i].second) {
            sub = 0;
            break;
        }
        sub = min(sub, min(interval[i].second, interval[i + 1].first) - maximum - 1);
        maximum = max(maximum, interval[i].second);
    }
    sub = min(sub, max(0, interval[n - 1].second - maximum));
    cout << total - sub << "\n";
    return 0;
}
