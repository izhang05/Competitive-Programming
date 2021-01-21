/*
ID: izhang01
TASK: boards
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
}
const int maxp = 1e5 + 1;
int dp[maxp];

struct point {
    int x, y;
    bool operator<(const point &rhs) const {
        x == rhs.x ? y < rhs.y : x < rhs.x;
    }
};


int main() {
    setIO();
    int n, p;
    cin >> n >> p;

    vector<pair<point, point>> a;
    for (int i = 0; i < p; ++i) {
        cin >> a[i].first.x >> a[i].first.y >> a[i].second.x >> a[i].second.y;
    }
    sort(a.begin(), a.end());
    return 0;
}
