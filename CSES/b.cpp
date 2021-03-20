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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
vector<int> adj[maxn];
long long color[maxn], sol = 0, tred, tblue, red[maxn], blue[maxn];

void dfs(int c, int p) {
    if (color[c] == 1) {
        red[c] = 1;
    } else if (color[c] == 2) {
        blue[c] = 1;
    }
    for (auto i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            red[c] += red[i];
            blue[c] += blue[i];
        }
    }
    if ((red[c] == 0 || red[c] == tred) && (blue[c] == 0 || blue[c] == tblue)) {
        if (!((red[c] == 0 && blue[c] == 0) || (red[c] == tred && blue[c] == tblue))) {
#ifdef DEBUG
            cout << c << "\n";
#endif
            ++sol;
        }
    }
}

int main() {
    setIO("b");

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> color[i];
        if (color[i] == 1) {
            ++tred;
        } else if (color[i] == 2) {
            ++tblue;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << sol << "\n";
    return 0;
}
