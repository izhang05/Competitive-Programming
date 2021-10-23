/* Author: izhang05
 * Time: 08-25-2021 23:26:23
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
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, d;
    cin >> n >> d;
    int sol = 0, cur = 0;
    for (int i = 0; i < d; ++i) {
        string s;
        cin >> s;
        bool good = false;
        for (auto &j : s) {
            if (j == '0') {
                good = true;
                break;
            }
        }
        if (good) {
            ++cur;
        } else {
            cur = 0;
        }
        sol = max(sol, cur);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
