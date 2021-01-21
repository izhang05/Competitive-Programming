#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        set<int> row, col;
        int a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a;
                if (a) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        int rows = n - row.size(), cols = m - col.size();
        if (min(rows, cols) % 2 == 0) {
            cout << "Vivek" << "\n";
        } else {
            cout << "Ashish" << "\n";
        }
    }
    return 0;
}
