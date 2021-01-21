/*
ID: izhang01
TASK: snowboots
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
}


int main() {
    setIO();
    int n, b;
    cin >> n >> b;
    vector<pair<int, int>> tiles(n); // first = depth, second = original index
    vector<pair<pair<int, int>, int>> queries(b); // first = max depth, second = step size
    vector<int> sol(b);
    set<int> indexes;
    for (int i = 0; i < n; ++i) {
        cin >> tiles[i].first;
        tiles[i].second = i;
        indexes.insert(i);
    }
    sort(tiles.begin(), tiles.end(), greater<pair<int, int>>());
    for (int i = 0; i < b; ++i) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }
    sort(queries.begin(), queries.end(), greater<pair<pair<int, int>, int>>());
    int dist = 0, j = 0;
    for (int i = 0; i < b; ++i) {
        while (tiles[j].first > queries[i].first.first) {
            indexes.erase(tiles[j].second);
            auto it = indexes.upper_bound(tiles[j].second); // cannot = index.end() because tiles[j].second would be 0
            dist = max(dist, *it - *prev(it));
            ++j;
        }
        sol[queries[i].second] = queries[i].first.second >= dist;
    }
    for (int i = 0; i < b; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}


