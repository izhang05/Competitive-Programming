/* Author: izhang05
 * Time: 07-18-2021 21:10:02
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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            if (i % 2 == 0) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << "\n";
        for (int i = 1; i < n - 1; ++i) {
            if (i % 2 == 1) {
                for (int j = 0; j < m; ++j) {
                    cout << 0;
                }
                cout << "\n";
            } else {
                cout << 1;
                for (int j = 1; j < m - 1; ++j) {
                    cout << 0;
                }
                if (m >= 3) {
                    cout << 1 << "\n";
                } else {
                    cout << 0 << "\n";
                }
            }
        }
        if (n % 2 == 1) {
            cout << 1;
        } else {
            cout << 0;
        }
        for (int i = 1; i < m - 2; ++i) {
            if (i % 2 == 0) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        if (n % 2 == 1) {
            if (m % 2 == 0) {
                cout << "10" << "\n";
            } else {
                cout << "01" << "\n";
            }
        } else {
            cout << "00"
                 << "\n";
        }
        cout << "\n";
    }
    return 0;
}
