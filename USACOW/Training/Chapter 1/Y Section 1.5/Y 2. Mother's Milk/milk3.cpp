/*
ID: izhang01
TASK: milk3
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> cap(3);
set<int> sol;
vector<vector<int> > visited;
vector<int> cur(3);

void dfs() {
    visited.push_back(cur);
    if (!cur[0]) {
        sol.insert(cur[2]);
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i != j) {
                vector<int> pre = cur;
                int pour = min(cur[i], cap[j] - cur[j]);
                cur[i] -= pour;
                cur[j] += pour;
                if (find(pre.begin(), pre.end(), cur) == pre.end()) {
                    dfs();
                }
                cur = pre;
            }
        }
    }
}


int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);

    cin >> cap[0] >> cap[1] >> cap[2];
    cur = {0, 0, cap[2]};
    dfs();
    auto it = sol.begin();
    cout << *it;
    sol.erase(it);
    for (int i : sol) {
        cout << " " << i;
    }
    cout << "\n";
    cout << 0x11 << "\n";
    return 0;
}
