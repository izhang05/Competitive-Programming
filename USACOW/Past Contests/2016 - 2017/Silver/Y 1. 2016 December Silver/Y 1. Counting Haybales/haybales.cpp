/*
ID: izhang01
TASK: haybales
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
int visited[MAXN];

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    int h;
    set<int> hay;
    set<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> h;
        hay.insert(h);
        nums.insert(h);
    }
    vector<pair<int, int> > queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        nums.insert(queries[i].first);
        nums.insert(queries[i].second);
    }
    map<int, int> index;
    int ind = 1;
    for (int i : nums) {
        index[i] = ind;
        ++ind;
    }
    for (int i : hay) {
        ++visited[index[i]];
    }

    for (int i : nums) {
        visited[index[i]] += visited[index[i] - 1];
    }
    for (auto i : queries) {
        cout << visited[index[i.second]] - visited[index[i.first] - 1] << "\n";
    }

    return 0;
}
