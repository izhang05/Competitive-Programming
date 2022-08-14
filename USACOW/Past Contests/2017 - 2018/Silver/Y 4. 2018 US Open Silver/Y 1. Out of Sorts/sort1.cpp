#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> nums(n); // pair<value, index>
    for (int i = 0; i < n; ++i) {
        nums[i].second = i;
        cin >> nums[i].first;
    }
    sort(nums.begin(), nums.end());

    int sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, nums[i].second - i); // find max of original_ind - new_ind
    }
    cout << sol + 1 << "\n"; // +1 because the pseudocode runs for an extra iteration at the end
    return 0;
}
