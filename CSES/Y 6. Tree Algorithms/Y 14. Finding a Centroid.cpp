#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("14.in", "r", stdin);
    freopen("14.out", "w", stdout);
    freopen("14.out", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<int> adj[maxn];
int sub[maxn], n;

void dfs(int c, int p) {
    sub[c] = 1;
    for (auto i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            sub[c] += sub[i];
        }
    }
}

int centroid(int c, int p) {
#ifdef DEBUG
    cout << c << endl;
#endif
    for (auto i : adj[c]) {
        if (i != p && sub[i] > n / 2) {
            return centroid(i, c);
        }
    }
    return c;
}

int main() {
    setIO();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        cout << sub[i] << " ";
    }
    cout << "\n";
#endif
    cout << centroid(0, -1) + 1 << "\n";
    return 0;
}
