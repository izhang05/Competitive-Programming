/*
ID: izhang01
TASK: crossings
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crossings.in", "r", stdin);
    freopen("crossings.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    set<pair<int, int>> pre;
    pre.insert(make_pair(a[0].second, 0));
    int sol = 0, farthest = a[0].second;
    for (int i = 1; i < n; ++i) {
        if (a[i].second < farthest) {
            auto it = pre.lower_bound(make_pair(a[i].second, 0));
            for (; it != pre.end();) {
                ++sol;
                it = pre.erase(it);
            }
            ++sol;
        } else {
            pre.insert(make_pair(a[i].second, i));
        }
        farthest = max(farthest, a[i].second);
    }
    cout << n - sol << "\n";
    return 0;
}
