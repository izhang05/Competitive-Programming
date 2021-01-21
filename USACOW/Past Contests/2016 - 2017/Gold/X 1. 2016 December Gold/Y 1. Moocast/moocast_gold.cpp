/*
ID: izhang01
TASK: mootube_gold
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
}

const int maxn = 1000;
int parent[maxn], comp;

int dist(pair<int, int> x, pair<int, int> y) { // return distance squared
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

int merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot == yroot) {
        return 0;
    }
    parent[yroot] = xroot;
    return --comp;
}


int main() {
    setIO();
    int n;
    cin >> n;
    comp = n;
    vector<pair<int, int> > cows(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].first >> cows[i].second;
        parent[i] = i;
    }
    vector<pair<int, pair<int, int> > > paths;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            paths.emplace_back(dist(cows[i], cows[j]), make_pair(i, j));
        }
    }
    sort(paths.begin(), paths.end());
    for (auto i : paths) {
        if (merge(i.second.first, i.second.second) == 1) {
            cout << i.first << "\n";
            break;
        }
    }
    return 0;
}
