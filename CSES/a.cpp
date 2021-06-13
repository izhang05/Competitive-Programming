#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int mod = 1e9 + 7, maxn = 2e5 + 5;
const long long inf = 1e18;
long long a[maxn], b[maxn], c[maxn], bt[maxn], ct[maxn], min_anc[maxn], w0[maxn], w1[maxn], sub0[maxn], sub1[maxn];
vector<int> adj[maxn];

void dfs(int cur, int p) {
    min_anc[cur] = a[cur];
    if (p != -1) {
        min_anc[cur] = min(min_anc[cur], min_anc[p]);
    }
    bt[cur] = b[cur], ct[cur] = c[cur];
    if (b[cur] == 1 && c[cur] == 0) {
        w0[cur] = 1;
    } else if (b[cur] == 0 && c[cur] == 1) {
        w1[cur] = 1;
    }
    for (auto &i : adj[cur]) {
        if (i != p) {
            dfs(i, cur);
            bt[cur] += bt[i];
            ct[cur] += ct[i];
            w0[cur] += w0[i];
            w1[cur] += w1[i];
        }
    }
}
long long sol = 0;
void dfs2(int cur, int p) {
    for (auto &i : adj[cur]) {
        if (i != p) {
            dfs2(i, cur);
            w0[cur] -= sub0[i];
            w1[cur] -= sub1[i];
            sub0[cur] += sub0[i];
            sub1[cur] += sub1[i];
        }
    }
    if (min_anc[cur] == a[cur]) {
        long long swap = min(w0[cur], w1[cur]);
        sol += 2 * a[cur] * swap;
        if (p != -1) {
            sub0[cur] += swap;
            sub1[cur] += swap;
        }
    }
}

int main() {
    setIO("1");
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        min_anc[i] = inf;
    }
    for (int i = 0; i < n - 1; ++i) {
        int d, e;
        cin >> d >> e;
        --d, --e;
        adj[d].push_back(e);
        adj[e].push_back(d);
    }
    dfs(0, -1);
    if (bt[0] != ct[0]) {
        cout << -1 << "\n";
        return 0;
    }
    dfs2(0, -1);
    cout << sol << "\n";
    return 0;
}
