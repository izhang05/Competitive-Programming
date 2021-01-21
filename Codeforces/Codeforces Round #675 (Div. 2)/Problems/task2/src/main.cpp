#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long sol = 0;
        cin >> n >> m;
        int grid[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
        vector<long long> nums;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                nums.clear();
                nums.push_back(grid[i][j]);
                nums.push_back(grid[n - i - 1][j]);
                nums.push_back(grid[i][m - j - 1]);
                nums.push_back(grid[n - i - 1][m - j - 1]);
                sort(nums.begin(), nums.end());
                for (int k = 0; k < 4; ++k) {
                    sol += abs(nums[k] - nums[1]);
                }
            }
        }
        if (n % 2 == 1) {
            for (int i = 0; i < m / 2; ++i) {
                sol += abs(grid[n / 2][i] - grid[n / 2][m - i - 1]);
            }
        }
        if (m % 2 == 1) {
            for (int i = 0; i < n / 2; ++i) {
                sol += abs(grid[i][m / 2] - grid[n - i - 1][m / 2]);
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
