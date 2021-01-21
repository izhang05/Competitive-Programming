/*
ID: izhang01
TASK: convention2
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int> > cows(n, vector<int>(3));
    map<int, int> index;
    for (int i = 0; i < n; ++i) {
        cin >> cows[i][0] >> cows[i][1];
        cows[i][2] = i;
        index[i] = cows[i][0];
    }
    sort(cows.begin(), cows.end());
    set<pair<int, int> > waiting;
    int time = cows[0][0];
    int sol = 0;
    for (int i = 0; i < cows.size(); ++i) {
//        cout << cows[i][0] << " " << cows[i][1] << " " << cows[i][2] << " " << time << "\n";
        if (cows[i][0] <= time) {
            waiting.insert(pair<int, int>{cows[i][2], cows[i][1]});
        } else if (!waiting.empty()) {
            --i;
            pair<int, int> current = *waiting.begin();
//            for (auto j : waiting) {
//                cout << j.first << " " << j.second << "\n";
//            }
            waiting.erase(waiting.begin());
//            cout << current.first << " " << current.second << "\n";
            sol = max(sol, time - index[current.first]);
//            cout << sol << "\n";
            time += current.second;
        } else {
            waiting.insert(pair<int, int>{cows[i][2], cows[i][1]});
            time = cows[i][0];
        }
    }
    for (auto i : waiting) {
        pair<int, int> current = i;
//            for (auto j : waiting) {
//                cout << j.first << " " << j.second << "\n";
//            }
//        cout << current.first << " " << current.second << "\n";
        sol = max(sol, time - index[current.first]);
//        cout << sol << "\n";
        time += current.second;
    }
    cout << sol << "\n";

    return 0;
}
