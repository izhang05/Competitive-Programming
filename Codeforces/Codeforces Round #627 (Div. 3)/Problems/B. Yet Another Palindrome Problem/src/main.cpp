#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, previous_num, current_num;
    cin >> t;
    bool possible;
    while (t--) {
        unordered_map<int, int> nums;
        possible = false;
        cin >> n;
        cin >> previous_num;
        nums[previous_num] = 1;
        for (int i = 0; i < n - 1; ++i) {
            cin >> current_num;
            if (nums.count(current_num)) {
                ++nums[current_num];
            } else {
                nums[current_num] = 1;
            }
            if (nums[current_num] > 2 || (nums[current_num] == 2 && previous_num != current_num)) {
                possible = true;
            }
            previous_num = current_num;
        }
        if (possible) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
