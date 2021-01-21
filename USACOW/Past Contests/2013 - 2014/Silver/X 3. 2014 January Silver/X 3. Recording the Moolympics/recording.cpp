/*
ID: izhang01
TASK: recording
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("recording.in", "r", stdin);
    freopen("recording.out", "w", stdout);
}
const int maxn = 151;
int dp[2][maxn];

int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());

    return 0;
}
