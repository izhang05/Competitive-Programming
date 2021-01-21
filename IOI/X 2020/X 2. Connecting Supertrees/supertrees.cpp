#include "supertrees.h"
#include <bits/stdc++.h>


using namespace std;
const int maxn = 1e3 + 5;
int parent[maxn], parent2[maxn];
vector<int> comp[maxn], comp2[maxn];

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (comp[xroot].size() < comp[yroot].size()) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        parent[xroot] = yroot;
        comp[yroot].insert(comp[yroot].end(), comp[xroot].begin(), comp[xroot].end());
        comp[xroot].clear();
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

int get2(int x) {
    return parent2[x] == x ? x : parent2[x] = get2(parent2[x]);
}

bool merge2(int x, int y) {
    int xroot = get2(x), yroot = get2(y);
    if (comp2[xroot].size() < comp2[yroot].size()) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        parent2[xroot] = yroot;
        comp2[yroot].insert(comp2[yroot].end(), comp2[xroot].begin(), comp2[xroot].end());
        comp2[xroot].clear();
        return true;
    }
    return false;
}

bool same2(int x, int y) {
    return get2(x) == get2(y);
}

int construct(vector<vector<int>> p) {
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        parent2[i] = i;
        comp[i].push_back(i);
        comp2[i].push_back(i);
        if (p[i][i] != 1) {
            return 0;
        }
    }
    vector<vector<int>> sol(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (p[i][j] == 1) {
                merge(i, j);
            } else if (p[i][j] == 2) {
                merge2(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!p[i][j] && (same(i, j) || same2(i, j))) {
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (comp[i].size() > 1) {
            for (int j = 0; j < (int) comp[i].size() - 1; ++j) {
                sol[comp[i][j]][comp[i][j + 1]] = 1;
                sol[comp[i][j + 1]][comp[i][j]] = 1;
            }
        }
        if (comp2[i].size() > 1) {
            for (int j = 0; j < (int) comp2[i].size() - 1; ++j) {
                sol[comp2[i][j]][comp2[i][j + 1]] = 1;
                sol[comp2[i][j + 1]][comp2[i][j]] = 1;
            }
            if (comp2[i].size() == 2) {
                return 0;
            }
            sol[comp2[i][0]][comp2[i][comp2[i].size() - 1]] = 1;
            sol[comp2[i][comp2[i].size() - 1]][comp2[i][0]] = 1;
        }
    }
    build(sol);
    return 1;
}

#ifdef DEBUG
int main() {
    freopen("1.in", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    cout << construct(a) << "\n";
}
#endif
