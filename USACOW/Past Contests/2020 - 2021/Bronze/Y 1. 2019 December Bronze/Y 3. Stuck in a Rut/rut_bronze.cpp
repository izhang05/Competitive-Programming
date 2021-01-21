#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("1.in", "r", stdin);
#endif
}
const int maxn = 1e3;
int grid[maxn][maxn], sol[maxn];

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
        sol[i] = -1;
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
                    sol[j.second] = e_dist;
                } else if (n_dist > e_dist) {
                    sol[i.second] = n_dist;
                    break;
                }
            }
        }
        for (auto j : to_erase) {
            east.erase(j);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (sol[i] == -1) {
            cout << "Infinity"
                 << "\n";
        } else {
            cout << sol[i] << "\n";
        }
    }
    return 0;
}
