#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 205;
vector<int> adj[maxn];
int sol;

void dfs(int c, int p, int d) {
    sol = max(sol, d);
    for (auto i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    map<string, int> m;
    int ind = 0;
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b >> b;
        for (auto &j : a) {
            j = tolower(j);
        }
        for (auto &j : b) {
            j = tolower(j);
        }
        if (m.find(b) == m.end()) {
            m[b] = ind++;
        }
        if (m.find(a) == m.end()) {
            m[a] = ind++;
        }
        adj[m[b]].push_back(m[a]);
    }
    dfs(0, -1, 1);
    cout << sol << "\n";
    return 0;
}
