/*
ID: izhang01
TASK: pairup
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int> > cows;
    int x, y, m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        cows.emplace_back(y, x);
        m += x;
    }
    sort(cows.begin(), cows.end());
    int count = 0;
    int sol = 0;
    int i = 0, j = n - 1;
    while (i <= j) {
        int min_cow = min(cows[i].second, cows[j].second);
        sol = max(sol, cows[i].first + cows[j].first);
        if (i == j) {
            min_cow /= 2;
        }
        cows[i].second -= min_cow;
        cows[j].second -= min_cow;
        if (cows[i].second == 0) {
            ++i;
        }
        if (cows[j].second == 0) {
            --j;
        }
    }
    cout << sol << "\n";
    return 0;
}
