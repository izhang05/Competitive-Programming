/* Author: izhang05
 * Time: 07-09-2021 18:51:53
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<int> adj[maxn];
int par[maxn];

void dfs(int c, int p) {
    par[c] = p;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
        }
    }
}

int main() {
    setIO("1");
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    dfs(0, -1);
    while (q--) {
        int t, v;
        cin >> t >> v;
        --v;
        if (t == 1) {
            bool found = false;
            int orig = v;
            while (v != 0) {
                v = par[v];
                if (gcd(a[v], a[orig]) != 1) {
                    found = true;
                    cout << v + 1 << "\n";
                    break;
                }
            }
            if (!found) {
                cout << -1 << "\n";
            }
        } else {
            int w;
            cin >> w;
            a[v] = w;
        }
    }
    return 0;
}
