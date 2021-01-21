/*
ID: izhang01
TASK: helpcross
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int c, n;
    cin >> c >> n;
    multiset<int> chicken;
    int ci;
    for (int i = 0; i < c; ++i) {
        cin >> ci;
        chicken.insert(ci);
    }
    vector<pair<int, int> > cow(n);
    for (int i = 0; i < n; ++i) {
        cin >> cow[i].second >> cow[i].first;
    }
    sort(cow.begin(), cow.end());
//    for (int i : chicken) {
//        cout << i << "\n";
//    }
//    for (auto i : cow) {
//        cout << i.first << " " << i.second << "\n";
//    }
    int sol = 0;
    for (pair<int, int> i : cow) {
//        cout << i.second << " " << i.first << endl;
        if (chicken.empty()) {
            break;
        }
        auto it = chicken.lower_bound(i.second);
        if (it == chicken.end()) {
            continue;
        }
        if (*it <= i.first) {
            ++sol;
            chicken.erase(it);
        }
    }
    cout << sol << "\n";
    return 0;
}
