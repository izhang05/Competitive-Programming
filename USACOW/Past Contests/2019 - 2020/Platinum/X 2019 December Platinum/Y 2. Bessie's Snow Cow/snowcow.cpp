/*
ID: izhang01
TASK: snowcow
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("snowcow.in", "r", stdin);
    freopen("snowcow.out", "w", stdout);
    freopen("snowcow.out", "w", stderr);
}
//#define DEBUG
const int maxn = 1e5 + 5, inf = 1e9 + 5;
vector<int> adj[maxn];
int t = 1, st[maxn], en[maxn], sub[maxn], n;
long long bit[4 * maxn][2];
set<pair<int, int>> co[maxn];

void dfs(int c, int p) {
    st[c] = t++;
    sub[c] = 1;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            sub[c] += sub[i];
        }
    }
    en[c] = t - 1;
}

void update(int p, int v, int ind) {
    for (; p <= n; p += p & (-p)) {
        bit[p][ind] += v;
    }
}
long long sum(int p, int ind) {
    long long res = 0;
    for (; p > 0; p -= p & (-p)) {
        res += bit[p][ind];
    }
    return res;
}

long long query(int l, int r, int ind) {
    return sum(r, ind) - sum(l - 1, ind);
}

void upd(int x, int v) {
    update(st[x], v, 0);
    update(en[x] + 1, -v, 0);
    update(st[x], v * sub[x], 1);
}

signed main() {
    setIO();
    int q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
#ifdef DEBUG
    cout << "sub:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << sub[i] << " ";
    }
    cout << "\n";
    cout << "st:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << st[i] << " ";
    }
    cout << "\n";
    cout << "en:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << en[i] << " ";
    }
    cout << "\n";
#endif
    for (int i = 0; i < q; ++i) {
        int type, x;
        cin >> type >> x;
        --x;
        if (type == 1) {
            int c;
            cin >> c;
            auto it = co[c].lower_bound({st[x], inf});
            if (it != co[c].begin() && en[prev(it)->second] >= en[x]) {
                continue;
            }
            while (it != co[c].end() && en[it->second] <= en[x]) {
#ifdef DEBUG
                cout << "erase: " << it->first << " " << it->second << "\n";
#endif
                upd(it->second, -1);
                it = co[c].erase(it);
            }
            co[c].insert({st[x], x});
            upd(x, 1);
        } else {
            long long res = sum(st[x], 0) * sub[x];
            res += query(st[x] + 1, en[x], 1);
            cout << res << "\n";
        }
    }
    return 0;
}
