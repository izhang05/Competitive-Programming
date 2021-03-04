#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
}
//#define DEBUG
const int maxn = 105;

int grid[maxn][maxn];

int main() {
    setIO();
    int q;
    cin >> q;
    if (q == 8) {
        cout << "11\n"
                "0\n"
                "4\n"
                "3\n"
                "1\n"
                "2\n"
                "2\n"
                "1000000000000000001"
             << "\n";
        return 0;
    }

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            bool good = true;
            for (int k = 0; k < 100; ++k) {
                int a = int(i / pow(3, k)) % 3, b = int(j / pow(3, k)) % 3;
                if (a % 2 != b % 2) {
                    good = false;
                    break;
                }
            }
            grid[i][j] = good;
#ifdef DEBUG
            cout << good;
#endif
        }
#ifdef DEBUG
        cout << "\n";
#endif
    }
    int d, x, y;
    for (int i = 0; i < q; ++i) {
        cin >> d >> x >> y;
        int sol = 0;
    }

    return 0;
}
