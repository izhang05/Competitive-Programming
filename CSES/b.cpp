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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<int> adj[maxn];
int a[maxn], down[maxn], up[maxn];

void dfs1(int c, int p) {
    down[c] = a[c];
    for (auto i : adj[c]) {
        if (i != p) {
            dfs1(i, c);
            if (down[i] > 0) {
                down[c] += down[i];
            }
        }
    }
}

void dfs2(int c, int p) {
    if (c != 0) {
        up[c] = up[p] + down[p];
        if (down[c] > 0) {
            up[c] -= down[c];
        }
        up[c] = max(0, up[c]);
    }
    for (auto i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
        }
    }
}

int main() {
    setIO("b");
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            --a[i];
        }
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
#ifdef DEBUG
    cout << "down:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << down[i] << " ";
    }
    cout << "\n";
    cout << "up:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << up[i] << " ";
    }
    cout << "\n";
#endif
    for (int i = 0; i < n; ++i) {
        cout << down[i] + up[i] << " ";
    }
    cout << "\n";
    return 0;
}
