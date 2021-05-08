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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;

pair<long long, long long> down[maxn], up[maxn];
int a[maxn];
vector<int> adj[maxn];

void dfs1(int c, int p) {
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c);
            down[c].first += down[i].first + down[i].second;
            down[c].second += down[i].second;
        }
    }
    down[c].second += a[c];
}

void dfs2(int c, int p) {
    if (p != -1) {
        up[c].first += up[p].first + down[p].first - down[c].first - down[c].second;
        up[c].first += up[p].second + down[p].second - down[c].second;
        up[c].second += up[p].second + down[p].second - down[c].second;
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
        }
    }

}

int main() {
    setIO("1");

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
#ifdef DEBUG
        cout << i << " " << down[i].first + up[i].first << " " << down[i].first << " " <<  up[i].first << "\n";
#endif
        sol = max(sol, down[i].first + up[i].first);
    }

    cout << sol << "\n";
    return 0;
}
