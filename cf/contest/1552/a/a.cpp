/* Author: izhang05
 * Time: 07-25-2021 10:36:09
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
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string n_s(s.begin(), s.end());
    sort(n_s.begin(), n_s.end());
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        if (n_s[i] != s[i]) {
            ++sol;
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
