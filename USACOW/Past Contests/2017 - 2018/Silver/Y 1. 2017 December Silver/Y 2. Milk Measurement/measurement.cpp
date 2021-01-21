/*
ID: izhang01
TASK: measurement
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n, g;
    cin >> n >> g;
    vector<pair<pair<int, int>, int>> a(n);
    map<int, int> milk;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
        milk[a[i].first.second] = g;
    }
    sort(a.begin(), a.end());

    return 0;
}
