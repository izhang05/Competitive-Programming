/* Author: izhang05
 * Time: 07-12-2021 15:06:54
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (m--) {
        int t, v;
        cin >> t >> v;
        --v;
        if (t == 0) {
            int b;
            cin >> b;
            a[v] = b;
        } else {
            int sol = 0, cur = v;
            while (true) {
                sol += 1;
                int next = cur + a[cur];
                if (next >= n) {
                    break;
                }
                cur = next;
            }
            cout << cur + 1 << " " << sol << "\n";
        }
    }
    return 0;
}
