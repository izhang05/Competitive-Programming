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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2505;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[maxn];
long long dist[maxn], dp[maxn];
bool vis[maxn];
vector<int> seen;

void dfs(int c) {
    vis[c] = true;
    seen.push_back(c);
    for (auto &i : adj[c]) {
        if (dist[i.first] > dist[c] + i.second) {
            dist[i.first] = dist[c] + i.second;
            if (vis[i.first]) {
                cout << "YES"
                     << "\n";
                vector<int> sol{i.first};
                while (seen.back() != i.first) {
                    sol.push_back(seen.back());
                    seen.pop_back();
                }
                sol.push_back(i.first);
                reverse(sol.begin(), sol.end());
                for (auto &j : sol) {
                    cout << j + 1 << " ";
                }
                cout << "\n";
                exit(0);
            }
            dfs(i.first);
        }
    }
    vis[c] = false;
    seen.pop_back();
}

int main() {
    setIO("12");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto &k : adj[j]) {
                dp[k.first] = min(dp[k.first], dp[j] + k.second);
            }
        }
    }
    bool loop = false;
    for (int i = 0; i < n; ++i) {
        for (auto &j : adj[i]) {
            if (dp[j.first] > dp[i] + j.second) {
                loop = true;
                break;
            }
        }
    }
    if (!loop) {
        cout << "NO"
             << "\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        memset(dist, 0x3f, sizeof(dist));
        memset(vis, false, sizeof(vis));
        dist[i] = 0;
        dfs(i);
    }
    assert(false);
    return 0;
}
