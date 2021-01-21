/*
ID: izhang01
TASK: fairphoto
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fairphoto.in", "r", stdin);
    freopen("fairphoto.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, char>> cows(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end());
    vector<int> pre(n);
    pre[0] = 0;
    if (cows[0].second == 'G') {
        --pre[0];
    } else {
        ++pre[0];
    }
    for (int i = 1; i < n; ++i) {
        if (cows[i].second == 'G') {
            pre[i] = pre[i - 1] - 1;
        } else {
            pre[i] = pre[i - 1] + 1;
        }
    }

    int sol = 0;
    vector<int> occur(2 * n, -1);
    int pre_same = cows[0].first;
    char pre_cow = cows[0].second;
    for (int i = 0; i < n; ++i) {
        if (occur[pre[i] + n] != -1) {
            sol = max(sol, cows[i].first - cows[occur[pre[i] + n] + 1].first);
        } else {
            occur[pre[i] + n] = i;
        }
        if (cows[i].second == pre_cow) {
            sol = max(sol, cows[i].first - pre_same);
        } else {
            pre_same = cows[i].first;
            pre_cow = cows[i].second;
        }
    }
    cout << sol << "\n";
    return 0;
}
