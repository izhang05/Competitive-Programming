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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<int> adj[maxn];
int p[maxn], h[maxn], total[maxn], u[maxn];
bool sol = true;

void dfs(int c, int par) {
    total[c] = p[c];
    for (auto i : adj[c]) {
        if (i != par) {
            dfs(i, c);
            total[c] += total[i];
            if (!sol) {
                return;
            }
        }
    }
    if (total[c] % 2 != abs(h[c]) % 2 || abs(h[c]) > total[c]) {
        sol = false;
#ifdef DEBUG
        cout << "bad: " << c << "\n";
#endif
        return;
    }
    u[c] = (total[c] - h[c]) / 2;
}

void dfs1(int c, int par) {
    int sum = 0;
    for (auto i : adj[c]) {
        if (i != par) {
            dfs(i, c);
            if (!sol) {
                return;
            }
            sum += u[i];
        }
    }
    if (sum < u[c] - p[c]) {
#ifdef DEBUG
        cout << "bad: " << c << "\n";
        cout << sum << " " << u[c] - p[c] << "\n";
#endif
        sol = false;
        return;
    }
}

int main() {
    setIO("b");
    int t;
    cin >> t;
    while (t--) {
        sol = true;
        memset(p, 0, sizeof(p));
        memset(h, 0, sizeof(h));
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            cin >> p[i];
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
        dfs(0, -1);
#ifdef DEBUG
        cout << "total:"
             << "\n";
        for (int i = 0; i < n; ++i) {
            cout << total[i] << " ";
        }
        cout << "\n";
#endif
        dfs1(0, -1);
        cout << (sol ? "YES" : "NO") << "\n";
    }
    return 0;
}
