/* Author: izhang05
 * Time: 06-29-2021 14:33:25
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
const int maxn = 2e5 + 5;
bool marked[8 * maxn];
long long t[8 * maxn];

void push(int v) {
    if (marked[v]) {
        t[v * 2] = t[v * 2 + 1] = t[v];
        marked[v * 2] = marked[v * 2 + 1] = true;
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), new_val);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return get(v * 2, tl, tm, pos);
    else
        return get(v * 2 + 1, tm + 1, tr, pos);
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
vector<int> adj[maxn];
int tin[maxn], tout[maxn], ti = 0;

void dfs(int c, int p) {
    tin[c] = ti++;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
        }
    }
    tout[c] = ti - 1;
}

int main() {
    setIO("1");
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        update(0, 0, 2 * n, tin[i], tout[i] + 1, s);
    }
    return 0;
}


