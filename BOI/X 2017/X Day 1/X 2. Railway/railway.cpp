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
vector<int> adj[maxn];


int main() {
    setIO("1");

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a,b;
        cin >> a>>b;
        --a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return 0;
}
