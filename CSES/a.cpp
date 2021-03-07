#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105;

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int a;
                cin >> a;
                if ((i + j) % 2 == a % 2) {
                    cout << a << " ";
                } else {
                    cout << a + 1 << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
