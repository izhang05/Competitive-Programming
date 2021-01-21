/*
ID: izhang01
TASK: truth
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("truth.in", "r", stdin);
    freopen("truth.out", "w", stdout);
}


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    unordered_set<int> same[n];
    unordered_set<int> diff[n];
    int x, y;
    char t;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> t;
        --x, --y;
        if (t == 'T') {
            if (diff[x].find(y) != diff[x].end()) {
                cout << i << "\n";
                return 0;
            }
            if (diff[y].find(x) != diff[y].end()) {
                cout << i << "\n";
                return 0;
            }
            same[x].insert(y);
            same[y].insert(x);
        } else {
            if (same[x].find(y) != same[x].end()) {
                cout << i << "\n";
                return 0;
            }
            if (same[y].find(x) != same[y].end()) {
                cout << i << "\n";
                return 0;
            }
            diff[x].insert(y);
            diff[y].insert(x);
        }
    }
    cout << m << "\n";
    return 0;
}
