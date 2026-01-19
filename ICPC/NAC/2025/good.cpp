#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    int c = a + b;
    if(c >= MOD) c -= MOD;
    return c;
}

int mult(int a, int b) {
    return (1ll * a * b) % MOD;
}

int binpow(int a, int b) {
    int c = 1;
    for(; b > 0; b /= 2, a = mult(a, a)) if(b & 1) c = mult(c, a);
    return c;
}

int divide(int a, int b) {
    return mult(a, binpow(b, MOD - 2));
}

int n;

vector<vector<pair<int, int>>> tree;

vector<pair<int, int>> edges;

vector<bool> vis;

bool validflag;

void dfs(int v, int p) {
    vis[v] = true;

    for(auto [e, i] : tree[v]) {
        if(i == p) continue;

        if(!vis[e]) dfs(e, i);
        else {
            validflag = false;
            return;
        }
    }
}

bool isvalid(){
    vis.assign(n + 1, false);

    int cnt = 0;
    validflag = true;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i, -1);
        }
    }

    return validflag && cnt == 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n;

    tree.assign(n + 1, {});

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        tree[a].push_back({b, -1});
        tree[b].push_back({a, -1});

        edges.push_back({a, b});
    }

    for(int i = 1; i <= n; i++) {
        if(tree[i].size() == 1 && i != 1) {
            edges.push_back({1, i});
        }
    }

    int ans = 0;

    for(int m = 0; m < (1 << edges.size()); m++) {
        if(__builtin_popcount(m) != n - 1) continue;

        tree.assign(n + 1, {});

        for(int i = 0; i < edges.size(); i++) {
            if((m >> i) & 1) {
                tree[edges[i].first].push_back({edges[i].second, i});
                tree[edges[i].second].push_back({edges[i].first, i});
            }
        }

        if(isvalid()) ans++;
    }

    cout << ans;
}