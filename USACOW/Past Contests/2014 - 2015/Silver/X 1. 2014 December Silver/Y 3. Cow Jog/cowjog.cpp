/*
ID: izhang01
TASK: cowjog
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    vector<pair<int, int> > pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> pos[i].first >> pos[i].second;
        pos[i].second *= t;
        pos[i].second += pos[i].first;
    }
    int sol = 1;
    int pre = pos[n - 1].second;
    for (int i = n - 1; i >= 0; --i) {
        if (pos[i].second < pre) {
            ++sol;
            pre = pos[i].second;
        }
    }
    cout << sol << "\n";
    return 0;
}
