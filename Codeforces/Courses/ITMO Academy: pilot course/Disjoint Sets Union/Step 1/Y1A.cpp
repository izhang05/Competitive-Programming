#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int parent[maxn];

int find(int n) {
    return parent[n] == n ? n : parent[n] = find(parent[n]);
}

string sol(int x, int y) {
    if (find(x) == find(y)) {
        return "YES";
    } else {
        return "NO";
    }
}

void merge(int x, int y) {
    int xr = find(x), yr = find(y);
    if (xr != yr) {
        parent[xr] = yr;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    string a;
    int b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --b, --c;
        if (a == "union") {
            merge(b, c);
        } else {
            cout << sol(b, c) << "\n";
        }
    }
    return 0;
}
