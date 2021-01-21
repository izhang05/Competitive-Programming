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
        int grid[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }
        vector<int> flip;
        for (int i = n - 1; i >= 1; --i) {
            bool order = true;
            for (int j = 0; j <= i; ++j) {
                if (grid[i][j] != i * n + j + 1) {
                    order = false;
                    break;
                }
            }
            if (!order) {
                flip.push_back(1);
                continue;
            }
            for (int j = 0; j < i; ++j) {
                if (grid[j][i] != j * n + i + 1) {
                    order = false;
                    break;
                }
            }
            if (!order) {
                flip.push_back(1);
            } else {
                flip.push_back(0);
            }
        }
        int pre = flip[0], sol = pre;
        for (int i = 1; i < flip.size(); ++i) {
            if (flip[i] != pre) {
                pre = flip[i];
                ++sol;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
