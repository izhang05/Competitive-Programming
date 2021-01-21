/*
ID: izhang01
TASK: socdist2
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int> > cows(n);
    vector<int> sick;
    int x, s;
    for (int i = 0; i < n; ++i) {
        cin >> x >> s;
        cows[i] = pair<int, int>{x, s};
        if (s == 1) {
            sick.push_back(x);
        }
    }
    sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });
    int previous = cows[0].second;
    int r = 1e9;
    for (int i = 1; i < n; ++i) {
        if (cows[i].second != previous) {
            r = min(r, cows[i].first - cows[i - 1].first - 1);
            previous = cows[i].second;
        }
    }
    int solution = 1;
    sort(sick.begin(), sick.end());
    int previous_cow = sick[0];
    for (int i = 1; i < sick.size(); ++i) {
        if (sick[i] - previous_cow > r) {
//            cout << previous_cow << " " << sick[i] << "\n";
            ++solution;
        }
        previous_cow = sick[i];
    }
    cout << solution << "\n";
    return 0;
}
