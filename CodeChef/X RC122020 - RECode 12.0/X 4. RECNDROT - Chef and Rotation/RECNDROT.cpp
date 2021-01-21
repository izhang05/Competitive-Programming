#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


int main() {
    freopen("1.in", "r", stdin);
    freopen("solution.out", "w", stdout);
    int t, n, max_length;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> nums = {1};
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            if (((find(nums.begin(), nums.end(), num)) == nums.end())) {
                nums.push_back(num + 1);
            } else {
                ++nums[find(nums.begin(), nums.end(), num) - nums.begin()];
            }
        }
        cout << nums.size() << "\n";
    }
    return 0;
}