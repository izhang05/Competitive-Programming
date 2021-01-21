/*
ID: izhang01
TASK: gates
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    string s;
    cin >> s;
    pair<int, int> pos;
    map<pair<int, int>, set<pair<int, int>>> pre_loc;
    int sol = 0;
    set<pair<int, int> > visited;
    visited.insert(pair<int, int>{0, 0});
    pair<int, int> pre = pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'N') {
            ++pos.second;
        } else if (s[i] == 'S') {
            --pos.second;
        } else if (s[i] == 'E') {
            ++pos.first;
        } else if (s[i] == 'W') {
            --pos.first;
        }
        if (visited.find(pos) == visited.end()) {
            visited.insert(pos);
            pre_loc[pos].insert(pre);
        } else {
            if (pre_loc[pos].find(pre) == pre_loc[pos].end()) {
                pre_loc[pos].insert(pre);
                ++sol;
            } else {
//                for (pair<int, int> i : pre_loc[pos]) {
//                    cout << i.first << " " << i.second << "\n";
//                }
//                cout << "\n";
//                cout << pos.first << " " << pos.second << "\n";
//                cout << "\n";
            }
        }
        pre_loc[pre].insert(pos);
        pre = pos;
    }
    cout << sol << "\n";
    return 0;
}
