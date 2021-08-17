/* Author: izhang05
 * Time: 08-16-2021 23:21:18
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

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}
void solve() {
    string s;
    cin >> s;
    int n = int(s.size());
    vector<int> z = z_function(s);
    int max_z = 0;
    for (int i = 1; i < n; ++i) {
        if (z[i] == n - i && max_z >= z[i]) {
            cout << s.substr(0, n - i) << "\n";
            return;
        }
        max_z = max(max_z, z[i]);
    }
    cout << "Just a legend\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
