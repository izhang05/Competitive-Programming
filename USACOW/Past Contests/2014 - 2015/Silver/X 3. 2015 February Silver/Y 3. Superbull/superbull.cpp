/*
ID: izhang01
TASK: superbull
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
}

const int maxn = 2000;
int parent[maxn];

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void merge(int x, int y) {
    parent[find(x)] = y;
}

int main() {
    setIO();
    int n;
    cin >> n;
    vector<unsigned long long> teams(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        cin >> teams[i];
    }
    vector<pair<unsigned long long, pair<int, int> > > adj;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            adj.emplace_back(teams[i] ^ teams[j], make_pair(i, j));
        }
    }
    sort(adj.begin(), adj.end());
    reverse(adj.begin(), adj.end());
    long long sol = 0;
    for (auto i : adj) {
        if (!same(i.second.first, i.second.second)) {
            sol += i.first;
            merge(i.second.first, i.second.second);
        }
    }
    cout << sol << "\n";
    return 0;
}
