/*
ID: izhang01
TASK: frac1
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<double, pair<int, int> > > sol;
    sol.emplace_back(0, make_pair(0, 1));
    sol.emplace_back(1, make_pair(1, 1));
    for (int i = 2; i < n + 1; ++i) {
        for (int j = 1; j < i; ++j) {
            bool pos = true;
            for (int k = 2; k < j + 1; ++k) {
                if (i % k == 0 && j % k == 0) {
                    pos = false;
                    break;
                }
            }
            if (pos) {
                sol.emplace_back((double) j / (double) i, make_pair(j, i));
            }
        }
    }
    sort(sol.begin(), sol.end());
    for (auto i : sol) {
        cout << i.second.first << "/" << i.second.second << "\n";
    }
    return 0;
}
