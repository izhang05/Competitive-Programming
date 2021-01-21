/*
ID: izhang01
TASK: teleport
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<long long, long long> > transport(n);
    map<long long, int> slope_change;
    for (int i = 0; i < n; ++i) {
        cin >> transport[i].first >> transport[i].second;
    }
    long long time = 0;
    for (pair<long long, long long> i : transport) {
        long long dist = abs(i.first - i.second);
        time += dist;
        if (abs(i.first) < dist) {
            if (i.first < 0 && i.second > i.first || i.first >= 0 && i.second < i.first) {
                if (slope_change.find(0) == slope_change.end()) {
                    slope_change[0] = 0;
                }
                --slope_change[0];
                if (slope_change.find(i.second) == slope_change.end()) {
                    slope_change[i.second] = 0;
                }
                slope_change[i.second] += 2;
                if (slope_change.find(i.second * 2) == slope_change.end()) {
                    slope_change[i.second * 2] = 0;
                }
                --slope_change[i.second * 2];
            } else {
                if (slope_change.find(i.first * 2) == slope_change.end()) {
                    slope_change[i.first * 2] = 0;
                }
                --slope_change[i.first * 2];
                if (slope_change.find(i.second) == slope_change.end()) {
                    slope_change[i.second] = 0;
                }
                slope_change[i.second] += 2;
                if (slope_change.find(2 * (i.second - i.first)) == slope_change.end()) {
                    slope_change[2 * (i.second - i.first)] = 0;
                }
                --slope_change[2 * (i.second - i.first)];
            }
        }
    }
    long long slope = 0, pre, sol = 1e18;
    for (auto i : slope_change) {
        time += (i.first - pre) *  slope;
        slope += i.second;
        sol = min(sol, time);
        //        cout << i.first << " " <<  time << " " << slope << "\n";
        pre = i.first;
    }
    cout << sol << "\n";
    return 0;
}
