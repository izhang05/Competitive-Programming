#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5;
int parent[maxn], comp[maxn], s[maxn], mn[maxn], mx[maxn];

int find(int n) {
    return parent[n] == n ? n : parent[n] = find(parent[n]);
}

void merge(int x, int y) {
    if (s[find(x)] > s[find(y)]) {
        swap(x, y);
    }
    int xr = find(x), yr = find(y);
    if (xr != yr) {
        mn[yr] = min(mn[yr], mn[xr]);
        mx[yr] = max(mx[yr], mx[xr]);
        comp[xr] = comp[yr];
        parent[xr] = yr;
        s[yr] += s[xr];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        comp[i] = i;
        s[i] = 1;
        mn[i] = i;
        mx[i] = i;
    }
    string a;
    int b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a;
        if (a == "union") {
            cin >> b >> c;
            --b, --c;
            merge(b, c);
        } else {
            cin >> b;
            --b;
            int cur = find(b);
            cout << mn[cur] + 1 << " " << mx[cur] + 1 << " " << s[cur] << "\n";
        }
    }
    return 0;
}