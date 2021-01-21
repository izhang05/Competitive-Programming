/*
ID: izhang01
TASK: citystate
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int n;
    cin >> n;
    unordered_map<string, pair<int, int> > count;
    vector<pair<string, string> > cities(n);
    string a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        cities[i].first = a.substr(0, 2);
        cities[i].second = b;
    }
    for (auto i : cities) {
        string id = i.first + i.second;
        if (count.find(id) == count.end()) {
            if (count.find(i.second + i.first) == count.end()) {
                count[id] = pair<int, int>{1, 0};
            } else {
                ++count[i.second + i.first].second;
            }
        } else {
            ++count[id].first;
        }
//        id = i.second + i.first;
//        if (count.find(id) == count.end()) {
//            count[id] = pair<int, int>{0, 1};
//        } else {
//            ++count[id].second;
//        }
    }
    int sol = 0;
    for (auto i : count) {
//        cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
        sol += i.second.first * i.second.second;
    }
    cout << sol << "\n";
    return 0;
}
