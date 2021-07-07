/* Author: izhang05
 * Time: 07-07-2021 10:35:04
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> pos;
    for (int i = 0; i < n; ++i) {
        pos.insert(i);
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int guess = cur ^ *pos.begin();
        pos.erase(pos.begin());
        cout << guess << endl;
        cur ^= guess;
        int res;
        cin >> res;
        if (res == 1) {
            return;
        }
    }
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
