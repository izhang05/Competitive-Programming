/* Author: izhang05
 * Time: 07-09-2021 18:36:21
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;

vector<int> factor(int x) {
    vector<int> res;
    if (x % 2 == 0) {
        res.push_back(2);
        while (x % 2 == 0) {
            x /= 2;
        }
    }
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            res.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        res.push_back(x);
    }
    return res;
}

int a[maxn];
pair<int, int> sol[maxn];
vector<int> f[maxn], adj[maxn];
map<int, pair<int, int>> cur;

void dfs(int c, int p, int d) {
    map<int, pair<int, int>> pre;
    for (auto &i : f[c]) {
        if (cur.find(i) != cur.end()) {
#ifdef DEBUG
            cout << c << " " << i << " " << cur[i] << "\n";
#endif
            sol[c] = max(sol[c], cur[i]);
        }
        pre[i] = cur[i];
        cur[i] = {d, c + 1};
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
    for (auto &i : pre) {
        if (i.second != make_pair(0, 0)) {
            cur[i.first] = i.second;
        } else {
            cur.erase(i.first);
        }
    }
}

int main() {
    setIO("2");

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        f[i] = factor(a[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    for (int i = 0; i < n; ++i) {
        sol[i] = {-1, -1};
    }
    dfs(0, -1, 1);
    while (q--) {
        int t, v;
        cin >> t >> v;
        --v;
        if (t == 1) {
            cout << sol[v].second << "\n";
        } else {
            int w;
            cin >> w;
            a[v] = w;
            f[v] = factor(w);
            for (int i = 0; i < n; ++i) {
                sol[i] = {-1, -1};
            }
            dfs(0, -1, 1);
        }
    }
    return 0;
}
