#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
#endif
}
const int maxn = 1e3;
int grid[maxn][maxn], blame[maxn];

int dist(pair<int, int> x, pair<int, int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int main() {
    setIO();
    int n;
    cin >> n;
    set<pair<pair<int, int>, int>> north, east; // set<x, y, ind>
    char c;
    pair<int, int> a;
    for (int i = 0; i < n; ++i) {
        cin >> c >> a.first >> a.second;
        if (c == 'N') {
            north.insert(make_pair(a, i));
        } else {
            swap(a.first, a.second);
            east.insert(make_pair(a, i));
        }
    }
    for (pair<pair<int, int>, int> i : north) {
        vector<pair<pair<int, int>, int>> to_erase;
        for (pair<pair<int, int>, int> j : east) {
            swap(j.first.first, j.first.second);
            if (j.first.first <= i.first.first && j.first.second >= i.first.second) {
                pair<int, int> meet{i.first.first, j.first.second};
                int n_dist = dist(i.first, meet), e_dist = dist(j.first, meet);
                if (n_dist < e_dist) {
                    swap(j.first.first, j.first.second);
                    to_erase.push_back(j);
                    blame[i.second] += blame[j.second] + 1;
                } else if (n_dist > e_dist) {
                    blame[j.second] += blame[i.second] + 1;
                    break;
                }
            }
        }
        for (auto j : to_erase) {
            east.erase(j);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << blame[i] << "\n";
    }
    return 0;
}
