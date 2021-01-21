#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//    freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string swaps;
    cin >> swaps;
    swaps += '0';
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        if (swaps[i] == '0') {
            nums.push_back(a[i]);
            if (nums.size() == 1) {
                if (nums[0] != i + 1) {
                    cout << "NO" << "\n";
                    return 0;
                }
            } else {
                sort(nums.begin(), nums.end());
                if ((nums[nums.size() - 1] - nums[0] != nums.size() - 1) || (nums[nums.size() - 1] != i + 1)) {
                    cout << "NO" << "\n";
                    return 0;
                }

            }
            nums.clear();
        } else {
            nums.push_back(a[i]);
        }
    }
    cout << "YES" << "\n";
    return 0;
}
