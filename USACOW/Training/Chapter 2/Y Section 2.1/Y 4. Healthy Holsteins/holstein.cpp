/*
ID: izhang01
TASK: holstein
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
}


int main() {
    setIO();
    int v;
    cin >> v;
    vector<int> vit(v);
    for (int i = 0; i < v; ++i) {
        cin >> vit[i];
    }
    int g;
    cin >> g;
    int feed[g][v];
    for (int i = 0; i < g; ++i) {
        for (int j = 0; j < v; ++j) {
            cin >> feed[i][j];
        }
    }
    pair<int, vector<int>> sol;
    sol.first = 1e9;
    for (int i = 0; i < 1 << g; ++i) {
        pair<int, vector<int>> cur_sol;
        vector<int> cur_feed(v);
        for (int j = 0; j < g; ++j) {
            if (i & (1 << j)) {
                ++cur_sol.first;
                cur_sol.second.push_back(j);
                for (int k = 0; k < v; ++k) {
                    cur_feed[k] += feed[j][k];
                }
            }
        }
        bool pos = true;
        for (int j = 0; j < v; ++j) {
            if (cur_feed[j] < vit[j]) {
                pos = false;
                break;
            }
        }
        if (pos) {
            sol = min(sol, cur_sol);
        }
    }
    cout << sol.first;
    for (int i = 0; i < sol.first; ++i) {
        cout << " " << sol.second[i] + 1;
    }
    cout << "\n";
    return 0;
}
