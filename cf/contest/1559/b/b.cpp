/* Author: izhang05
 * Time: 08-15-2021 10:35:03
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
    string tmp;
    cin >> tmp;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        if (tmp[i] == 'B') {
            s[i] = 0;
        } else if (tmp[i] == 'R') {
            s[i] = 1;
        } else {
            s[i] = 2;
        }
    }
    int cur = 0;
    vector<char> ch{'B', 'R'};
    for (int i = 0; i < n; ++i) {
        if (s[i] != 2) {
            if (i % 2 == 0) {
                cur = s[i];
            } else {
                cur = s[i] ^ 1;
            }
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] != 2) {
            cur = s[i];
        }
        cout << ch[cur];
        cur ^= 1;
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
