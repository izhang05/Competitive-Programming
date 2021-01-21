/*
ID: izhang01
TASK: meetings
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
}

const int maxn = 5e4;

int main() {
    setIO();
    int n, l;
    cin >> n >> l;
    vector<vector<int> > cows(n, vector<int>(3));
    vector<pair<int, int> > endings(n);
    int total_weight = 0, l_ind = 0, r_ind = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cows[i][1] >> cows[i][0] >> cows[i][2];
        if (cows[i][2] == -1) {
            ++r_ind;
        }
        total_weight += cows[i][1];
    }
    sort(cows.begin(), cows.end());
    for (int i = 0; i < n; ++i) {
        if (cows[i][2] == -1) {
            endings[i] = make_pair(cows[i][0], cows[l_ind++][1]);
        } else {
            endings[i] = make_pair(l - cows[i][0], cows[r_ind++][1]);
        }
    }
    sort(endings.begin(), endings.end());
    int t = -1;
    for (pair<int, int> i : endings) {
        total_weight -= 2 * i.second;
        if (total_weight <= 0) {
            t = i.first;
            break;
        }
    }
    assert(t != -1);
    int sol = 0;
    cout << t << "\n";
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        while (!q.empty() && cows[i][0] > q.front()) {
            q.pop();
        }
        if (cows[i][2] == -1) {
            sol += q.size();
        } else {
            q.push(cows[i][0] + 2 * t);
        }
    }
    cout << sol << "\n";
    return 0;
}
