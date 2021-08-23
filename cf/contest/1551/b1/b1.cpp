/* Author: izhang05
 * Time: 08-20-2021 22:26:45
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
    string s;
    cin >> s;
    map<char, int> cnt;
    int single = 0;
    for (auto &i : s) {
        ++cnt[i];
    }
    int sol = 0;
    for (auto &i : cnt) {
        if (i.second >= 2) {
            ++sol;
        } else {
            ++single;
        }
    }
    cout << sol + single / 2 << "\n";
}

void a() {
    cout << "a\n";
}
void b() {
    cout << "b\n";
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
