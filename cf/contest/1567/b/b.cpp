/* Author: izhang05
 * Time: 09-29-2021 14:04:27
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long pre[maxn];

void solve() {
    int a, b;
    cin >> a >> b;
    if (pre[a - 1] == b) {
        cout << a << "\n";
    } else if ((pre[a - 1] ^ b) != a) {
        cout << a + 1 << "\n";
    } else {
        cout << a + 2 << "\n";
    }
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    for (int i = 1; i < maxn; ++i) {
        pre[i] = pre[i - 1] ^ i;
    }
    while (t--) {
        solve();
    }
    return 0;
}
