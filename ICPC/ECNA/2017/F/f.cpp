#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e4 + 5;
vector<int> adj[mxn];
long long sz[mxn], depth[mxn];
bool path[mxn], endp[mxn];
int par[mxn];

long long dfs(int c, int p, int d = 0) {
    par[c] = p;
    sz[c] = 1;
    depth[c] = d;
    for (auto i: adj[c]) {
        if (i != p) {
            sz[c] += dfs(i, c, d + 1);
        }
    }
    return sz[c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ++n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    pair<long long, long long> sol;
    for (int i = 0; i < n; ++i) {
        vector<long long> s;
        long long cur = 0;
        for (auto &j: adj[i]) {
            if (j != par[i]) {
                cur += sz[j] * (n - sz[j] - 1);
                s.push_back(sz[j]);
            }
        }
        cur += (n - sz[i]) * (sz[i] - 1);
        s.push_back(n - sz[i]);
        cur /= 2;
        long long cur2 = cur;
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        if (s.size() >= 2) {
            cur2 -= s[0] * s[1];
        }
        sol = max(sol, {cur, cur2});
    }
    cout << sol.first << " " << sol.second << "\n";
}