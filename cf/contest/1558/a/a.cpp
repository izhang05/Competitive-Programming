/* Author: izhang05
 * Time: 08-24-2021 14:05:02
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
    int a, b;
    cin >> a >> b;
    set<int> sol;
    for (int i = 0; i < 2; ++i) {
        int serve = (a + b + 1) / 2, other = a + b - serve;
        for (int j = 0; j <= min(a, serve); ++j) {
            if (b >= serve - j && a - j <= other) {
                sol.insert(serve - j + a - j);
            }
        }
        swap(a, b);
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
