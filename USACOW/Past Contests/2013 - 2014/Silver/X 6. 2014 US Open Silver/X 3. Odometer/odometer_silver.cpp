/*
ID: izhang01
TASK: odometer
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("odometer.in", "r", stdin);
    freopen("odometer.out", "w", stdout);
}

bool valid(int x) {
    int len = 0;
    map<int, int> occ;
    while (x) {
        ++occ[x % 10];
        x /= 10;
        ++len;
    }
    return any_of(occ.begin(), occ.end(), [len](pair<int, int> i) {
        return i.second * 2 >= len;
    });
}

int main() {
    setIO();
    long long x, y;
    cin >> x >> y;
    long long sol = 0;
    for (int i = x; i < y + 1; ++i) {
        if (valid(i)) {
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}
