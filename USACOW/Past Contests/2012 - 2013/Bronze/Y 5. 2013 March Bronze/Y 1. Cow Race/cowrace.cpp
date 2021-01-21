/*
ID: izhang01
TASK: cowrace
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowrace.in", "r", stdin);
    freopen("cowrace.out", "w", stdout);
}


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].first >> b[i].second;
    }
    int sol = 0, i = 0, j = 0, cur = 0, a_loc = 0, b_loc = 0, pre = -1;
    while (true) {
        int dist = min(a[i].second, b[j].second);
        a[i].second -= dist, b[j].second -= dist;
        a_loc += dist * a[i].first;
        b_loc += dist * b[j].first;
        if (a_loc > b_loc) {
            if (pre == 2) {
                ++sol;
            }
            pre = 1;
        }
        if (b_loc > a_loc) {
            if (pre == 1) {
                ++sol;
            }
            pre = 2;
        }
        if (a[i].second == 0) {
            ++i;
        }
        if (b[j].second == 0) {
            ++j;
        }
        if (i == n || j == m) {
            break;
        }
    }
    cout << sol << "\n";
    return 0;
}
