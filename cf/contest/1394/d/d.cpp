/* Author: izhang05
 * Time: 06-28-2021 21:14:05
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
int n, in[maxn], out[maxn], deg[maxn];
long long down[maxn], up[maxn], t[maxn], h[maxn];
bool vis[maxn];
vector<int> o_adj[maxn], adj[maxn];

void dfs1(int c, int p) {
    for (auto &i : o_adj[c]) {
        if (i != p) {
            if (h[c] < h[i]) {
                ++out[c], ++in[i];
            } else if (h[i] < h[c]) {
                ++out[i], ++in[c];
            } else {
                adj[c].push_back(i), adj[i].push_back(c);
            }
            dfs1(i, c);
        }
    }
}

void dfs2(int c, int p) {
    vis[c] = true;
    vector<long long> children;
    long long tot_up = 0;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
            children.push_back(down[i] - up[i]);
            tot_up += up[i];
        }
    }
    sort(children.begin(), children.end());
    reverse(children.begin(), children.end());
    int num_c = int(children.size());
    long long pre = 0;
    for (int i = 0; i <= num_c; ++i) {
        if (i) {
            pre += children[i - 1];
        }
        long long cur = pre + tot_up;
        if (p != -1) {
            down[c] = max(down[c], cur + min(in[c] + 1 + num_c - i, out[c] + i) * t[c]);
            up[c] = max(up[c], cur + min(in[c] + num_c - i, out[c] + i + 1) * t[c]);
        } else {
            down[c] = max(down[c], cur + min(in[c] + num_c - i, out[c] + i) * t[c]);
        }
    }
}

int main() {
    setIO("1");
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ++deg[a], ++deg[b];
        o_adj[a].push_back(b);
        o_adj[b].push_back(a);
    }
    dfs1(0, -1);
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += deg[i] * t[i];
        if (!vis[i]) {
            dfs2(i, -1);
            sol -= down[i];
        } else if (adj[i].empty()) {
            sol -= (min(in[i], out[i])) * t[i];
        }
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        cout << i << " " << down[i] << " " << up[i] << "\n";
    }
#endif
    cout << sol << "\n";
    return 0;
}
