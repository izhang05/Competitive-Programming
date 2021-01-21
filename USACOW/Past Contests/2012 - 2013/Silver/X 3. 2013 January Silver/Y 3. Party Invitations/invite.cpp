/*
ID: izhang01
TASK: invite
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("invite.in", "r", stdin);
    freopen("invite.out", "w", stdout);
}


int main() {
    setIO();
    int n, g, s;
    cin >> n >> g;
    set<int> group[g];
    vector<int> in[n];
    for (int i = 0; i < g; ++i) {
        cin >> s;
        int a;
        for (int j = 0; j < s; ++j) {
            cin >> a;
            --a;
            group[i].insert(a);
            in[a].push_back(i);
        }
    }
    set<int> to_add{0};
    int sol = 0;
    while (!to_add.empty()) {
        ++sol;
        int cur = *to_add.begin();
        to_add.erase(to_add.begin());
        for (int i : in[cur]) {
            group[i].erase(cur);
            if (group[i].size() == 1) {
                to_add.insert(*group[i].begin());
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
