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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
int p[maxn], h[maxn], tot[maxn], happy[maxn];
vector<int> adj[maxn];
bool pos;

void dfs(int c, int par) {
    tot[c] = p[c];
    int sum_happy = 0;
    for (auto &i : adj[c]) {
        if (i != par) {
            dfs(i, c);
            tot[c] += tot[i];
            if (!pos) {
                return;
            }
            sum_happy += happy[i];
        }
    }
    if (abs(tot[c] % 2) != abs(h[c] % 2) || h[c] > tot[c]) {
        pos = false;
        return;
    }
    happy[c] = (tot[c] + h[c]) / 2;
    if (sum_happy > happy[c]) {
        pos = false;
    }
}

int main() {
    setIO("b");

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            adj[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        pos = true;
        dfs(0, -1);
        if (!pos) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
