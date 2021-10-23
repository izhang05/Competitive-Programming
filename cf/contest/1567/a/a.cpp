/* Author: izhang05
 * Time: 09-29-2021 14:00:51
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool left = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') {
            cout << 'D';
        } else if (s[i] == 'D') {
            cout << 'U';
        } else {
            if (left) {
                cout << 'L';
                left = false;
            } else {
                cout << 'R';
                left = true;
            }
        }
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
