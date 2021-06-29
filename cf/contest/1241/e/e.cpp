/* Author: izhang05
 * Time: 06-29-2021 13:50:40
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5 + 5;
vector<pair<int, int>> adj[maxn];

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n - 1; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            --a, --b;
            adj[a].emplace_back(b, c);
            adj[b].emplace_back(a, c);
        }

    }
    return 0;
}
