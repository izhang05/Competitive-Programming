/* Author: izhang05
 * Time: 07-27-2021 22:26:33
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

    int k;
    cin >> k;
    vector<int> pre(1 << k, 1);
    for (int j = 0; j < (1 << k); ++j) {
        cout << '+';
    }
    cout << "\n";
    for (int i = 1; i < (1 << k); ++i) {
        vector<int> cur(1 << k);
        cur[0] =
        for (int j = 0; j < (1 << k); ++j) {

        }
        for (auto &j : cur) {
            if (j) {
                cout << '+';
            } else {
                cout << '-';
            }
        }
        cout << "\n";
    }
    return 0;
}
