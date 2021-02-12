#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1e5;
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

    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int> > > edge;
    int a, b, c;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        edge.emplace_back(c, make_pair(a, b));
    }
    long long sol = 0, roads = 0;
    sort(edge.begin(), edge.end());
    for (auto i : edge) {
        if (!same(i.second.first, i.second.second)) {
            merge(i.second.first, i.second.second);
            assert(same(i.second.first, i.second.second));
            sol += i.first;
            ++roads;
            if (roads == n - 1) {
                break;
            }
        }
    }
    if (roads < n - 1) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        cout << sol << "\n";
    }
    return 0;
}
