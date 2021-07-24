/* Author: izhang05
 * Time: 07-22-2021 10:35:05
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 1;

int parent[maxn], depth[maxn];

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (depth[xroot] > depth[yroot]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        parent[xroot] = yroot;
        depth[yroot] = max(depth[yroot], depth[xroot] + 1);
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

set<int> prime(int x) {
    set<int> res;
    while (x % 2 == 0) {
        res.insert(2);
        x /= 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            res.insert(i);
            x /= i;
        }
    }
    if (x > 1) {
        res.insert(x);
    }
    return res;
}

set<int> adj[maxn];
int main() {
    setIO("1");
    for (int i = 0; i < maxn; ++i) {
        parent[i] = i;
        depth[i] = 0;
    }
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        set<int> cur = prime(a[i]);
        for (auto &j : cur) {
            merge(j, a[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        set<int> cur = prime(a[i] + 1);
        vector<int> v(cur.begin(), cur.end());
        v.push_back(a[i]);
        for (int j = 0; j < int(v.size()); ++j) {
            adj[get(v[j])].insert(get(a[i] + 1));
            adj[get(a[i] + 1)].insert(get(v[j]));
            for (int k = j + 1; k < int(v.size()); ++k) {
                adj[get(v[j])].insert(get(v[k]));
                adj[get(v[k])].insert(get(v[j]));
            }
        }
    }
    while (q--) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        if (same(a[b], a[c])) {
            cout << 0 << "\n";
        } else if (adj[get(a[b])].find(get(a[c])) != adj[get(a[b])].end()) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
    return 0;
}
