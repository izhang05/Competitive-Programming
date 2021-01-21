#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> x, y;
        int xp, yp;
        for (int i = 0; i < 4 * n - 1; ++i) {
            cin >> xp >> yp;
            if (x.find(xp) == x.end()) {
                x[xp] = 1;
            } else {
                ++x[xp];
            }
            if (y.find(yp) == y.end()) {
                y[yp] = 1;
            } else {
                ++y[yp];
            }
//            cout << xp << " " << yp << "\n";
        }
        for (auto i : x) {
//            cout << i.first << " " << i.second << "\n";
            if (i.second % 2 == 1) {
                cout << i.first << " ";
                break;
            }
        }
        for (auto i : y) {
//            cout << i.first << " " << i.second << "\n";
            if (i.second % 2 == 1) {
                cout << i.first << "\n";
                break;
            }
        }

    }
    return 0;
}
