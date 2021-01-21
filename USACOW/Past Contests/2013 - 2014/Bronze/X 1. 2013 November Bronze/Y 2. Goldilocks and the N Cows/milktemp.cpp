/*
ID: izhang01
TASK: milktemp
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

struct temp {
    int cold, good, hot;
};

int main() {
    freopen("milktemp.in", "r", stdin);
    freopen("milktemp.out", "w", stdout);
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; ++i) {
        cin >> start[i] >> end[i];
    }
    int sol =  y + (n - 1) * x;
    vector<int> state{0, 1, n - 1};
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int ind = 0;
    for (int i = 1; i < n; ++i) {
        ++state[1];
        --state[2];
        while (end[ind] < start[i]) {
            ++ind;
            ++state[0];
            --state[1];
        }
        sol = max(sol, z * state[0] + y * state[1] + x * state[2]);
//        cout << start[i] << " " << state[0] << " " << state[1] << " " << state[2] << "\n";
    }
    cout << sol << "\n";
    return 0;
}
