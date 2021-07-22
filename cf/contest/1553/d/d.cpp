/* Author: izhang05
 * Time: 07-22-2021 10:35:05
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
    string s, t;
    cin >> s >> t;
    int n = int(s.size()), m = int(t.size());
    if (m > n) {
        cout << "NO"
             << "\n";
        return;
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int pre = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[0] && i % 2 == 0) {
            pre = i;
            break;
        }
    }
    if (pre == -1) {
        cout << "NO"
             << "\n";
        return;
    }
    int j = pre + 1;
    for (int i = 1; i < m; ++i) {
        while (j < n && ((s[j] != t[i]) || (j % 2 == pre % 2))) {
            ++j;
        }
        if (j == n) {
            cout << "NO"
                 << "\n";
            return;
        }
        pre = j;
        ++j;
    }
    cout << "YES" << "\n";
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
