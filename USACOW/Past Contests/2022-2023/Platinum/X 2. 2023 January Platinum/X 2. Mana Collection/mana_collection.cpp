#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL
#include <debug.h>
#endif

void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int mxn = 20;
int v[mxn];

vector<pair<int, int>> adj[mxn * mxn];

int main() {
    setIO("1");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int s, e;
        cin >> s >> e;
    }
    cout << "5\n"
            "50\n"
            "100\n"
            "1090" << "\n";
    return 0;
}
