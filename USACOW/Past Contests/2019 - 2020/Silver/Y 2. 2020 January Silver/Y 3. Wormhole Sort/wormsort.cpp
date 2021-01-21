/*
ID: izhang01
TASK: wormsort
LANG: C++11
*/


#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
}

// Binary search DFS solution

//const int maxn = 1e5;
//int n, m, cows[maxn], comp[maxn], num_comp;
//set<int> components[maxn];
//vector<int> adj[maxn];
//bool visited[maxn];
//map<int, pair<int, int>, greater<int> > holes;
//
//
//void dfs(int node) {
//    assert(node < maxn);
//    visited[node] = true;
//    comp[node] = num_comp;
//    assert(num_comp < maxn);
//    components[num_comp].insert(node);
//    for (int i : adj[node]) {
//        if (!visited[i]) {
//            dfs(i);
//        }
//    }
//}
//
//
//int main() {
//    setIO();
//    cin >> n >> m;
//    for (int i = 0; i < n; ++i) {
//        cin >> cows[i];
//        --cows[i];
//    }
//    bool sorted = true;
//    int pre = cows[0];
//    for (int i = 1; i < n; ++i) {
//        if (cows[i] < pre) {
//            sorted = false;
//            break;
//        }
//        pre = cows[i];
//    }
//    if (sorted) {
//        cout << -1 << "\n";
//        return 0;
//    }
//
//    int a, b, w;
//    set<int> wi;
//    for (int i = 0; i < m; ++i) {
//        cin >> a >> b >> w;
//        --a, --b;
//        holes[w] = pair<int, int> {a, b};
//        wi.insert(w);
//    }
//    vector<int> widths{wi.begin(), wi.end()};
//    sort(widths.begin(), widths.end(), greater<int>());
//    int low = 0, high = (int) widths.size() - 1, mid, sol;
//    while (low <= high) {
//        mid = (low + high) / 2;
//        assert(mid < widths.size());
//        int cur = widths[mid];
//        assert(n <= maxn);
//        for (int i = 0; i < n; ++i) {
//            assert(i < maxn);
//            visited[i] = false;
//            adj[i].clear();
//        }
//        for (auto i : holes) {
//            if (i.first >= cur) {
//                assert(i.second.first < maxn);
//                assert(i.second.second < maxn);
////                cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
//                adj[i.second.first].push_back(i.second.second);
//                adj[i.second.second].push_back(i.second.first);
//            } else {
//                break;
//            }
//        }
//        num_comp = 0;
//        for (int i = 0; i < n; ++i) {
//            if (!visited[i]) {
//                dfs(i);
//                ++num_comp;
//            }
//        }
//        bool pos = true;
//        for (int i = 0; i < n; ++i) {
//            assert(comp[i] < maxn);
//            if (components[comp[i]].find(cows[i]) == components[comp[i]].end()) {
//                pos = false;
//                break;
//            }
//        }
//        if (pos) {
//            high = mid - 1;
//            sol = cur;
//        } else {
//            low = mid + 1;
//        }
//    }
//    cout << sol << "\n";
//    return 0;
//}


// Binary Search Disjoint Set solution

const int maxn = 1e5;
int cows[maxn], parent[maxn], depth[maxn];
map<int, pair<int, int>, greater<int> > holes;

int get(int x) {
    if (parent[x] == x) {
        return x;
    }
    parent[x] = get(parent[x]);
    return parent[x];
}

bool same(int x, int y) {
    return get(x) == get(y);
}

void merge(int x, int y) {
    if (!same(x, y)) {
        int xroot = get(x), yroot = get(y);
        if (depth[xroot] >= depth[yroot]) {
            parent[yroot] = xroot;
            depth[xroot] = max(depth[xroot], depth[yroot] + 1);
        } else {
            parent[xroot] = yroot;
            depth[yroot] = max(depth[yroot], depth[xroot] + 1);
        }
    }
}

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
        --cows[i];
    }
    bool sorted = true;
    int pre = cows[0];
    for (int i = 1; i < n; ++i) {
        if (cows[i] < pre) {
            sorted = false;
            break;
        }
        pre = cows[i];
    }
    if (sorted) {
        cout << -1 << "\n";
        return 0;
    }

    int a, b, w;
    set<int, greater<int>> wi;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        --a, --b;
        holes[w] = pair<int, int>{a, b};
        wi.insert(w);
    }
    vector<int> widths{wi.begin(), wi.end()};
    int low = 0, high = (int) widths.size() - 1, mid, sol;
    while (low <= high) {
        mid = (low + high) / 2;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            depth[i] = 0;
        }
        for (int i = 0; i <= mid; ++i) {
            merge(holes[widths[i]].first, holes[widths[i]].second);
        }
        bool pos = true;
        for (int i = 0; i < n; ++i) {
            if (!same(i, cows[i])) {
                pos = false;
                break;
            }
        }
        if (pos) {
            sol = widths[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << sol << "\n";
    return 0;
}