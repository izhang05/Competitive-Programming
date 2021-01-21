/*
ID: izhang01
TASK: crazy
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crazy.in", "r", stdin);
    freopen("crazy.out", "w", stdout);
}

const int maxn = 1000;
int cur_comp;
map<int, int> comp;
bool visited[maxn];


int main() {
    setIO();
    int n, c;
    cin >> n >> c;
    vector<pair<pair<int, int>, pair<int, int>>> points(n);
    map<pair<int, int>, set<int>> line;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first.first >> points[i].first.second >> points[i].second.first >> points[i].second.second;
        line[points[i].first].insert(i);
        line[points[i].second].insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (visited[i]) {
            continue;
        }
        int cur = i;
        while (true) {
            comp[cur] = cur_comp;
            for (int i : line[points[i]])
        }
        ++cur_comp;
    }
    return 0;
}
