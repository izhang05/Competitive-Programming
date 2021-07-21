/* Author: izhang05
 * Time: 07-20-2021 17:42:21
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

    int n, k;
    cin >> n >> k;
    if (n % 2 == 0 || k > max(0, (n - 3) / 2)) {
        cout << "NO\n";
        return 0;
    }
    return 0;
}
