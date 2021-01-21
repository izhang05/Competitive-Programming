/*
ID: izhang01
TASK: bteams
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> skill(12);
int player[12];
int team[4];
int sol = 1e9;

void solve(int n) {
//    cout << n << "\n";
    if (n == 12) {
        vector<int> team_skill(4, 0);
        for (int i = 0; i < 12; ++i) {
            team_skill[player[i]] += skill[i];
        }
        sol = min(sol, *max_element(team_skill.begin(), team_skill.end()) -
                       *min_element(team_skill.begin(), team_skill.end()));
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (team[i] < 3) {
            player[n] = i;
            ++team[i];
            solve(n + 1);
            --team[i];
        }
    }
}

int main() {
    freopen("bteams.in", "r", stdin);
    freopen("bteams.out", "w", stdout);
    for (int i = 0; i < 12; ++i) {
        cin >> skill[i];
    }
    solve(0);
    cout << sol << "\n";

    return 0;
}
