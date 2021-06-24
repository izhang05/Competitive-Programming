/* Author: izhang05
 * Time: 06-23-2021 17:24:04
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

    int a, b, c;
    cin >> a >> b >> c;
    cout << 7 * (min({a, b / 2, c / 4})) << "\n";
    return 0;
}
