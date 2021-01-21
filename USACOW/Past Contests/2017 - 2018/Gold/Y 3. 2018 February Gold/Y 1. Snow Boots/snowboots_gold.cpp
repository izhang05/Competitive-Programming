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

const int maxn = 1e5 + 1;
int parent[maxn], size[maxn];


int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

void merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot == yroot) {
        return;
    }
    if (size[xroot] > size[yroot]) {
        parent[yroot] = xroot;
        size[xroot] += size[yroot];
    } else {
        parent[xroot] = yroot;
        size[yroot] += size[xroot];
    }
}


int main() {
    setIO();
    int n, b;
    cin >> n >> b;
    vector<pair<int, int> > tiles(n); // first = depth, second = original index
    vector<pair<pair<int, int>, int> > queries(b); // first = step size, second = max depth
    vector<int> sol(b);
    multiset<int, greater<int> > depths;
    for (int i = 0; i < n; ++i) {
        cin >> tiles[i].first;
        tiles[i].second = i;
        depths.insert(tiles[i].first);
        parent[i] = i;
    }
    sort(tiles.begin(), tiles.end(), greater<pair<int, int> >());
    for (int i = 0; i < b; ++i) {
        cin >> queries[i].first.second >> queries[i].first.first;
        queries[i].second = i;
    }
    sort(queries.begin(), queries.end());
    int j = 0;
    for (int i = 0; i < b; ++i) {
        bool flag = true;
        while (flag && queries[i].first.first != 1) {
            if (j >= n || tiles[j].second == 0) {
                break;
            }
            flag = false;
            int ind = tiles[j].second;
            if (size[get(ind - 1)] == 0) {
                if (size[get(ind + 1)] == 0) {
                    size[ind] = 1;
                    flag = true;
                } else if (size[get(ind + 1)] + 1 < queries[i].first.first) {
                    size[ind] = 1;
                    merge(ind, ind + 1);
                    flag = true;
                }
            } else if (size[get(ind + 1)] == 0) {
                if (size[get(ind - 1)] + 1 < queries[i].first.first) {
                    size[ind] = 1;
                    merge(ind, ind - 1);
                    flag = true;
                }
            } else {
                if (size[get(ind - 1)] + size[get(ind + 1)] + 1 < queries[i].first.first) {
                    size[ind] = 1;
                    merge(ind - 1, ind);
                    merge(ind, ind + 1);
                    flag = true;
                }
            }
            if (flag) {
                depths.erase(depths.find(tiles[j++].first));
                if (j >= n) {
                    break;
                }
            }
        }
        int cur = queries[i].first.first;
        sol[queries[i].second] = queries[i].first.second >= *depths.begin();
        if (i == n - 1) {
            break;
        }
        while (queries[i + 1].first.first == cur) {
            ++i;
            sol[queries[i].second] = queries[i].first.second >= *depths.begin();
            if (i == n - 1) {
                break;
            }
        }
    }
    for (int i = 0; i < b; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
