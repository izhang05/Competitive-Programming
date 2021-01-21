#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //    freopen("solution.out", "w", stdout);
        freopen("1.in", "r", stdin);
#endif
    int t, n;
    cin >> t;
    bool hor, vert;
    while (t--) {
        hor = true, vert = true;
        cin >> n;
        vector<string> matrix(n);
        for (int i = 0; i < n; ++i) {
            cin >> matrix[i];
        }
        for (int i = 0; i < n / 2; ++i) {
            if (matrix[i] != matrix[n - i - 1]) {
                hor = false;
                break;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                if (matrix[i][j] != matrix[i][n - j - 1]) {
                    vert = false;
                    break;
                }
            }
            if (!vert) {
                break;
            }
        }

        if (hor && vert) {
            cout << "BOTH" << "\n";
        } else if (hor) {
            cout << "HORIZONTAL" << "\n";
        } else if (vert) {
            cout << "VERTICAL" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}