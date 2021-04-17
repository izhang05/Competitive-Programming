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

int main() {
    setIO("1");

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a>>b;
        --a,--b;
        adj[a].push_back(b);
    }

    return 0;
}
