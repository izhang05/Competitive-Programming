/* Author: izhang05
 * Time: 06-27-2021 21:32:06
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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sol = 0;
        for (int i = 0; i < 9; ++i) {
            vector<int> a, b;
            for (int j = 1; j <= n; ++j) {
                if (j & (1 << i)) {
                    a.push_back(j);
                } else {
                    b.push_back(j);
                }
            }
            if (a.empty() || b.empty()) {
                continue;
            }
            cout << a.size() << " " << b.size();
            for (auto &j : a) {
                cout << " " << j;
            }
            for (auto &j : b) {
                cout << " " << j;
            }
            cout << endl;
            int cur;
            cin >> cur;
            sol = max(sol, cur);
        }
        cout << -1 << " " << sol << endl;
    }
    return 0;
}
