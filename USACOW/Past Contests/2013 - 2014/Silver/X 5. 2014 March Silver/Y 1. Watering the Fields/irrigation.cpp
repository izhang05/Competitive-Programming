/*
ID: izhang01
TASK: irrigation
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("irrigation.in", "r", stdin);
    freopen("irrigation.out", "w", stdout);
}
const int maxn = 2e3 + 5, inf = 1e9 + 1;
int cost[maxn];
bool con[maxn];

int dist(pair<int, int> x, pair<int, int> y) {
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}


int main() {
    setIO();
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        int cur = dist(a[0], a[i]);
        if (cur >= c) {
            cost[i] = cur;
        } else {
            cost[i] = inf;
        }
    }
    con[0] = true;
    long long sol = 0;
    for (int _ = 0; _ < n - 1; ++_) {
        pair<int, int> min_cost = {inf, 0};
        for (int i = 0; i < n; ++i) {
            if (!con[i]) {
                min_cost = min(min_cost, {cost[i], i});
            }
        }
        if (min_cost.first == inf) {
            cout << -1 << "\n";
            return 0;
        }
        sol += min_cost.first;
        con[min_cost.second] = true;
        for (int i = 0; i < n; ++i) {
            if (!con[i]) {
                int cur = dist(a[i], a[min_cost.second]);
                if (cur >= c) {
                    cost[i] = min(cost[i], cur);
                }
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
