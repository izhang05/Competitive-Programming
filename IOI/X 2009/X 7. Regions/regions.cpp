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

int region[maxn];
vector<int> adj[maxn];

int main() {
    setIO("regions");
    int n, r, q;
    cin >> n >> r >> q;
    cin >> region[1];
    for (int i = 2; i < n; ++i) {
        int a;
        cin >> a >> region[i];
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

    }
    return 0;
}
