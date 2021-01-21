#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int> > grid(n, vector<int>(n, 0));
        vector<int> row(n, 0);
        vector<int> col(n, 0);
        multiset<int> row_set;
        multiset<int> col_set;
        for (int i = 0; i < n; ++i) {
            row_set.insert(0);
            col_set.insert(0);
        }
        int cur_sum = 0;
        int x = 0, y = 0, to_add = n - 1, orig_x = 0, orig_y = 0;
        while (cur_sum < k) {
            cout << x << " " << y << "\n";
            grid[x][y] = 1;
            row_set.erase(row[x]);
            col_set.erase(col[y]);
            ++row[x];
            ++col[y];
            row_set.insert(row[x]);
            col_set.insert(col[y]);
            ++cur_sum;
            if (cur_sum >= k) {
                cout << cur_sum << "\n";
                break;
            }
            if (to_add > 0) {

                grid[x + to_add][y + to_add] = 1;
                row_set.erase(row[x + to_add]);
                col_set.erase(col[y + to_add]);
                ++row[x + to_add];
                ++col[y + to_add];
                row_set.insert(row[x + to_add]);
                col_set.insert(col[y + to_add]);
                ++cur_sum;
                to_add -= 2;
                ++x;
                ++y;
            }
            if (to_add <= 0) {
                y = orig_x;
                x = orig_y;
                if (orig_x <= orig_y) {
                    ++y;
                }
                to_add = min(n - x, n - y) - 1;
                orig_x = x;
                orig_y = y;
            }
        }
        for (vector<int> i : grid) {
            for (int j : i) {
                cout << j << "";
            }
            cout << "\n";
        }
    }
    return 0;
}
