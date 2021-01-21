/*
ID: izhang01
TASK: fuel
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fuel.in", "r", stdin);
    freopen("fuel.out", "w", stdout);
}


int main() {
    setIO();
    int n, cap, cur, d;
    cin >> n >> cap >> cur >> d;
    vector<pair<int, int>> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i].first >> f[i].second;
    }
    f.emplace_back(0, 1e9 + 1);
    f.emplace_back(d, 0);
    sort(f.begin(), f.end());
    long long sol = 0;
    set<pair<int, int>> reachable;
    int j = 0;
    for (int i = 0; i < n + 1; ++i) {
        j = max(i, j);
        while (j < n + 2 && f[j].first - f[i].first <= cap) {
            reachable.insert(make_pair(f[j].second, f[j].first));
            ++j;
        }
        reachable.erase(make_pair(f[i].second, f[i].first));
        if (reachable.empty()) {
            cout << -1 << "\n";
            return 0;
        }
        if (reachable.begin()->first < f[i].second) {
            sol += max(0, reachable.begin()->second - f[i].first - cur) * f[i].second;
        } else {
            sol += (cap - cur) * f[i].second;
        }
        cur -= f[i + 1].first - f[i].first;
    }
    cout << sol << "\n";
    return 0;
}
