/* Author: izhang05
 * Time: 08-17-2021 16:33:47
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
vector<int> z_func(string s) {
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
    z[0] = n;
    return z;
}

void solve() {
    string s;
    cin >> s;
    int n = int(s.size());
    vector<pair<int, int>> sol;
    vector<int> z = z_func(s);
    vector<int> sorted_z(z.begin(), z.end());
    sort(sorted_z.begin(), sorted_z.end());
    for (int i = 0; i < n; ++i) {
        if (z[n - i - 1] == i + 1) {
            sol.emplace_back(i + 1, sorted_z.end() - lower_bound(sorted_z.begin(), sorted_z.end(), i + 1));
        }
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i.first << " " << i.second << "\n";
    }
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
