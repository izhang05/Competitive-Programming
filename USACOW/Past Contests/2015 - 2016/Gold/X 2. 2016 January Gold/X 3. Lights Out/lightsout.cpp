/*
ID: izhang01
TASK: lightsout
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    int perimeter;
    vector<int> anti(n), clock(n);
    cin >> p[0].first >> p[0].second;
    pair<int, int> pre = p[0];
    for (int i = 1; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
        perimeter += abs(p[i].first - pre.first) + abs(p[i].second - pre.second);
        pre = p[i];
        anti[i] = perimeter;
    }
    for (int i = 1; i < n; ++i) {
        clock[i] = perimeter - anti[i];
    }
    int sol = 0;
    for (int i = 1; i < n; ++i) {

    }
    return 0;
}
