/*
ID: izhang01
TASK: stampede
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("stampede.in", "r", stdin);
    freopen("stampede.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int>> times(2 * n);
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a = -a;
        times[2 * i] = make_pair((a - 1) * c, b);
        times[2 * i + 1] = make_pair(a * c, -b);
    }
    sort(times.begin(), times.end());
    set<int> cur, sol;
    for (int i = 0; i < 2 * n;) {
        int j = i;
        for (; j < 2 * n && times[i].first == times[j].first; ++j) {
            if (times[j].second > 0) {
                cur.insert(times[j].second);
            } else {
                cur.erase(-times[j].second);
            }
        }
        if (!cur.empty()) {
            sol.insert(*cur.begin());
        }
        i = j;
    }
    cout << sol.size() << "\n";
    return 0;
}
