/* Author: izhang05
 * Time: 09-29-2021 14:04:27
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

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
void solve() {
    string n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < int(n.size()); ++i) {
        if (i % 2 == 0) {
            a *= 10;
            a += n[i] - '0';
        } else {
            b *= 10;
            b += n[i] - '0';
        }
    }
    cout << ((a + 1) * (b + 1)) - 2 << "\n";
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
