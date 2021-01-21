#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; ++i) {
        if (nums[i - 1] != i) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << n << "\n";
}
